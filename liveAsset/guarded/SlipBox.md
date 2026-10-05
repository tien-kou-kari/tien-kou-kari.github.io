---
isDerivableIntoChildren: true
---

2026-10-05 16:42:57 placeholder

2026-10-05 17:04:21 #tk演进

- 把Latest（TheFlow）流也放到release版（非insider版）首页了。
- 试了一下把SlipBox.md archive一次，让其与新开的并存，hoard出问题了，修了。
- 并且还有问题：疑似这个archive过程没有被incremental很好地处理（例如：先处理新开文件，再处理新出现的archive文件；或者反过来；或者两者都有问题），需要手动重启hoard全量一次才正常，后面看。
