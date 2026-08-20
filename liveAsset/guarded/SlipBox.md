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

2025-10-28 20:49:14 #WhatIAmOntoNow #AiPrompt #Pastebin

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

2025-11-02 21:09:41 We reduced a container image from 800GB to 2GB 我们将容器映像从 800GB 减少到 2GB - https://sealos.io/blog/reduce-container-image-size-case-study

HN讨论 https://news.ycombinator.com/item?id=45719237

抛开他们展示的公司内糟糕的docker层级管理不论，我已经见到docker image squash工具被独立发明至少3次以上了…

2025-11-04 01:50:12 mycophobia's web site - Debian+MATE: An OS that stays put

https://mycophobia.org/debian_mate.html

《永恒OS》

2025-11-06 21:40:13 https://blog.fooleap.org/use-non-monospaced-font-in-gvim.html

在 gVim 中使用“非等宽字体”

<a href="/miscMedia/SlipBox_3ldy0vip_0_%E5%9C%A8%20gVim%20%E4%B8%AD%E4%BD%BF%E7%94%A8%E2%80%9C%E9%9D%9E%E7%AD%89%E5%AE%BD%E5%AD%97%E4%BD%93%E2%80%9D%20_%20Fooleap&#039;s%20Blog%20(11_6_2025%209_33_09%20PM).html" class="md-attach md-attach-file-link" target="_blank">SlipBox_3ldy0vip_0_在 gVim 中使用“非等宽字体” _ Fooleap&#039;s Blog (11_6_2025 9_33_09 PM).html</a>

2025-11-06 22:30:35 repost=guarded/SlipBox/2025-11-06_21.40.13  https://github.com/laishulu/Sarasa-Term-SC-Nerd

修正Panose元数据为等宽的更纱黑体

2025-11-08 02:31:15 https://www.youtube.com/watch?v=esCNvfKV9Rc

Yoo Se Yoon - Don't Skip the Interlude | Rooftop Live (1997~)

又整了第三版，带制作

2025-11-08 11:02:27 YouTube Removes Windows 11 Bypass Tutorials, Claims 'Risk of Physical Harm' YouTube 删除 Windows 11 旁路教程，声称存在 “身体伤害风险”

https://news.itsfoss.com/youtube-removes-windows-11-bypass-tutorials/

越来越离谱

2025-11-08 14:20:38 repost=guarded/SlipBox/2025-11-01_01.02.49 

Mullvad: Shutting down our search proxy Leta
https://mullvad.net/en/blog/shutting-down-our-search-proxy-leta

不是…？

2025-11-09 20:46:32 Ticker: Don’t Die of Heart Disease

https://myticker.com/

2025-11-10 12:31:14 Cromite前几天释出了支持扩展程序的测试版本，我们终于要再次拥有自由源码的Android端支持扩展且可维持更新的Chromium浏览器了： https://github.com/uazo/cromite/issues/256

比较搞笑的是扩展程序Load Unpacked功能还是闪退的（[不止一个用户验证了](https://github.com/uazo/cromite/issues/256#issuecomment-3495723111)），贴里给的workaround竟然是用Android原生文件应用**分屏拖放**.crx文件，第一次见这种操作！


2025-11-11 01:16:37 repost=guarded/SlipBox/2025-11-10_12.31.14 装上了，用上扩展插件了。So far so good

2025-11-11 01:35:10 妈的我撤回前言

2025-11-11 20:15:18 Comments on https://markusstrasser.org/creative-work-landscapes.html , from https://news.ycombinator.com/item?id=45885242 :

qlm:

> Perhaps a controversial view on this particular forum but I find the tendency of a certain type of person* to write about everything in this overly-technical way regardless of whether it is appropriate to the subject matter to be very tiresome ("executing cached heuristics", "constrained the search space").
>
>这可能是这个特定论坛上的一个有争议的观点，但我发现某种类型的人 * 倾向于以这种过于技术化的方式写所有东西，而不考虑主题是否适合变得非常令人厌烦 (“执行缓存启发式”、“限制搜索空间”)。
>
>*I associate it with the asinine contemporary "rationalist" movement (LessWrong et al.) but I'm not making any claims the author is associated with this.
>
>*我将其与愚蠢的当代 “理性主义” 运动 (LessWrong 等人) 联系在一起，但我并不认为作者与此有任何关联。
>

jbreckmckye:

>I have observed it too, it is heavily inspired by economics and mathematics.
>
>我也观察到了，它在很大程度上受到了经济学和数学的启发。
>
>Saying "it's better to complete something imperfect than spend forever polishing" - dumb, trite, anyone knows that. Saying "effort is a utility curve function that must be clamped to achieve meta-optimisation" - ooh, clever, this guy Has a Blog.
>
>说什么 “完成不完美的事情总比永远打磨要好”—— 愚蠢，陈词滥调，谁都知道。说什么 “努力是一个效用曲线函数，必须加以约束才能实现元优化”—— 哦，聪明，这家伙有个博客。
>
>If I was going to be uncharitable, I think there is a corner of the internet where people without much training in either economics or philosophy write straightforward things that appeal to their audience's bias, but dress it up in technical language to launder it as somehow academic and data driven.
>
>如果我要说得不客气的话，我认为互联网上有一个角落，那里的人既没有受过太多经济学或哲学方面的培训，却能写出直截了当的内容，迎合他们受众的偏见，同时又用技术性语言进行粉饰，以便在某种程度上以学术和数据驱动的形式进行洗白。

好骂

2025-11-13 14:34:40 我知道为什么我对AutoHotKey的第一印象这么差了，当时错认为它是AutoIt，一个很久之前碰过的特别臃肿的同样做Windows自动化脚本的Freeware。

2025-11-14 00:43:56 Pure Sh Bible (Archived)

https://github.com/dylanaraps/pure-sh-bible

...

2025-11-15 10:20:36 AI World Clocks AI 世界时钟 - https://clocks.brianmoore.com/

可以和Simon的鹈鹕自行车测试一起列为AI的[画钟试验](https://en.wikipedia.org/wiki/Executive_dysfunction#Clock_drawing_test)了（原来Kimi K2这么强吗

2025-11-15 19:48:49 > aorth 2 hours ago | parent | context | favorite | on: Unofficial Microsoft Teams client for Linux
>
> True! I've been doing this for years on Linux. I use a dedicated Chromium instance in app mode:
>     /usr/bin/chromium --ozone-platform=wayland --enable-features=UseOzonePlatform,WaylandWindowDecorations,WebRTCPipeWireCapturer --user-data-dir=/home/myuser/.config/chromium-ilri --app=https://teams.microsoft.com
> Works incredibly well (put this in a `.desktop` file with `Exec=` and you can launch it via your desktop's launcher). Some of the settings may not be needed anymore, as Chromium has come a long way in terms of Wayland support. I use Firefox for everything else, but haven't tried Teams there.

https://news.ycombinator.com/item?id=45936249

2025-11-16 11:34:06 > [...]
>
> And before you say "but no one does that", no, I've see that myself. Imagine you have a class that inherits from SteelMan but calls StealMan in it's constructor and Python's like "looks good to me".
>
> I've seen horrors you people can't imagine.
> 
> * I've seen superclass constructors called multiple times.
> 
> * I've seen constructors called out of order.
> 
> * I've seen intentional skipping of constructors (with comments saying "we have to do this because blah blah blah)
> 
> * I've seen intentional skipping of your parent's constructor and instead calling your grandparent's constructor.
> 
> * And worst of all, calling constructors which aren't even in your inheritance chain.

https://news.ycombinator.com/item?id=45942215

2025-11-16 19:53:11 Why I Don't Need a Steam Machine | Brain Baking

https://brainbaking.com/post/2025/11/why-i-dont-need-a-steam-machine/

2025-11-18 22:40:39 立 此 存 照

见 证 历 史

Ｃ Ｇ 回 收

拍 照 打 卡

<a href="/miscMedia/SlipBox_pj5cagby_0_image.png" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/SlipBox_pj5cagby_0_image.png" class="md-attach md-attach-img" alt="本站的Cloudflare Workers实例 https://tien-kou.shunf4.workers.dev/ 在2025年11月18日的Cloudflare全球大宕机事件中访问呈现“Cloudflare网络内部错误”的截图。" title="本站的Cloudflare Workers实例 https://tien-kou.shunf4.workers.dev/ 在2025年11月18日的Cloudflare全球大宕机事件中访问呈现“Cloudflare网络内部错误”的截图。" style="max-width: 20rem; max-height: 40rem;">
        </a>

2025-11-22 14:27:22 tidbits={"X-Note-On-Src":"截图是哔哩哔哩视频BV1djUEBPEmK的评论区。"}

<a href="/miscMedia/SlipBox_su7g6bg9_0_Stitch19aaa39c17f.png" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/SlipBox_su7g6bg9_0_Stitch19aaa39c17f.png" class="md-attach md-attach-img" alt="" title="" style="max-width: 20rem; max-height: 40rem;">
        </a>

2025-11-23 09:50:40 The privacy nightmare of browser fingerprinting https://kevinboone.me/fingerprinting.html

一个综述

HN评论也很有意思： https://news.ycombinator.com/item?id=46016249

> Some time ago I noticed that in Chrome, every time you click "Never translate $language", $language quietly gets added to the Accept-Language header that Chrome sends to every website!
> 
> My header ended up looking like a permuted version of this:
> 
>     en-US,en;q=0.9,zh-CN;q=0.8,de;q=0.7,ja;q=0.6
> 
> [...]
> 
> There was even a proposal to reduce this surface area, but it wasn't adopted:
> 
> https://github.com/explainers-by-googlers/reduce-accept-lang...

2025-11-23 20:28:35 https://news.ycombinator.com/item?id=45992035

2025-11-28 13:12:46 History of Zero-based Months? - https://www.jefftk.com/p/history-of-zero-based-months

2025-11-28 20:17:36 repost=guarded/misc/tg/2025-11-28/2025-11-28_20.16.28 我觉得值得一个 #DystopianDaily

2025-11-29 00:49:02 #TIL 抽水马桶两个冲水按键一起按，只相当于按了小按键。（啊？）

https://b23.tv/BV1nZi1YtEjx 03:20

2025-11-29 16:33:44 https://kerrick.blog/articles/2025/confessions-of-a-software-developer-no-more-self-censorship/

发现的第一个特别明显的多种分类分不同RSS Feed链接的个人博客

2025-12-02 19:52:09 #DystopianDaily India orders smartphone makers to preload state-owned cyber safety app 印度要求智能手机制造商预装国有网络安全应用程序 - https://www.reuters.com/sustainability/boards-policy-regulation/india-orders-mobile-phones-preloaded-with-government-app-ensure-cyber-safety-2025-12-01/

2025-12-04 20:16:01 > 但后来我意识到，这不仅仅是一次对话。每次我与西雅图的工程师分享 Wanderfugl 时，我都会得到同样条件反射式的、批评性的、负面的反应。在巴厘岛、东京、巴黎或旧金山，情况并非如此。那里的人们很好奇，很投入，想要理解我正在建造的东西。但在西雅图呢？他们一听到 “AI” 这个词就会立即产生敌意。

Everyone in Seattle Hates AI — Jonathon Ready - https://jonready.com/blog/posts/everyone-in-seattle-hates-ai.html

2025-12-04 20:21:23 > 只要用户以诗歌的形式表达问题，人工智能聊天机器人就会就核武器、儿童性虐待材料和恶意软件等话题进行讨论。研究表明：“诗歌框架在手工诗歌中的平均越狱成功率为 62%, 在元即时转换中约为 43%。”

Prompt Injection via Poetry 通过诗歌提前注入 - https://www.wired.com/story/poems-can-trick-ai-into-helping-you-make-a-nuclear-weapon/

(archive.today可绕付费墙)

2025-12-08 20:03:40 GitHub Actions Has a Package Manager, and It Might Be the Worst GitHub Actions 有一个包管理器，这可能是最糟糕的 - https://nesbitt.io/2025/12/06/github-actions-package-manager.html

非常好吹哨

2025-12-10 20:07:31 Show HN: Gemini Pro 3 hallucinates the HN front page 10 years from now 展示 HN:Gemini Pro 3 在 10 年后的 HN 首页上呈现幻觉 - https://dosaygo-studio.github.io/hn-front-page-2035/news

我踏马服了

2025-12-16 08:58:16 Vaxry's Blog - https://blog.vaxry.net/articles/2025-dbusSucks

好开

我们Linux桌面真是太安全啦

2025-12-18 11:14:19 Working quickly is more important than it seems (2015) 快速工作比看起来更重要 (2015) - https://jsomers.net/blog/speed-matters

2025-12-20 16:11:40 #TIL 新加坡管AIDS叫爱之病，看联合早报RSS才知道

台卫福部：台北袭击案一伤员是爱之病患者 - https://www.zaobao.com/realtime/china/story20251220-7993602

2025-12-20 16:14:03 repost=guarded/SlipBox/2025-12-20_16.11.40 然后维基百科（手机端）的语言选择列表预览看不出来，需要点选新加坡中文跳转后才能看出来： https://zh.wikipedia.org/wiki/艾滋病#/languages

2025-12-20 20:18:01 不是，AutoHotKey都能有Cloud Playground的吗？？

还有人做了AHK v1自动转v2的迁移工具？？？

天才

https://autohotkey.wiki/cloudahk

2025-12-27 20:36:31 From https://news.ycombinator.com/item?id=46395184 :


teddyh 16 hours ago | next [–]

> I then decided to contact Insulet to get the kernel source code for it, being GPLv2 licensed, they're obligated to provide it.
This is technically not true. It is an oversimplification of the common case, but what actually normally should happen is that:

1. The GPL requires the company to send the user a written offer of source code.

2. The user uses this offer to request the source code from the company.

3. If the user does not receive the source code, the user can sue the company for not honoring its promises, i.e. the offer of source code. This is not a GPL violation; it is a straight contract violation; the contract in this case being the explicit offer of source code, and not the GPL.

Note that all this is completely off the rails if the user does not receive a written offer of source code in the first place. In this case, the user has no right to source code, since the user did not receive an offer for source code.

However, the copyright holders can immediately sue the company for violating the GPL, since the company did not send a written offer of source code to the user. It does not matter if the company does or does not send the source code to the user; the fact that the company did not send a written offer to the user in the first place is by itself a GPL violation.

(IANAL)

reply

	
JoshTriplett 14 hours ago | parent | next [–]

This is an open legal question, which the Conservancy v Vizio case will hopefully change; in that case, Conservancy is arguing that consumers have the right to enforce the GPL in order to receive source code.
reply

	
schmuckonwheels 13 hours ago | root | parent | next [–]

This got buried on HN a few days ago which is a shame:
https://social.kernel.org/notice/B1aR6QFuzksLVSyBZQ

2025-12-28 10:09:18 From https://news.ycombinator.com/item?id=46404848 :

> Presumably this was what "journalism" was originally supposed to be.

《这就是新闻学》

2025-12-28 19:45:39 https://substack.com/inbox/post/182743659

中核404厂往事

2025-12-30 08:53:00 Mistakes engineers make in large established codebases - https://www.seangoedecke.com/large-established-codebases/

You can't design software you don't work on - https://www.seangoedecke.com/you-cant-design-software-you-dont-work-on/

2026-01-03 12:47:53 Publish (On Your) Own Site, Syndicate Elsewhere - https://indieweb.org/POSSE#

2026-01-08 20:43:55 So you wanna de-bog yourself (2024) https://www.experimental-history.com/p/so-you-wanna-de-bog-yourself

很好鸡汤文，有助于识别一些心理/行为上的谬误/困境

2026-01-10 14:03:01 #启示录最新进程 

The Vietnam government has banned rooted phones from using any banking app

https://xdaforums.com/t/discussion-the-root-and-mod-hiding-fingerprint-spoofing-keybox-stealing-cat-and-mouse-game.4425939/post-90441375

2026-01-23 20:12:39 #TIL GitHub可以在Settings-Appearance里启用高对比度模式，效果如图。

好几次看到别人的截图里有这样的界面，好奇是用了什么浏览器扩展或者UserStyles，最后发现原来是GitHub自带。

<a href="/miscMedia/SlipBox_uqejygrs_0_image.png" class="md-attach md-attach-img-link" target="_blank">
            <img src="/miscMedia/SlipBox_uqejygrs_0_image.png" class="md-attach md-attach-img" alt="一张截图，内容是GitHub网站的dnGrep/dnGrep仓库首页。浅色主题，启用了高对比度模式，对比非高对比度模式的情况，着色加深。原来有渐变背景色的区域也没有了渐变，抹平成了纯色。所有的分界边框线条变得更灰，似乎也变得更粗了。" title="一张截图，内容是GitHub网站的dnGrep/dnGrep仓库首页。浅色主题，启用了高对比度模式，对比非高对比度模式的情况，着色加深。原来有渐变背景色的区域也没有了渐变，抹平成了纯色。所有的分界边框线条变得更灰，似乎也变得更粗了。" style="max-width: 20rem; max-height: 40rem;">
        </a>

2026-01-25 20:01:06 https://news.ycombinator.com/item?id=46688804

含有一些Android和iOS生态的应用程序体验的争论

2026-01-29 20:15:15 https://growtika.com/blog/authenticity-edge

2026-01-29 20:33:11 > I remember the good old days of J2ME of writing everything from scratch. Or writing some graph editor for universiry, or some speculative, huffman coding algorithm.
> 
> That kept me sharp.
> 
> But today I feel like I'm living in that netflix series about people being in Hell and the Devil tricking them they're in Heaven and tormenting them: how on planet Earth do I keep sharp with java, streams, virtual threads, rxjava, tuning the jvm, react, kafka, kafka streams, aws, k8s, helm, jenkins pipelines, CI-CD, ECR, istio issues, in-house service discovery, hierarchical multi-regions, metrics and monitoring, autoscaling, spot instances and multi-arch images, multi-az, reliable and scalable yet as cheap as possible, yet as cloud native as possible, hazelcast and distributed systems, low level postgresql performance tuning, apache iceberg, trino, various in-house frameworks and idioms over all of this? Oh, and let's not forget the business domain, coding standards, code reviews, mentorships and organazing technical events. Also, it's 2026 so nobody hires QA or scrum masters anymore so take on those hats as well.
> 
> So LLMs it is, the new reality.

https://news.ycombinator.com/item?id=46771564

2026-01-31 23:10:09 https://en.wikipedia.org/wiki/Dinkus

https://en.wikipedia.org/wiki/Asterism_(typography)

2026-02-01 20:27:33 What I learned building an opinionated and minimal coding agent - https://mariozechner.at/posts/2025-11-30-pi-coding-agent/

敬佩，OpenClaw背后的agent实现，作者用了大量boring efforts去做的各提供商之间的抽象和尽最大努力的整合工作

2026-02-07 19:52:14 #ADHD小妙招

Start all of your commands with a comma - https://rhodesmill.org/brandon/2009/commands-with-comma/

2026-02-08 19:50:00 (AI) Slop Terrifies Me - https://ezhik.jp/ai-slop-terrifies-me/

- 2026-02-08 21:10:01 补：值得再读一遍。他居然用了temufication这个词…

2026-03-22 00:45:39 要像抵御病毒一样抵御GenAI。

2026-03-22 00:46:19 今日的 #TPOB : https://b23.tv/BV1a6wpz3EdW

2026-06-06 13:41:54 #TIL 某个论证“含有水分”/“holds water”在中文和英文中的意思是相反的。

2026-07-02 21:32:29 https://github.com/samyk/evercookie

一个利用尽可能多的浏览器存储机制来延伸 cookie 的存储，以达到尽可能规避清理，持续识别会话的效果

2026-07-04 11:12:53 MSI Center - How to gain SYSTEM privileges in seconds! | MrBruh's Epic Blog https://mrbruh.com/msicenter/

软件的平均水平be like，而且我前两天刚装了因为风扇不转

里面提到了Detect-It-Easy，似乎也和UniExtract2一样可以分析exe安装包的打包方式的，用来分析一些闭源专有安装包可能有用

2026-08-01 19:35:29 tk翻新工事中…

2026-08-02 23:32:54 tk todo: 需要查看对于telegram新特性（例如，那个大字体）的兼容性

2026-08-02 23:34:42 tk todo: enable wal for serve sqlite3

2026-08-04 02:16:57 I scream.

2026-08-05 22:45:53 https://github.com/chenxiaolong/BasicSync

我的意思是，妳看到了这个README.md列出的各种技术细节、对各种Android版本限制的因应，甚至还专门列出了Android多用户/多profile下运行多实例遇到问题怎么解决，就很难不让人不信任这个项目了。同时也让人感伤今时今日在这个还算“安全”的隔离应用操作系统由资本增值动机、平台moderation需要、政府监管要求共同塑造的技术架构下做开发，要处理多少带着镣铐还要转体前空翻托马斯全旋的事情。

2026-08-06 20:18:44 Pareto front - Wikipedia https://en.wikipedia.org/wiki/Pareto_front

#FromHn 近似于中国互联网上最近热议为“DeepSeek V4 Flash斩杀线”的概念（虽然今早dpsk宣布将涨价拉了

2026-08-06 20:27:08 Let’s all meet up in the Y2K  ⌘I  Get Info https://blog.gingerbeardman.com/2026/08/06/lets-all-meet-up-in-the-y2k/

#FromHn

2026-08-10 20:04:14 Everything You Do Is Being Recorded - The Atlantic https://www.theatlantic.com/technology/2026/05/ai-wearable-surveillance-countermeasures/687203/

#FromHn #Ril

2026-08-13 21:18:38 > AI makes projects with weak engineering culture fail much faster.

AI is removing the middle class of software engineering https://blog.florianherrengt.com/ai-removing-middle-class-software-engineering.html

#FromHn

2026-08-17 01:14:42 `q<hat>badge/0yt<hat>dQw4w9WgXcQ<hat>` (change `<hat>` to `^`) -> q^badge/0yt^dQw4w9WgXcQ^

2026-08-20 20:19:01 laserphile: AliExpress webpage keeping multipoint Bluetooth headphones active with WebAudio fingerprinting https://blog.laserphile.com/2026/08/aliexpress-webpage-keeping-multipoint.html?m=1

#fhn また阴险的老中dark pattern
