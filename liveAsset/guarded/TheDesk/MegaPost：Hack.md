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

#### runhidden alternative in pure python (Windows)

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

2025-11-08 13:20:15 #TIL 总之目前GTK WebKit在NVIDIA显卡上是无法开箱即用的，这甚至影响到了Debian MATE默认的yelp帮助程序。

于是又有了如下咒语：

```
WEBKIT_DISABLE_COMPOSITING_MODE=1
```

或者

```
WEBKIT_DISABLE_DMABUF_RENDERER=1
```

2025-11-08 19:36:25 #TIL 纯Firefox目前在KDE上与系统特性的集成一团糟，例如采用不了KDE的代理设置（[bugzilla.mozilla.org/~](https://bugzilla.mozilla.org/show_bug.cgi?id=834039)；[github.com/openSUSE/~.patch](https://github.com/openSUSE/firefox-maintenance/blob/4092babd795b7a697ccceb8948ea5f51eb8f2f9f/mozilla-nongnome-proxies.patch)）；文件对话框也没有采用KDE风格的，而是采用了臭名昭著的GTK File Chooser（[google.com/search?~](https://www.google.com/search?q=gtk+file+chooser+sucks)）。为此Arch AUR和OpenSUSE都有自己的Firefox发行版/补丁专门弥补这些问题（https://aur.archlinux.org/packages/firefox-kde-opensuse ）。

当然以上两个问题都可以用环境变量workaround过去：`all_proxy=http://xx:xx GTK_USE_PORTAL=1 firefox-esr`（需要安装xdg-desktop-portal-kde；按理说xdg portal也支持获取系统代理信息，但可能Firefox没对接吧，所以`all_proxy`环境变量还是需要），但这就是易用性和<span style="text-decoration: underline dotted;" title="开箱即用体验">OOBE</span>的问题了。

2025-11-08 19:51:12 然后Debian KDE现在默认采用wayland后仍附带安装了im-config，会导致ibus默认是以（Xwayland？）形式启动的，进系统就会报一堆天书一样的通知告诉你ibus不能这么启动。解决办法是卸载（或禁用在Wayland启动？）im-config，然后真正以Wayland的方式启动ibus：在系统设置里找到Virtual Keyboard，置为IBus Wayland。

2025-11-09 02:52:54 sddm甚至会在AMD CPU的随机数生成器不工作时（WARNING: CPU random generator seem to be failing, disabling hardware random number generation）导致登入桌面登出（注销，log out）后第二次显示greeter失败（可能是因为随机数变成了固定数，前后两次socket名相同？）反正总之更新主板BIOS（这又是另一个痛苦的故事）后不再报随机数错误，也修复了sddm的问题。

---

但是紧接着就出现了另一个问题：KDE的log out有概率不起作用了。有时是不显示弹出菜单，有的是显示弹出菜单点击了Log out确认按钮后没有注销，有的甚至是注销再次sddm登录时卡几秒黑屏后重新回到greeter。有可能和session保存功能有关，但是关了之后也有概率复现。用loginctl unlock-session有时能解除sddm无法登录的状态。

possibly related: https://bugzilla.redhat.com/show_bug.cgi?id=2404966
