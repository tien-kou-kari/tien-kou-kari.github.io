---
isDerivableIntoChildren: true
---

2025-10-13 17:57:32 因为7-Zip vuln，又下了PeaZip试了试。PeaZip到2025年了，还是没把Windows的文件关联搞明白…

装完文件关联不Work，研究了下是因为文件关联分系统全局设置和用户设置，7-Zip的关联选项一应俱全清晰明了，但是PeaZip就只有那几个复选框，只修改全局设置，所以如果事前有用户设置的覆盖，则完全不生效。
