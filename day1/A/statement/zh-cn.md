{{ self.title() }}

{{ s('description') }}

给定 $n$ 个数 $a_1,a_2,\cdots,a_n$，你需要求以下式子的值：

$$\sum_{S \subseteq \{1,2,\cdots,n\}} \varphi \left(\prod_{i \in S} a_i\right).$$

其中 $\phi$ 为欧拉函数，$\phi(x)$ 表示在 $[1,x]$ 内与 $x$ 互质的整数数量，例如

- $\varphi(6) = 2$，因为在 $[1,6]$ 内有 $1$ 和 $5$ 与 $6$ 互质。
- $\varphi(1) = 1$，因为在 $[1,1]$ 内有 $1$ 与 $1$ 互质。

另外，我们定义 $\prod_{i \in \varnothing} a_i = 1$。

答案可能很大，你需要求出其对质数 $998244353$ 取模的结果。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行为一个整数 $n (1 \le n \le 2000)$ 表示数的数量，接下来一行 $n$ 个整数 $a_1,a_2,\cdots, a_n (1 \le a_i \le 3000)$。

{{ s('output format') }}

{{ self.output_file() }}

输出一行一个整数表示答案，对 $998244353$ 取模。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

共有八种 $S$ 的选择，所有选择得到的 $\prod_{i \in S} a_i$ 分别为 $1,1,2,2,3,3,6,6$。可以计算得到 $\varphi(1) = \varphi(2) = 1, \varphi(3) = \varphi(6) = 2$，因此答案为 $1 \times 4 + 2 \times 4 = 12$。
