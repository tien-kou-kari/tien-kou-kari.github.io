---
publishTime: '2025-11-08 01:03:46'
childrenSortOrder: condTimeDesc
isDerivableIntoChildren: true
title: 'MegaPost: Hack，或计算世界中的诸多魔法/巫术/術/器'
---


2026-01-02 22:15:10

### Windows takeown命令遇到长路径时怎么办 - WriteUp

- Windows NTFS文件系统下遇到目录文件权限乱套（例如，从另一台系统搬过来的硬盘）时一般考虑takeown+icacls一把梭
  - `takeown /f <file> /r /d y`（多次？）用来改文件的所有者
    - 虽然icacls有`/setowner`选项也能改所有者，但致命缺陷在于它完全遵守ACL，如果ACL不允许当前用户有“Take Ownership”这一项权限，则icacls即使以管理员权限运行也不会尝试任何其他方式提权，而是直接拒绝执行操作。而takeown能顺利提权（也许是SeRestorePrivilege？这个特权允许忽视NTFS ACL对文件进行任意操作）。
  - `icacls <file> /reset /T /C /Q /L`在当前用户已成为文件所有者时（此时无论实际ACL是否赋予了“修改权限”的权限都能执行修改权限的操作）可以对其重设权限为sensible default。
- 但是takeown同样也有一个致命缺陷：它无法绕过260字符的总路径长度限制。当遍历目录时一旦遇到一个文件的总路径长度超过时，它直接报错“The system cannot find the path specified”。icacls虽然也有这个问题，但有一个workaround：传UNC路径`\\?\C:\dir\...\file`即可；但takeown不接受UNC路径。
  - 有一个第三方SetACL.exe似乎能解决这个问题，但它是Freeware，源码不可用。
- 于是摸索了一下午最后认为最合理的解决方案是让DeepSeek写一个MinGW-w64 C程序作为takeown的支持长路径的替代，我将其命名为takeown2，源码见附件。
  - 最后的整体解决方案为：
```
(在管理员命令提示符下，或sudo -i System -s下)
.\takeown2.exe /r /U myuser /f C:\mydir\mydir2
(之后切回到当前用户的普通用户的命令提示符下，或当前用户的管理员命令提示符下，但不能切换为`sudo -i System`/`sudo -s`，那样将作为SYSTEM用户执行改命令，反而会因为不是owner被拒绝权限)
icacls \\?\C:\mydir\mydir2 /reset /T /Q /C /L
```

<a href="/miscMedia/2026-01-02/takeown2_win32.c" class="md-attach md-attach-file-link" target="_blank">takeown2_win32.c</a>

<a href="/miscMedia/2026-01-02/llm-chat-prompt-for-takeown2_win32.c.txt" class="md-attach md-attach-file-link" target="_blank">llm-chat-prompt-for-takeown2_win32.c.txt</a>


2025-11-08 01:13:37

#### Ventoy安装在本地硬盘上与Windows共存的办法

- 必须缩小+挪动Windows C盘，使得其前面有一块较大区域。
- 将原EFI扩大并挪动，使得EFI分区从1MB开始（2048扇区），占用较大空间，与Microsoft保留分区间隔40MB以上。
- 从Windows安装Ventoy，必须选择“无损安装”，Ventoy应能无需再操作分区，自行将VTOYEFI分区安装在上述40MB空闲空间内。
- 此时EFI分区将作为Ventoy承载ISO和配置的分区，即使其空间不足以放ISO，也可以用Vlnk的方式引用C盘或后面分区的ISO、Vtoy等文件。
- `sudo hexdump -s 0x1b8 -n 4 -C /dev/sdx`（cygwin下也可，用管理员权限运行） 确定当前磁盘的signature（ventoy唯一识别有用到）
- 若是全0， `sudo dd if=/dev/urandom of=/dev/sdX bs=1 count=4 seek=440 conv=fsync` 设置当前磁盘的signature（ventoy唯一识别有用到）
- `printf '\x78\x56\x34\x12' | sudo dd of=/dev/sdX bs=1 count=4 seek=440 conv=fsync` 可手动指定。

2025-11-08 01:15:48

#### BugMeNot - share login, share user, share password, share account

https://bugmenot.com/

至少对Oracle官网和Broadcom（VMWare）官网这种不不登录不给下载的毒瘤还有用

2025-11-08 01:22:37

#### Quickly Share Cookies from One Browser to Another

`document.cookie`

` '...'.split(';').forEach(c => document.cookie=c);`

2025-11-08 01:26:11

#### runhidden alternative in pure python (Windows)

```
pythonw.exe -I -P -c "import sys, subprocess as sp, ctypes as ct; MIN = 6; HID = 0; i = sp.STARTUPINFO(); i.dwFlags |= sp.STARTF_USESHOWWINDOW; i.wShowWindow |= HID; rt = sp.run(sys.argv[1:], startupinfo=i, creationflags=sp.CREATE_NEW_CONSOLE).returncode; app_name = 'XXXXXX'; ct.windll.user32.MessageBoxW(None, app_name + ' exited with code ' + str(rt) + ' . Is that expected?', 'Warning: ' + app_name + ' exited', 0x30); sys.exit(rt);" MyCommandLineTool.exe arg1 arg2
```

2025-11-08 01:30:12

#### Background Process 无 nohup 和 setsid 情况下起一个后台

```
(( command 0<&- >/dev/null 2>&1 &) &) &
```

（有StackExchange回答引证，需要补充引证）

2025-11-08 01:31:04

#### Chromium ArgumentList

```
--profile-directory= --user-data-dir= --window-position= --window-size=  --no-default-browser-check --no-first-run --ash-no-nudges --password-store=basic
--disable-gpu --no-sandbox --disable-dev-shm-usage --no-default-browser-check --no-first-run --ash-no-nudges --password-store=basic
```

酌情挑选使用，只要知道自己在做什么。

2025-11-08 01:38:34

#### 利用GNU coreutils env -S的特殊性质，把一个bash脚本变成一个可直接执行的systemctl --user shebang wrapper

Shebang最长允许256字节，且只允许拆为两个命令行arg，即使有多个空格分隔，第二个空格开始其分割作用也不生效，统一归入第二个arg。由此GNU env提供了-S选项，允许将它的一个arg再次以空格劈为多个arg（并且还实现了很贴心的引号、变量引用等一些基本类Shell句法！）做真正的执行。借此可让Shebang机制对当前文件做复杂的逻辑处理。

```
#!/usr/bin/env -S /bin/bash -c 'F="$(cat "$1")"; LAUNCHER="${F%%$'\''---\n'\''*}; exit;"; if [ "$LAUNCHER" = "$F" ]; then echo shebang/===/launcher/---/conf/---/script, /=LF >&2; exit 4; fi; $0 -c "${LAUNCHER#*$'\''===\n'\''}" $0 "$@"' /bin/bash

echo Should be launched by launcher only >&2
exit 4

===

ORIG_FILE_PATH="$1"
F="$(cat "$ORIG_FILE_PATH")"
CUT_1="${F#*$'---\n'}"
CONF="${CUT_1%%$'---\n'*}"
MAIN_SCRIPT="${CUT_1#*$'---\n'}"
shift

eval "$CONF"

if [ -z "$UNIT_NAME" ]; then
	UNIT_NAME="${ORIG_FILE_PATH##*/}"
	UNIT_NAME="${UNIT_NAME%.sh}"
	if [ -z "${UNIT_NAME}" ]; then
		echo No unit name >&2
		exit
	fi
fi
UNIT_NAME="${UNIT_NAME%.service}.service"

echorun ()
{
    local a
    local i
	echo -n '+' 1>&2
    for a in "$@"
    do
		if [ "${a%%$'\n'*}" = "$a" ]; then
        	echo -n " '${a}'" 1>&2
		else
        	echo -n " '...'" 1>&2
		fi
    done
	echo 1>&2
	"$@"
}

SHOULD_RUN=1
[ $#"$1" = 1stop ] && SHOULD_RUN=0
SHOULD_LOG=0
LOG_ARGS=' -n 200 --follow'
[ $#"$1" = 1log -o $#"$1" = 1l ] && SHOULD_LOG=1 && SHOULD_RUN=0
[ $#"$1" = 1logp -o $#"$1" = 1lp ] && LOG_ARGS=' -n 2999' && SHOULD_LOG=1 && SHOULD_RUN=0
SHOULD_STATUS=0
[ $#"$1" = 1status -o $#"$1" = 1s ] && SHOULD_STATUS=1 && SHOULD_RUN=0

if [ $SHOULD_STATUS = 1 ]; then
        echorun systemctl --user --no-pager status "$UNIT_NAME"
elif [ $SHOULD_LOG = 1 ]; then
        echorun journalctl --user --unit "$UNIT_NAME" --pager-end ${LOG_ARGS}
else
        echorun systemctl --user stop "$UNIT_NAME"
        if [ $SHOULD_RUN = 1 ]; then
                echorun systemd-run --user --unit "$UNIT_NAME" ${SYSTEMD_RUN_ARGS} --same-dir --collect -- /bin/bash -c "$MAIN_SCRIPT" /bin/bash "$@"
                sleep 1
                echorun journalctl --user --unit "$UNIT_NAME" --pager-end -n 50 --follow
        fi
fi

exit
---
# UNIT_NAME=my-unit-1
# SYSTEMD_RUN_ARGS='--property=RuntimeMaxSec=7200 --property=Restart=always '
# may need to set systemd user to be lingering to live through ssh logout
---

<bash script content goes here>


```

用法：

```
./xxx # 将当前bash脚本以systemd用户服务的形式启动或重启
./xxx l # 看日志
./xxx stop # 停止服务
```

#### mintty 开启一个带标签页管理的新窗口

首先在`~/.minttyrc`里写`NewTabs=1`（使得从其他地方启动mintty的窗口总是新开标签页组，也即不纳入当前标签页组管理）。

之后在已有窗口里写`( ( mintty <...mintty options> --newtabs --tabbar=4 <&- >/dev/null 2>&1 & ) & ) &`，即可新开带tab管理的窗口。

注意：*目前没有很干净的办法将**当前**窗口纳入标签页管理。*

