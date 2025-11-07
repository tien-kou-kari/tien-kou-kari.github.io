---
publishTime: '2025-11-08 01:03:46'
childrenSortOrder: condTimeDesc
isDerivableIntoChildren: true
title: 'MegaPost: Hack，或计算世界中的诸多魔法/巫术/術/器/怪异/奇谭/訳/无奈与妥协'
---

2025-11-08 01:13:37

##### Ventoy安装在本地硬盘上与Windows共存的办法

- 必须缩小+挪动Windows C盘，使得其前面有一块较大区域。
- 将原EFI扩大并挪动，使得EFI分区从1MB开始（2048扇区），占用较大空间，与Microsoft保留分区间隔40MB以上。
- 从Windows安装Ventoy，必须选择“无损安装”，Ventoy应能无需再操作分区，自行将VTOYEFI分区安装在上述40MB空闲空间内。
- 此时EFI分区将作为Ventoy承载ISO和配置的分区，即使其空间不足以放ISO，也可以用Vlnk的方式引用C盘或后面分区的ISO、Vtoy等文件。

2025-11-08 01:15:48

##### BugMeNot - share login, share user, share password, share account

https://bugmenot.com/

至少对Oracle官网和Broadcom（VMWare）官网这种不不登录不给下载的毒瘤还有用

