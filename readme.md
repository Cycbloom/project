#

在Ubuntu 22.04系统下编译运行

命令行输入make，在build目录下生成tiger

运行tiger，若语法分析成功则在本目录下生成tree.dot

使用命令dot -Tpng tree.dot -o tree.png可生成可视化的中间代码树。

use

make test

to generate all the test parse tree.
