/**
 * takeown2_win32.c - Windows ownership utility with UNC and long path support
 * Compile: x86_64-w64-mingw32-gcc -o takeown2.exe takeown2_win32.c -ladvapi32 -lole32 -luser32 -static -municode -Wl,--stack,16777216
 */

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#define _UNICODE

#include <windows.h>
#include <aclapi.h>
#include <sddl.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <shellapi.h>

// For extended path prefix
#define EXTENDED_PATH_PREFIX L"\\\\?\\"
#define UNC_EXTENDED_PATH_PREFIX L"\\\\?\\UNC\\"
#define MAX_LONG_PATH 32767

typedef struct {
    BOOL recursive;
    BOOL verbose;
    BOOL force;
    BOOL skipErrors;
    BOOL help;
    BOOL quiet;
    LPWSTR username;
    LPWSTR path;
} TAKEOWN_OPTIONS;

VOID PrintUsage(LPCWSTR programName) {
    wprintf(L"TAKEOWN2 - Take ownership of files and directories\n");
    wprintf(L"Version 2.0 (compatible with Microsoft takeown.exe)\n\n");
    wprintf(L"Usage: %ls [/S system [/U username [/P [password]]]] /F filename [/A] [/R [/D prompt]]\n\n", programName);
    wprintf(L"Description:\n");
    wprintf(L"  Enables an administrator to recover access to a file that previously was denied\n");
    wprintf(L"  by granting ownership to the administrator account.\n\n");
    wprintf(L"Parameter List:\n");
    wprintf(L"  /S system           Specifies the remote system to connect to.\n");
    wprintf(L"  /U username         Specifies the user context under which\n");
    wprintf(L"                      the command should execute.\n");
    wprintf(L"  /P password         Specifies the password for the given\n");
    wprintf(L"                      user context.\n");
    wprintf(L"  /F filename         Specifies the filename or directory name\n");
    wprintf(L"                      pattern. Can include wildcard *.\n");
    wprintf(L"  /A                  Gives ownership to the Administrators group.\n");
    wprintf(L"  /R                  Recursive: operates on files in the specified\n");
    wprintf(L"                      directory and all subdirectories.\n");
    wprintf(L"  /D prompt           Default answer used when the current user\n");
    wprintf(L"                      doesn't have the \"list folder\" permission on\n");
    wprintf(L"                      a directory (Y - take ownership / N - skip).\n");
    wprintf(L"  /SKIPERRORS         Continue executing on file errors.\n");
    wprintf(L"  /?                  Displays this help message.\n\n");
    wprintf(L"Examples:\n");
    wprintf(L"  %ls /F lostfile.txt\n", programName);
    wprintf(L"  %ls /F \\\\server\\share\\file.txt /A\n", programName);
    wprintf(L"  %ls /F directory /R /D Y\n", programName);
    wprintf(L"  %ls /F C:\\Windows\\*.dll /R\n", programName);
    wprintf(L"  %ls /F \"C:\\path with spaces\\file.txt\"\n", programName);
}

BOOL EnablePrivilege(LPCWSTR privilegeName) {
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;
    
    // Open process token
    if (!OpenProcessToken(GetCurrentProcess(), 
                         TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, 
                         &hToken)) {
        return FALSE;
    }
    
    // Lookup privilege value
    if (!LookupPrivilegeValue(NULL, privilegeName, &tkp.Privileges[0].Luid)) {
        CloseHandle(hToken);
        return FALSE;
    }
    
    // Enable the privilege
    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
    
    BOOL result = AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, NULL, NULL);
    
    CloseHandle(hToken);
    return result && (GetLastError() == ERROR_SUCCESS);
}

LPWSTR ConvertToLongPath(LPCWSTR path) {
    static WCHAR longPath[MAX_LONG_PATH];
    
    // Check if already in long path format
    if (wcsncmp(path, EXTENDED_PATH_PREFIX, 4) == 0 ||
        wcsncmp(path, UNC_EXTENDED_PATH_PREFIX, 8) == 0) {
        wcsncpy_s(longPath, MAX_LONG_PATH, path, _TRUNCATE);
        longPath[MAX_LONG_PATH - 1] = L'\0';
        return longPath;
    }
    
    // Check if it's a UNC path
    if (wcsncmp(path, L"\\\\", 2) == 0 && path[2] != L'?') {
        // Convert UNC to extended UNC format
        _snwprintf_s(longPath, MAX_LONG_PATH, _TRUNCATE, L"%ls%ls", 
                     UNC_EXTENDED_PATH_PREFIX, path + 2);
    } else {
        // Convert regular path to extended format
        _snwprintf_s(longPath, MAX_LONG_PATH, _TRUNCATE, L"%ls%ls", 
                     EXTENDED_PATH_PREFIX, path);
    }
    
    longPath[MAX_LONG_PATH - 1] = L'\0';
    return longPath;
}

BOOL SetObjectOwner(LPCWSTR path, PSID pSid, BOOL isDirectory, TAKEOWN_OPTIONS* opts) {
    DWORD dwRes;
    PSECURITY_DESCRIPTOR pSD = NULL;
    PACL pDacl = NULL;
    PACL pSacl = NULL;
    PSECURITY_DESCRIPTOR pNewSD = NULL;
    BOOL success = FALSE;
    HANDLE hFile = INVALID_HANDLE_VALUE;
    DWORD access = 0;
    
    // Try to open the file/directory with appropriate access
    if (opts->force) {
        access = ACCESS_SYSTEM_SECURITY | WRITE_OWNER | READ_CONTROL | DELETE;
    } else {
        access = ACCESS_SYSTEM_SECURITY | WRITE_OWNER | READ_CONTROL;
    }
    
    DWORD shareMode = FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE;
    DWORD creationDisposition = OPEN_EXISTING;
    DWORD flags = FILE_FLAG_BACKUP_SEMANTICS;
    
    hFile = CreateFileW(path, access, shareMode, NULL,
                       creationDisposition, flags, NULL);
    
    if (hFile == INVALID_HANDLE_VALUE) {
        DWORD err = GetLastError();
        if (!opts->quiet) {
            wprintf(L"\nError opening %ls: 0x%08lX\n", path, err);
        }
        return FALSE;
    }
    
    // Get current security descriptor
    dwRes = GetSecurityInfo(hFile, 
                           SE_FILE_OBJECT,
                           OWNER_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION,
                           NULL, NULL, &pDacl, NULL, &pSD);
    
    if (dwRes == ERROR_SUCCESS) {
        // Create new security descriptor with modified owner
        pNewSD = LocalAlloc(LPTR, SECURITY_DESCRIPTOR_MIN_LENGTH);
        if (pNewSD) {
            if (InitializeSecurityDescriptor(pNewSD, SECURITY_DESCRIPTOR_REVISION)) {
                if (SetSecurityDescriptorOwner(pNewSD, pSid, FALSE)) {
                    // Apply new security descriptor
                    dwRes = SetSecurityInfo(hFile, 
                                          SE_FILE_OBJECT,
                                          OWNER_SECURITY_INFORMATION,
                                          pSid, NULL, NULL, NULL);
                    
                    if (dwRes == ERROR_SUCCESS) {
                        success = TRUE;
                        if (opts->verbose) {
                            wprintf(L"\nSuccessfully set owner on: %ls\n", path);
                        }
                    } else {
                        if (opts->verbose) {
                            wprintf(L"\nFailed to set security info on %ls: 0x%08lX\n", path, dwRes);
                        }
                    }
                }
            }
            LocalFree(pNewSD);
        }
    } else {
        if (opts->verbose) {
            wprintf(L"\nFailed to get security info for %ls: 0x%08lX\n", path, dwRes);
        }
    }
    
    if (pSD) {
        LocalFree(pSD);
    }
    
    CloseHandle(hFile);
    return success;
}

BOOL ProcessPath(LPCWSTR path, PSID pSid, TAKEOWN_OPTIONS* opts) {
    WIN32_FIND_DATAW findData;
    HANDLE hFind;
    WCHAR searchPath[MAX_LONG_PATH];
    WCHAR fullPath[MAX_LONG_PATH];
    BOOL isDirectory = FALSE;
    DWORD attrs;
    
    // Check if path exists
    attrs = GetFileAttributesW(path);
    if (attrs == INVALID_FILE_ATTRIBUTES) {
        if (!opts->quiet) {
            wprintf(L"\nERROR: The system cannot find the file specified: %ls\n", path);
        }
        return FALSE;
    }
    
    isDirectory = (attrs & FILE_ATTRIBUTE_DIRECTORY) != 0;
    
    // Take ownership of the current path
    if (!SetObjectOwner(path, pSid, isDirectory, opts)) {
        if (!opts->skipErrors && !opts->quiet) {
            wprintf(L"\nERROR: Failed to take ownership of %ls\n", path);
        }
        if (!opts->skipErrors) {
            return FALSE;
        }
    } else if (!opts->quiet) {
        // wprintf(L"\nSuccess: %ls\n", path);
        wprintf(L".");
    }
    
    // Process recursively if directory and recursive flag is set
    if (isDirectory && opts->recursive) {
        // Build search pattern
        _snwprintf_s(searchPath, MAX_LONG_PATH, _TRUNCATE, L"%ls\\*", path);
        searchPath[MAX_LONG_PATH - 1] = L'\0';
        
        hFind = FindFirstFileW(searchPath, &findData);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                // Skip . and ..
                if (wcscmp(findData.cFileName, L".") == 0 ||
                    wcscmp(findData.cFileName, L"..") == 0) {
                    continue;
                }
                
                // Build full path
                _snwprintf_s(fullPath, MAX_LONG_PATH, _TRUNCATE, L"%ls\\%ls", 
                           path, findData.cFileName);
                fullPath[MAX_LONG_PATH - 1] = L'\0';
                
                // Process the file/directory
                ProcessPath(fullPath, pSid, opts);
                
            } while (FindNextFileW(hFind, &findData));
            
            FindClose(hFind);
        }
    }
    
    return TRUE;
}

BOOL ParseCommandLine(int argc, LPWSTR argv[], TAKEOWN_OPTIONS* opts) {
    int i;
    
    // Initialize options
    ZeroMemory(opts, sizeof(TAKEOWN_OPTIONS));
    
    for (i = 1; i < argc; i++) {
        if (argv[i][0] == L'/' || argv[i][0] == L'-') {
            if (_wcsicmp(argv[i] + 1, L"r") == 0 ||
                _wcsicmp(argv[i] + 1, L"R") == 0) {
                opts->recursive = TRUE;
            }
            else if (_wcsicmp(argv[i] + 1, L"v") == 0 ||
                _wcsicmp(argv[i] + 1, L"V") == 0) {
                opts->verbose = TRUE;
            }
            else if (_wcsicmp(argv[i] + 1, L"q") == 0 ||
                _wcsicmp(argv[i] + 1, L"Q") == 0) {
                opts->quiet = TRUE;
            }
            else if (_wcsicmp(argv[i] + 1, L"f") == 0 ||
                    _wcsicmp(argv[i] + 1, L"F") == 0) {
                i++; // Skip to next argument which should be the filename
                if (i < argc) {
                    opts->path = argv[i];
                } else {
                    wprintf(L"\nERROR: Invalid syntax. Filename not specified.\n");
                    return FALSE;
                }
            }
            else if (_wcsicmp(argv[i] + 1, L"a") == 0 ||
                    _wcsicmp(argv[i] + 1, L"A") == 0) {
                // For compatibility - we'll use Administrators group SID
                opts->username = L"BUILTIN\\Administrators";
            }
            else if (_wcsicmp(argv[i] + 1, L"skiperrors") == 0 ||
                    _wcsicmp(argv[i] + 1, L"SKIPERRORS") == 0) {
                opts->skipErrors = TRUE;
            }
            else if (_wcsicmp(argv[i] + 1, L"s") == 0 ||
                    _wcsicmp(argv[i] + 1, L"S") == 0) {
                i++; // Skip system parameter (not implemented)
                wprintf(L"\nNote: Remote system connection not implemented in this version.\n");
            }
            else if (_wcsicmp(argv[i] + 1, L"u") == 0 ||
                    _wcsicmp(argv[i] + 1, L"U") == 0) {
                i++; // Skip to username
                if (i < argc) {
                    opts->username = argv[i];
                }
            }
            else if (_wcsicmp(argv[i] + 1, L"p") == 0 ||
                    _wcsicmp(argv[i] + 1, L"P") == 0) {
                i++; // Skip password (not used in this implementation)
            }
            else if (_wcsicmp(argv[i] + 1, L"d") == 0 ||
                    _wcsicmp(argv[i] + 1, L"D") == 0) {
                i++; // Skip default prompt answer
                // Not implemented in this version
            }
            else if (_wcsicmp(argv[i] + 1, L"?") == 0) {
                opts->help = TRUE;
                return TRUE; // Early return for help
            }
            else {
                wprintf(L"\nERROR: Invalid parameter - %ls\n", argv[i]);
                return FALSE;
            }
        }
        else {
            // If no /F specified but we have a path argument, use it
            if (opts->path == NULL) {
                opts->path = argv[i];
            }
            else {
                wprintf(L"\nERROR: Invalid syntax.\n");
                return FALSE;
            }
        }
    }
    
    // Microsoft takeown requires /F parameter
    if (!opts->help && opts->path == NULL) {
        wprintf(L"ERROR: Invalid syntax.\n");
        wprintf(L"Type \"TAKEOWN2 /?\" for usage.\n");
        return FALSE;
    }
    
    return TRUE;
}

int wmain(int argc, WCHAR* argv[]) {
    TAKEOWN_OPTIONS opts;
    PSID pSid = NULL;
    DWORD sidSize = 0;
    DWORD domainSize = 0;
    SID_NAME_USE sidType;
    LPWSTR domainName = NULL;
    BOOL success = FALSE;
    LPWSTR longPath = NULL;
    
    // Set locale for proper Unicode output
    _wsetlocale(LC_ALL, L"");
    
    // Show banner for takeown2
    wprintf(L"TAKEOWN2 v2.0 - Enhanced Take Ownership Utility\n\n");
    
    // Parse command line
    if (!ParseCommandLine(argc, argv, &opts)) {
        return 1;
    }
    
    if (opts.help) {
        PrintUsage(L"takeown2");
        return 0;
    }
    
    if (opts.path == NULL) {
        wprintf(L"\nERROR: File name parameter (/F) is required.\n");
        PrintUsage(L"takeown2");
        return 1;
    }
    
    // Enable required privileges
    if (!EnablePrivilege(SE_RESTORE_NAME)) {
        if (opts.verbose) {
            wprintf(L"\nWarning: Could not enable SE_RESTORE_NAME privilege\n");
        }
    }
    if (!EnablePrivilege(SE_TAKE_OWNERSHIP_NAME)) {
        if (opts.verbose) {
            wprintf(L"\nWarning: Could not enable SE_TAKE_OWNERSHIP_NAME privilege\n");
        }
    }
    if (!EnablePrivilege(SE_BACKUP_NAME)) {
        if (opts.verbose) {
            wprintf(L"\nWarning: Could not enable SE_BACKUP_NAME privilege\n");
        }
    }
    
    // Convert to long path format
    longPath = ConvertToLongPath(opts.path);
    
    // Get SID for the specified user or current user
    if (opts.username) {
        // First call to get buffer sizes
        LookupAccountNameW(NULL, opts.username, NULL, &sidSize, NULL, &domainSize, &sidType);
        
        pSid = LocalAlloc(LPTR, sidSize);
        domainName = LocalAlloc(LPTR, domainSize * sizeof(WCHAR));
        
        if (!pSid || !domainName) {
            wprintf(L"\nERROR: Memory allocation failed\n");
            goto cleanup;
        }
        
        if (!LookupAccountNameW(NULL, opts.username, pSid, &sidSize, 
                               domainName, &domainSize, &sidType)) {
            wprintf(L"\nERROR: User '%ls' not found\n", opts.username);
            goto cleanup;
        }
        
        if (opts.verbose) {
            wprintf(L"\nUsing user: %ls\\%ls\n", domainName, opts.username);
        }
    }
    else {
        // Default to current user if no user specified
        HANDLE hToken;
        DWORD tokenSize;
        PTOKEN_USER pTokenUser = NULL;
        
        if (OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) {
            GetTokenInformation(hToken, TokenUser, NULL, 0, &tokenSize);
            pTokenUser = LocalAlloc(LPTR, tokenSize);
            
            if (pTokenUser && 
                GetTokenInformation(hToken, TokenUser, pTokenUser, tokenSize, &tokenSize)) {
                sidSize = GetLengthSid(pTokenUser->User.Sid);
                pSid = LocalAlloc(LPTR, sidSize);
                if (pSid) {
                    CopySid(sidSize, pSid, pTokenUser->User.Sid);
                }
            }
            
            if (pTokenUser) LocalFree(pTokenUser);
            CloseHandle(hToken);
        }
        
        if (!pSid) {
            wprintf(L"\nERROR: Failed to get current user SID\n");
            goto cleanup;
        }
        
        if (opts.verbose) {
            wprintf(L"\nUsing current user\n");
        }
    }
    
    if (opts.verbose) {
        LPWSTR sidString = NULL;
        if (ConvertSidToStringSidW(pSid, &sidString)) {
            wprintf(L"\nUsing SID: %ls\n", sidString);
            LocalFree(sidString);
        }
    }
    
    // Process the path
    wprintf(L"\nTaking ownership of: %ls\n", opts.path);
    if (opts.recursive) {
        wprintf(L"\nProcessing recursively...\n");
    }
    
    success = ProcessPath(longPath, pSid, &opts);
    
    if (success && !opts.quiet) {
        wprintf(L"\n\nSUCCESS: The ownership of the file(s) has been taken.\n");
    }
    
cleanup:
    if (pSid) LocalFree(pSid);
    if (domainName) LocalFree(domainName);
    
    return success ? 0 : 1;
}