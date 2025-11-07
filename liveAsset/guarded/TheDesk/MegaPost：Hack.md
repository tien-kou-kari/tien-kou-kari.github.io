---
publishTime: '2025-11-08 01:03:46'
childrenSortOrder: condTimeDesc
isDerivableIntoChildren: true
title: 'MegaPost: Hack，或计算世界中的诸多魔法/巫术/術/器/怪异/奇谭/訳/无奈与妥协'
---

2025-11-08 01:13:37

#### Ventoy安装在本地硬盘上与Windows共存的办法

- 必须缩小+挪动Windows C盘，使得其前面有一块较大区域。
- 将原EFI扩大并挪动，使得EFI分区从1MB开始（2048扇区），占用较大空间，与Microsoft保留分区间隔40MB以上。
- 从Windows安装Ventoy，必须选择“无损安装”，Ventoy应能无需再操作分区，自行将VTOYEFI分区安装在上述40MB空闲空间内。
- 此时EFI分区将作为Ventoy承载ISO和配置的分区，即使其空间不足以放ISO，也可以用Vlnk的方式引用C盘或后面分区的ISO、Vtoy等文件。

2025-11-08 01:15:48

#### BugMeNot - share login, share user, share password, share account

https://bugmenot.com/

至少对Oracle官网和Broadcom（VMWare）官网这种不不登录不给下载的毒瘤还有用

2025-11-08 01:22:37

#### Quickly Share Cookies from One Browser to Another

`document.cookie`

` '...'.split(';').forEach(c => document.cookie=c);`

2025-11-08 01:26:11

##### runhidden alternative in pure python (Windows)

```
pythonw.exe -I -P -c "import sys, subprocess as sp, ctypes as ct; MIN = 6; HID = 0; i = sp.STARTUPINFO(); i.dwFlags |= sp.STARTF_USESHOWWINDOW; i.wShowWindow |= HID; rt = sp.run(sys.argv[1:], startupinfo=i, creationflags=sp.CREATE_NEW_CONSOLE).returncode; app_name = 'XXXXXX'; ct.windll.user32.MessageBoxW(None, app_name + ' exited with code ' + str(rt) + ' . Is that expected?', 'Warning: ' + app_name + ' exited', 0x30); sys.exit(rt);" MyCommandLineTool.exe arg1 arg2
```

2025-11-08 01:26:14 #经典永流传

https://learn.microsoft.com/en-us/archive/blogs/twistylittlepassagesallalike/everyone-quotes-command-line-arguments-the-wrong-way

Everyone quotes command line arguments the wrong way

附：PowerShell/PoSh/pwsh 带引号的命令行解析转义逻辑耻辱柱（节选）

- https://github.com/PowerShell/PowerShell/issues/5576
- https://stackoverflow.com/questions/6714165/powershell-stripping-double-quotes-from-command-line-arguments
    - 然后Powershell V7的Quoting rules又与v5不同……又一个python3了属于是
- https://stackoverflow.com/questions/6714165/powershell-stripping-double-quotes-from-command-line-arguments/59681993#59681993
    - 一条在powershell v5上还起码报出哪里有句法错误的语句，在v7上跑起来直接静默崩溃，没有报错输出，只会将errorlevel设为1。。。

2025-11-08 01:30:12

##### Background Process 无 nohup 和 setsid 情况下起一个后台

```
(( command 0<&- >/dev/null 2>&1 &) &) &
```

（有StackExchange回答引证，需要补充引证）


