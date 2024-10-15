{{ self.title() }}

{{ s('description') }}

在 $n$ 行 $m$ 列的网格的最左上角的格子上，有一个边长和网格格子边长相等的骰子。初始，这个骰子 $1$ 在顶面，$2$ 朝下，$3$ 朝右，$i$ 的背后是 $7-i$，如下图所示。

{{ img('img1.png', size = 0.3, align = 'middle', inline = False, label='fig:sample') }}

现在你可以做任意多次操作，每次操作为以下两种：

- 若当前骰子所在的格子没有数字，在这个格子上写下骰子底面的数字；
- 选择上下左右四个方向的某一个，将骰子沿着这个方向滚一次：选择骰子底面对应方向的棱，将骰子沿着这条棱旋转九十度。下图展示了初始状态向右滚一次的结果。你不能将骰子滚出网格。

注意：在骰子第一次经过某个格子时，你可以选择不把此时底面的数字写在这个格子上。

{{ img('img2.png', size = 0.3, align = 'middle', inline = False, label='fig:sample') }}

你希望最大化最后网格上所有写过数字的格子的数字的和。

{{ s('input format') }}

{{ self.input_file() }}

输入一行两个整数 $n,m (2 \le n,m \le {{tl.hn(args['n'])}})$，表示网格的长和宽。

{{ s('output format') }}

{{ self.output_file() }}

输出一行一个整数，表示在进行任意多次操作后，网格上所有写过数字的格子的数字的和的最大值。

{{ s('sample', 1) }}

{{ self.sample_text() }}
