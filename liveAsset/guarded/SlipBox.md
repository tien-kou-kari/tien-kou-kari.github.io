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

2025-10-01 01:08:12 ref=zxf-struggled 在此庆贺这个新民主主义国家走过第七十六个年头。



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


2025-10-18 19:08:07 tidbit={"Note":"IYouPort在翻译时并没有给出原始来源链接，由此再次印证IYP的编辑过程持续地存在与其倡导价值观背道而驰的地方。原始来源链接为笔者所加。"} > 4、***主张**：“言论自由权意味着政府不能因为你说的话而逮捕你；但它仍然让其他人有赶走你的自由。”*
>
> 不是的。下面这幅流行的xkcd漫画是**错误的**。第一修正案限制了政府可以做什么，但言论自由是比这更大的事。
>
> [图1]
>
> 这幅漫画经常被用来作为否定言论自由的论点，但它是错误的：它不仅混淆了第一修正案的法律和言论自由，甚至没有正确理解第一修正案。
>
> 言论自由的概念是一个更大、更古老、更广泛的概念，而不是它在第一修正案中的具体应用。**对言论自由重要性的信念是激发第一修正案的原因；是它赋予第一修正案以意义，也是它在法律上的支撑。**
>
> [...]
>
> 虽然美国宪法在表面上只限制政府行为，但其应用有时需要政府保护你不被其他公民审查。例如，政府有责任保护你不被不喜欢你的想法的敌对暴徒攻击，或保护你的公开演讲不[被质问者](https://www.thefire.org/rejecting-the-hecklers-veto/)的否决权打断。

来源： https://www.thefire.org/news/blogs/eternally-radical-idea/answers-12-bad-anti-free-speech-arguments-featuring-xkcd-cartoon

引译：IYouPort： https://iyouport.substack.com/p/12-8d8

<a href="/miscMedia/SlipBox_854ieqlf_0_e960b8e8-c27f-4a35-9938-63ccd6598814_998x1022.webp" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/SlipBox_854ieqlf_0_e960b8e8-c27f-4a35-9938-63ccd6598814_998x1022.webp" class="md-attach md-attach-img" alt="https://xkcd.com/1357/ The famous xkcd comic about free speech. See transcript on https://www.explainxkcd.com/wiki/index.php/1357:_Free_Speech" title="https://xkcd.com/1357/ The famous xkcd comic about free speech. See transcript on https://www.explainxkcd.com/wiki/index.php/1357:_Free_Speech" style="max-width: 20rem; max-height: 40rem;">
        </a>

2025-10-19 11:30:53 Why the open social web matters now - https://werd.io/why-the-open-social-web-matters-now/

双语留档

<a href="/miscMedia/SlipBox_q9i8su8w_0_share4044655835246134171.html" class="md-attach md-attach-file-link" target="_blank">SlipBox_q9i8su8w_0_share4044655835246134171.html</a>

2025-10-19 22:41:33 浏览器里给了一句`font-family: monospace`，结果它的字体还和当前节点所属的lang有关？是中文直接变宋体，忽略浏览器设置？？

2025-10-20 00:00:26 https://www.rich-text-to-markdown.com/

2025-10-20 01:51:50 repost="guarded/misc/tg/2025-10-19/2025-10-19_15.36.28" 这篇的存档，AI生成的作品。

可怕的是人的神经结构是否确实允许会如作品中所说的认知方式的根本性改变？

<a href="/miscMedia/SlipBox_6w18xwaj_0_(1)%20Tz%20on%20X%EF%BC%9A%20%EF%BC%82%E3%80%8A%E8%AE%A4%E7%9F%A5%E7%9A%84%E8%BF%9C%E7%82%B9%E3%80%8B_%E4%B8%80_%E6%88%91%E7%AC%AC%E4%B8%80%E6%AC%A1%E6%84%8F%E8%AF%86%E5%88%B0%E8%AF%AD%E8%A8%80%E5%87%BA%E4%BA%86%E9%97%AE%E9%A2%98%EF%BC%8C%E6%98%AF%E5%9C%A8%E7%BB%99%E5%84%BF%E5%AD%90%E6%A3%80%E6%9F%A5%E4%BD%9C%E6%96%87%E7%9A%84%E6%97%B6%E5%80%99%E3%80%82_%E9%82%A3%E6%98%AF%E4%B8%80%E7%AF%87%E5%85%B3%E4%BA%8E%EF%BC%82%E6%97%B6%E9%97%B4%EF%BC%82%E7%9A%84%E5%91%BD%E9%A2%98%E4%BD%9C%E6%96%87%E3%80%82%E4%BB%96%E5%86%99%E9%81%93%EF%BC%9A%E2%80%A6.html" class="md-attach md-attach-file-link" target="_blank">SlipBox_6w18xwaj_0_(1) Tz on X： ＂《认知的远点》_一_我第一次意识到语言出了问题，是在给儿子检查作文的时候。_那是一篇关于＂时间＂的命题作文。他写道：….html</a>

2025-10-20 12:37:17 tidbit={"如果你看不懂":"这是在用一般互联网公司会为云服务制作的运行状态监控页（status page）的形式为美国政府也做了个运行状态页。"} US Government Uptime Monitor 美国政府正常运行时间监控器 - https://usa-status.com/

草

2025-10-22 08:57:01 错误处理：异常好于状态码 - 阮一峰的网络日志 - http://www.ruanyifeng.com/blog/2025/10/exception.html

> 在软件中，错误处理有两种方式：抛出异常（throwing exceptions）和返回状态码（returning status codes）。
>
> 几乎所有人都认为异常是更好的处理方式，但有些人仍然更喜欢返回状态码。本文解释为什么异常是更好的选择

源：Ned Batchelder
译：阮一峰

<a href="/miscMedia/SlipBox_97kqmd1t_0_%E9%94%99%E8%AF%AF%E5%A4%84%E7%90%86%EF%BC%9A%E5%BC%82%E5%B8%B8%E5%A5%BD%E4%BA%8E%E7%8A%B6%E6%80%81%E7%A0%81%20-%20%E9%98%AE%E4%B8%80%E5%B3%B0%E7%9A%84%E7%BD%91%E7%BB%9C%E6%97%A5%E5%BF%97%20(2025_10_22%2008%EF%BC%9A55%EF%BC%9A20).html" class="md-attach md-attach-file-link" target="_blank">备档</a>

2025-10-22 10:24:31 repost="guarded/hive/Rant/2025-10-13_17.57.32" 即使是NanaZip，相对于原版7-Zip的体验也有降级（启动速度；文件关联设置；以及所有的对话框都只在主显示器位置弹出而不是当前显示器），真不知道代码基是一样的为什么会改成这样。更别提PeaZip这个打开等几秒的了…

7-Zip有一点不好：默认宋体，之后看有没有办法改

2025-10-22 23:46:35 继Reddit内建全站贴文多语言AI翻译版本且开放给Google直接索引后 * ，现在知乎也同样开始做中译英了：

https://www.google.com/search?q=site%3Aen.zhihu.com

https://en.zhihu.com/answer/221354314

\---

**\* 关于Reddit见 -**

Reddit 的內建翻譯機制 | 敘事鋸 Narrativesaw - https://www.narrativesaw.com/2025/09/05/reddit-reddit-ai-ai.html

Bringing Reddit to More People Around the World – Machine Learning-Powered Localization and Translation Launching in More than 35 New Countries - https://redditinc.com/blog/bringing-reddit-to-more-people-around-the-world-machine-learning-powered-localization-and-translation-launching-in-more-than-35-new-countries

Reddit AI 翻译拯救了 Google 中文搜索结果质量 - V2EX - https://www.v2ex.com/t/1140800


2025-10-23 17:46:07 草，一个检测任意网站是否在线的工具站 https://downforeveryoneorjustme.com/ 居然有了一个短链： http://www.downfor.io/

之前也是直接Google搜索downfor找这个站的

2025-10-23 18:56:03 软件大厂，环境检测思路和规避思路，安卓改机应该改什么数据和参数，安卓boot内核修改 环境检测对抗 部分参数解析-CSDN博客 - https://blog.csdn.net/z920981023/article/details/131375231

啧，就是，你们能唉声叹气几百句又被这个App检测环境了又被那个风控了还不如去整两句有用的

<a href="/miscMedia/SlipBox_i034w5o8_0_%E8%BD%AF%E4%BB%B6%E5%A4%A7%E5%8E%82%EF%BC%8C%E7%8E%AF%E5%A2%83%E6%A3%80%E6%B5%8B%E6%80%9D%E8%B7%AF%E5%92%8C%E8%A7%84%E9%81%BF%E6%80%9D%E8%B7%AF%EF%BC%8C%E5%AE%89%E5%8D%93%E6%94%B9%E6%9C%BA%E5%BA%94%E8%AF%A5%E6%94%B9%E4%BB%80%E4%B9%88%E6%95%B0%E6%8D%AE%E5%92%8C%E5%8F%82%E6%95%B0%EF%BC%8C%E5%AE%89%E5%8D%93boot%E5%86%85%E6%A0%B8%E4%BF%AE%E6%94%B9%20%E7%8E%AF%E5%A2%83%E6%A3%80%E6%B5%8B%E5%AF%B9%E6%8A%97%20%E9%83%A8%E5%88%86%E5%8F%82%E6%95%B0%E8%A7%A3%E6%9E%90-CSDN%E5%8D%9A%E5%AE%A2%20(2025_10_23%2018%EF%BC%9A53%E2%80%A6.html" class="md-attach md-attach-file-link" target="_blank">备档</a>

2025-10-23 20:25:49 Programming With Less Than Nothing - https://joshmoody.org/blog/programming-with-less-than-nothing/

<a href="/miscMedia/SlipBox_qakl96f8_0_Programming%20With%20Less%20Than%20Nothing%20(2025_10_23%2020%EF%BC%9A25%EF%BC%9A14).html" class="md-attach md-attach-file-link" target="_blank">备档</a>

2025-10-23 20:28:54 #bash Scripts I wrote that I use all the time - https://evanhahn.com/scripts-i-wrote-that-i-use-all-the-time/

<a href="/miscMedia/SlipBox_qa2chfpl_0_Scripts%20I%20wrote%20that%20I%20use%20all%20the%20time%20(2025_10_23%2020%EF%BC%9A28%EF%BC%9A11).html" class="md-attach md-attach-file-link" target="_blank">备档</a>

2025-10-24 00:43:26 repost=guarded/SlipBox/2025-10-22_10.24.31,guarded/hive/Rant/2025-10-13_17.57.32 好了，花了一晚上把之前工作过的Easy7-Zip-SF直接rebase干上了最新版25.01，再也不用管什么NanaZip和PeaZip了。

https://github.com/shunf4/Easy7-Zip-SF

2025-10-24 21:52:18 repost=guarded/SlipBox/2025-10-19_22.41.33 现在浏览器御二家对于简体中文的字体fallback依然是狗屎。证据：

- "`font.name-list.monospace.zh-CN`" is "`NSimSun, SimSun, MS Song, SimSun-ExtB`" by default on ff
- https://issues.chromium.org/issues/41104519

所以本站所有目前`lang="zh-Hans"`下的`font-family: monospace`（等宽字体 Fixed-width font）内容仍然是宋体，如： <span style="font-family:monospace;">这是一段等宽字体文字</span> ，没有任何浏览器内建设置可供调整，唯一调整办法是用[/styleCustomizer](/styleCustomizer)或者UserScript或者UserStyle自定义页面样式。

- 2025-10-27 10:59:55 更新：验证了一下，这似乎是一个仅Windows端的问题。

2025-10-25 00:20:43 repost=guarded/misc/tg/2025-10-22/2025-10-22_16.58.30 本站已尝试全站内容默认添加此CSS样式。Chromium 140以上（如果没有在[/styleCustomizer](/styleCustomizer)自定义过样式）应该可以正常看到中英字符间距了。

2025-10-25 00:22:37 把Chromium Hibbiki fork更到了140以上发现它已经开始block Manifest V2扩展，怒切Marmaduke fork

2025-10-26 10:51:08 Tarmageddon: RCE vulnerability highlights challenges of open source abandonware Tamageddon: RCE 漏洞突出开源弃用软件的挑战 - https://edera.dev/stories/tarmageddon

2025-10-26 17:26:53 笑死我了，llama.cpp自带的那个Web界面刷新内容会让Chromium吃死GPU，查了半天为什么模型跑起来卡卡的结果发现GPU占用最多的不是模型自己

2025-10-26 20:11:53 Any decent error message is a kind of oracle — Digital Seams - https://digitalseams.com/blog/any-decent-error-message-is-a-kind-of-oracle

2025-10-27 00:49:44 这个博客的其他文章好像特别喜欢不说人话，which让我比较在意

The Great SaaS-Lighting: How IT Users Got Gaslit – Unworkable Ideas - https://unworkableideas.com/the-great-saas-lighting-how-it-users-got-gaslit/

<a href="/miscMedia/SlipBox_7uewgqdg_0_The%20Great%20SaaS-Lighting%EF%BC%9A%20How%20IT%20Users%20Got%20Gaslit%20%E2%80%93%20Unworkable%20Ideas%20(2025_10_27%2000%EF%BC%9A48%EF%BC%9A15).html" class="md-attach md-attach-file-link" target="_blank">留档</a>

2025-10-27 00:56:34 好了，我弄通了在手机上给网页机翻+留档的流程：

- 使用Ultimatum，较新版Android Chromium系浏览器安装扩展插件的唯一办法。虽然作者现在不更了。
- 安装SingleFile-MV3、ScriptCat、ScTranslator。
- 最重要的：SingleFile把misc-save in background关掉，否则下载报错；下载前确认dialog也可以关掉。SingleFile通过导出配置，编辑，导入的方式把userscript隐藏选项打开。
- ScriptCat安装Eruda UserScript，方便随时开控制台。写一个SingleFile事件处理器，保存前先将当前网页请求留档到Internet Archive和archive.today。
- done。现在可以先打开网页，点工具栏ScTranslator全文翻译，然后点一下SingleFile，网页就被抓下来提示保存到本地了。

2025-10-27 01:03:08 ref=guarded/SlipBox/2025-10-27_00.56.34 不是，找了个没收录过的URL试了下，怎么感觉IA和AT的这两个api都没用啊，提交了后还是反查不到，还是说要排队？不管了，反正已经提交获取到200返回，尽最大努力了，它收不收录是它的事。

- 2025-10-27 11:00:54 更新：后续确认，AT的接口没问题，提交了之后几分钟出结果。IA调整了一下参数要求其尽快存档，如此修改了之后IA几分钟后也可成功存档。

2025-10-28 20:49:14 #WhatIAmOntoNow #ShareAiPrompt

```
Give source code for a minimal (but complete - do not omit) and secure docker setup of Java + Maven + Tomcat + SFTP-hosted JSP (with an initial page of "Hello world"), suitable to be deployed to Fly.io .
```

2025-10-31 23:42:18 又一个Chromium on Android with Extension Support：

https://github.com/jqssun/android-helium-browser

HN讨论：

https://news.ycombinator.com/item?id=45715752

这可能得益于Chromium 142（？）起对移动端扩展的官方支持，谷歌官方也对支持移动端扩展的Chromium进行了官方构建发布，这个GitHub仓库将其自动获取下来发布为Release：

https://github.com/andrewginns/chromium-browser-snapshots-AndroidDesktop_arm64/releases

2025-11-01 00:44:49 repost=guarded/SlipBox/2025-10-31_23.42.18 试了下，这两个浏览器在加载本地已解包的扩展程序目录后都是直接闪退，纯烂。看来现阶段少不了Ultimatum那样对扩展程序在移动端做单独适配。

2025-11-01 01:02:49 repost=guarded/SlipBox/2025-10-31_23.42.18 Helium说是proudly based on Ungoogled Chromium，但看起来Android端并没有很Ungoogled啊，搜索引擎有Google，也能直跳Chrome扩展商店页（一般的Ungoogled Chromium分支应该都做了对google域名全量替换屏蔽）。但是这次发现了Mullvad Leta这个搜索引擎代理站，可以代理搜Brave搜索引擎和Google，好东西。

https://leta.mullvad.net/search?q=hello

2025-11-01 13:45:15 我们仍未知道那位日本人所说的风、竿子和龙的含义

https://entropicthoughts.com/the-wind-a-pole-and-the-dragon

36天前的HN讨论： https://news.ycombinator.com/item?id=45371309

2025-11-01 18:35:31 #Windows

https://jspaint.app/

https://98.js.org/

2025-11-02 14:02:14 https://fxgn.dev/blog/anubis/

一个比Anubis简单得多的，似乎同样能有效防止现阶段AI/LLM公司爬虫的方案，基于一段简短的JavaScript和Cookies校验

（针对性的绕过很容易！

2025-11-02 19:03:32 repost=guarded/SlipBox/2025-10-22_23.46.35

Tech Crimes Telegram频道的人已经发现这些页面了：https://t.me/techcrimes/14915

<a href="/miscMedia/SlipBox_3z4fpnbh_0_Screenshot_2025-11-02-19-03-01-25_ab4d794cbd93f5c7689532989c84240a.jpg" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/SlipBox_3z4fpnbh_0_Screenshot_2025-11-02-19-03-01-25_ab4d794cbd93f5c7689532989c84240a.jpg" class="md-attach md-attach-img" alt="" title="" style="max-width: 20rem; max-height: 40rem;">
        </a>
