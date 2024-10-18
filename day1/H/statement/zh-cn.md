{{ self.title() }}

{{ s('background') }}

{{ s('description') }}

给一棵$n$个点的无向树, 每个点$i$初始时有一个权值$c_i$, 表示这个点初始的沙子数量

如果存在一个点$i$, 满足$c_i\geqslant deg_i$, 则我们可以对这个点进行**fire**操作, 即令$c_i$减去$deg_i$, 并将其所有邻居的$c_i$加上$1$

每一时刻如果你可以找到一个点进行**fire**操作, 则随意挑选一个进行**fire**

可以证明, 如果存在一个有限的操作序列使得最终找不到一个点进行**fire**, 则所有的操作序列都将是有限的, 并且得到的最终状态, 即结束操作时的$c_i$数组是一致的

请对给定的初始状态判定其是否结束, 如果结束, 输出唯一的最终状态

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行包含一个正整数 $n(1\leqslant n\leqslant 10^6)$

接下来$n-1$行每行包含两个整数$x,y$表示一条边

接下来一行$n$个整数$c_i(0\leqslant c_i\leqslant 10^9)$表示初始时每个点上的沙子数量

{{ s('output format') }}

{{ self.output_file() }}

如果不能结束, 输出 `-1`

否则输出$n$个数表示最终的$c_i$数组

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ s('sample', 3) }}

{{ self.sample_text() }}

{{ s('hint') }}

一道好题, 一道坏题, 一道令人开心的题, 一道令人变得不幸的题