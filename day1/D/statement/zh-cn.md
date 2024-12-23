{{ self.title() }}

{{ s('description') }}

小白有 $n$ 个西瓜（保证 $n$ 是奇数），每个西瓜有个重量 $a_i$。她在这 $n$ 个西瓜之间建立了 $m$ 条无向边，使任意两个西瓜之间都至少存在一条路径能到达。

小白现在可以选择三个西瓜进行合并，具体地，她会选择三个不同的西瓜 $x,y,z$ 满足 $x,y$ 之间有一条无向边，$y,z$ 之间有一条无向边。她会得到一个新的西瓜 $w$，其重量 $a_w=\max(a_y,\min(a_x,a_z))$。接下来，她对于“至少和 $x,y,z$ 中某个西瓜之间有无向边”的西瓜 $t$，建立了一条 $(w,t)$ 之间的无向边。最后，小白删去了 $x,y,z$ 三个西瓜以及某一端为 $x,y,z$ 的无向边。

可以证明一定存在一种合并 $\frac{n-1}2$ 次的方案使得最后仅剩下一个西瓜，小白想知道最后那个西瓜重量的最大值是多少。

{{ s('input format') }}

{{ self.input_file() }}

第一行两个非负整数 $n,m$。保证 $1\le n\le 10^5$，$0\leq m\leq 10^5$，且 $n$ 是奇数。

第二行 $n$ 个正整数 $a_1, a_2, \dots, a_n$，表示每个西瓜的重量。保证 $1\le a_i\le n$。

接下来 $m$ 行，每行两个正整数 $x,y$ 表示图上的一条无向边 $(x,y)$。保证 $1\le x,y\le n$ 且 $x\ne y$。

保证给定的无向图连通，且无重边与自环。

{{ s('output format') }}

{{ self.output_file() }}

一行一个正整数，表示答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}
