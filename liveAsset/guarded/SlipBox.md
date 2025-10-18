---
isDerivableIntoChildren: true
---



2025-09-15 01:43:43 #meta title=图书馆建成了

图书馆建成了。

2025-09-18 01:02:57 

AI用于完全琐碎/非创意领域的道德性？
- 也有可能是非道德的。妳在给AI公司提供数据。

2025-09-18 11:15:51 [[

Thunderbird 143 on Windows 启动后闪退，在prefs.js里`mail.accountmanager.accounts`把Gmail账号移除掉后恢复。

2025-09-18 11:31:18

或者把mail.server.server1.login_at_startup改成false就好了

2025-09-18 11:31:19 ~~ Thunderbird 143 on Windows 启动后闪退问题

2025-09-18 11:31:23

但是只要gmail一收件就crash，咲希了

2025-09-18 11:35:04
？好像好了

2025-09-18 11:35:09
只要保证启动时gmail绝对不能自动收件就行

2025-09-18 23:56:39 ]]

2025-09-19 21:37:55 艹，太傻逼了，Windows 10有些窗口（比如services.msc）在最大化后习惯性鼠标甩到最右上角的位置点击竟然不是对应本窗口的关闭按钮，而是穿透到下一层窗口，比如把下一层的Chrome关掉了

2025-09-21 01:02:10 #tk演进 内容更新时间，group重新思考primary逻辑，进g内单条asset时行为，gkeys

2025-09-22 00:43:05 #tk演进 尽量减少kv写入，每请求最多写1次，每刷新最多写1+n(后续有增量请求数)次

2025-09-26 00:41:17

https://wiki.c2.com/?ClassesAreContext

https://wiki.c2.com/?ContextObjectsAreEvil

2025-09-26 01:09:03

所以说到Context，将JavaScript的AsyncLocalStorage类似概念（其他语言是否也有？Structured Concurrency是不是关于这个的？）用在Context的传递上变成语言的内禀功能，默认（或以一个尽量方便的标记opt-in）函数都需要用到context对象，需要取其中的内容时有语法糖支持使其尽可能方便，是否可行？

2025-09-27 22:43:32

#tk演进 frontMatter内直接写时间的问题

#tk演进 内容submit页面

#tk演进 文件变成文件夹后hoard的bug

2025-10-01 01:08:12 tref=zxf-struggled 在此庆贺这个新民主主义国家走过第七十六个年头。



2025-10-03 01:25:46 Lovely red panda 4

<a href="/miscMedia/2025-10-03_01-25-46_0.jpg" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/2025-10-03_01-25-46_0.jpg" class="md-attach md-attach-img" alt="" title="" style="max-width: 20rem; max-height: 40rem;">
        </a>


2025-10-03 01:26:22 Lovely red panda 5

<a href="/miscMedia/2025-10-03_01-26-22_0.jpg" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/2025-10-03_01-26-22_0.jpg" class="md-attach md-attach-img" alt="" title="" style="max-width: 20rem; max-height: 40rem;">
        </a>


2025-10-03 01:36:02 啊啊啊




2025-10-03 01:37:51 #tk演进 什么都有了，sender也做了，应该没什么事了吧…




2025-10-03 12:22:31 哎唷我草瓜熟迪落拉也听きとずぼ




2025-10-03 12:22:55 品味这一块


2025-10-04 16:10:07 船长的资料室 - 将一般Windows操作系统迁移到VHDX中并切换为WindowsToGo启动
 http://www.tiger2doudou.com/doku.php/windows:os:migrate_ordinary_os_to_vhdx_window_to_go_on_usb_driver

关于将Windows系统做成外置USB硬盘盒（Windows To Go）启动，以及（按需）克隆保证不出冲突的指引可以看上文，加上以下几点我自己的经验：

- 1. USB 驱动 `HKLM\SYSTEM\ControlSet001\Control\Class\{36fc9e60-c465-11cf-8056-444553540000}` 不能有 UpperFilters 。

- 2. 除了上述检查之外，改 BootDriverFlags 是保证USB 21H2能够启动的唯一需要。（如果是移动到新主板启动，即 Hardware GUID 全新，则可能改为只启用 HAL 检测即可。）

<a href="/miscMedia/SlipBox_b1xv3rs3_0.html" class="md-attach md-attach-file-link" target="_blank">SlipBox_b1xv3rs3_0.html</a>

2025-10-04 16:32:58 接上条。

普通系统切换为WTG的方法 · GitHub - https://gist.github.com/muink/1f963c5229328c4f5da408076af13448

把两个注册表键值的作用讲得很清楚了，可以理解为 PortableOperatingSystem 的值是完全不需要的。

同时还需要注意：ControlSet\Control键下也有一个BootDriverFlags，修改这个值对我而言似乎没用。而且在我的系统上一开始就是0x1c了（允许USB启动的值），也不需要修改。

<a href="/miscMedia/SlipBox_xlj13ckn_0_普通系统切换为WTG的方法 · GitHub (2025_10_4 16：22：37).html" class="md-attach md-attach-file-link" target="_blank">SlipBox_xlj13ckn_0_普通系统切换为WTG的方法 · GitHub (2025_10_4 16：22：37).html</a>

2025-10-04 23:25:27 看起来Chromium on Android/ChromeOS对于“让用户选择一个本地目录，然后对里面的某个具体文件进行取writable然后写入”这个用例目前还是不通的，至少Chrome 140.0.7339.207现在是这样…

2025-10-05 00:39:29 接上条：乐，查了下Firefox根本不支持window.showDirectoryPicker API。还得靠同行衬托

2025-10-05 00:58:30 又试了一试，感觉是总路径名太长才会触发这个bug…

2025-10-05 01:00:31 达到一定长度（70左右）会触发这个bug

2025-10-05 12:41:26 

2025-10-05 14:13:43 https://lab.skk.moe/traffic-consumer

苏卡卡的大厂 CDN 流量拉取器，可以测速、消耗流量等

2025-10-07 01:06:36 #tk演进 是否需要考虑将所有链接默认target=_blank？

2025-10-07 21:49:49 #tk演进 CSS;tksender md渲染？临时缓存

2025-10-13 02:09:38 #tk演进 如果还有明天的话：

里站。

全文多关键词搜索。

2025-10-13 18:16:27 [/hive/Blabber/NamingThings](/hive/Blabber/NamingThings)

2025-10-13 20:53:32 Nostr and ATProto (2024) Nostr 和 ATProto (2024) - https://shreyanjain.net/2024/07/05/nostr-and-atproto.html

2025-10-14 01:04:53 Nostr and ATProto (2024) Nostr 和 ATProto (2024) - https://shreyanjain.net/2024/07/05/nostr-and-atproto.html

双语留档

<a href="/miscMedia/SlipBox_0_shreyan_ - Nostr and ATProto (2025_10_14 01：02：31).html" class="md-attach md-attach-file-link" target="_blank">SlipBox_0_shreyan_ - Nostr and ATProto (2025_10_14 01：02：31).html</a>

2025-10-15 01:43:03 America's future could hinge on whether AI slightly disappoints - https://www.noahpinion.blog/p/americas-future-could-hinge-on-whether

双语留档

有付费墙，文章不完整

美帝的大洪水怎么还不来，可恶的AI.jpg

<a href="/miscMedia/SlipBox_0_America&#039;s%20future%20could%20hinge%20on%20whether%20AI%20slightly%20disappoints%20(2025_10_15%2001%EF%BC%9A41%EF%BC%9A52).html" class="md-attach md-attach-file-link" target="_blank">SlipBox_0_America&#039;s future could hinge on whether AI slightly disappoints (2025_10_15 01：41：52).html</a>

2025-10-17 20:48:45 很有戏剧性的黑客/工程师阴谋剧情

A conspiracy to kill IE6 (2019) 暗杀 IE6 的阴谋 (2019) - https://blog.chriszacharias.com/a-conspiracy-to-kill-ie6

<a href="/miscMedia/SlipBox_rahkfuia_0_A%20Conspiracy%20To%20Kill%20IE6%20(10_17_2025%209%EF%BC%9A35%EF%BC%9A20%20PM).html" class="md-attach md-attach-file-link" target="_blank">SlipBox_rahkfuia_0_A Conspiracy To Kill IE6 (10_17_2025 9：35：20 PM).html</a>

2025-10-18 13:52:48 The pivot 枢纽 - https://www.antipope.org/charlie/blog-static/2025/10/the-pivot-1.html

双语备档

<a href="/miscMedia/SlipBox_rq5lb1wo_0_The%20pivot%20-%20Charlie&#039;s%20Diary%20(2025_10_18%2013%EF%BC%9A51%EF%BC%9A33).html" class="md-attach md-attach-file-link" target="_blank">SlipBox_rq5lb1wo_0_The pivot - Charlie&#039;s Diary (2025_10_18 13：51：33).html</a>


2025-10-18 19:08:07 > 4、***主张**：“言论自由权意味着政府不能因为你说的话而逮捕你；但它仍然让其他人有赶走你的自由。”*
>
> 不是的。下面这幅流行的xkcd漫画是**错误的**。第一修正案限制了政府可以做什么，但言论自由是比这更大的事。
>
> [图1]
>
> 这幅漫画经常被用来作为否定言论自由的论点，但它是错误的：它不仅混淆了第一修正案的法律和言论自由，甚至没有正确理解第一修正案。
>
> 言论自由的概念是一个更大、更古老、更广泛的概念，而不是它在第一修正案中的具体应用。**对言论自由重要性的信念是激发第一修正案的原因；是它赋予第一修正案以意义，也是它在法律上的支撑。**

来源： https://www.thefire.org/news/blogs/eternally-radical-idea/answers-12-bad-anti-free-speech-arguments-featuring-xkcd-cartoon

引译：IYouPort，但它没有给出原始来源链接： https://iyouport.substack.com/p/12-8d8

<a href="/miscMedia/SlipBox_854ieqlf_0_e960b8e8-c27f-4a35-9938-63ccd6598814_998x1022.webp" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/SlipBox_854ieqlf_0_e960b8e8-c27f-4a35-9938-63ccd6598814_998x1022.webp" class="md-attach md-attach-img" alt="https://xkcd.com/1357/ The famous xkcd comic about free speech. See transcript on https://www.explainxkcd.com/wiki/index.php/1357:_Free_Speech" title="https://xkcd.com/1357/ The famous xkcd comic about free speech. See transcript on https://www.explainxkcd.com/wiki/index.php/1357:_Free_Speech" style="max-width: 20rem; max-height: 40rem;">
        </a>
