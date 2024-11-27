# CatsDaily

这里记录每天一道codeforces练习题，难度试每天的时间和心情而定

命令行输入`python day.py`，输入难度号可以随机得到一个难度和一个网址，点击这个网址下的第一道没做过的题就是今天的每日一题

`0py.py`和`0cpp.cpp`是标准模板，对于多组输入样例，以`0cpp.cpp`为例，直接修改`solve()`函数中的内容即可，单组输入样例则需要在调试结束后提交时手动注释掉`cin >> t;`一行

`0IN`是输入文件，这里面可以提前放好输入直接调试。

`.vscode`路径中是vscode的相关配置，只在我自己的电脑上可用

`.vscode/tasks.json`中定义了两种调试方式，一种是从`0IN`文件读入，一种是命令行读入，注意命令行读入不能一次粘贴大量数据，在断点后仍然有输入会出错(不明原因)

