{{ self.title() }}

{{ s('description') }}

给定两个互质正整数 $a, b$，你需要求两个非负整数 $c, d$，满足以下两个条件：

- $\frac{a}{b}+\frac{c}{d}$ 为十进制下的整数或有限小数。
- $1\le d \le {{ args['d'].hn() }}$。

在所有满足条件的非负整数对 $(c,d)$ 中，请求出 $c$ 最小的一对。

一个有理数 $x$ 是十进制下的有限小数，当且仅当将 $x$ 在十进制下以小数形式写出后，小数点后的位数是有限的，即存在正整数 $k$，整数 $p$ 和整数数组 $(q_1,q_2,\dots,q_k)$ 满足 $0\le q_i \le 9$，使得 $x=p+\sum\limits_{i=1}^{k}q_i\cdot 10^{-i}$。

{{ s('input format') }}

{{ self.input_file() }}

第一行包含一个正整数 $T\ (1\le T \le {{ args['t'].hn() }})$，表示数据组数。

每组数据包含一行两个正整数 $a, b \ (1\le a\le b\le {{ args['a'].hn() }})$，含义如题目描述所示。保证 $\gcd(a,b)=1$。

{{ s('output format') }}

{{ self.output_file() }}

对于每组数据，输出一行两个非负整数 $c, d$。如果有多组正确答案，输出任意一组即可。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

对于第一组数据，由于 $\frac{1}{2}=0.5$ 是有限小数，因此输出 $(c,d)$ 满足 $c=0$ 且 $1\le d \le {{ args['d'].hn() }}$ 即可。

对于第二组数据，$\frac{2}{3}+\frac{1}{3}=1$ 是整数，且 $\frac{2}{3}=0.666\dots$ 不是有限小数，因此 $c=1$ 是最小可能值。

对于第三组数据，$\frac{3}{7}+\frac{1}{14}=\frac{1}{2}=0.5$ 是有限小数。

对于第四组数据，$\frac{19}{79}+\frac{3}{316}=\frac{1}{4}=0.25$ 是有限小数，且可以证明不存在 $0\le c\le 2$，$1\le d \le 10^9$ 使得 $\frac{19}{79}+\frac{c}{d}$ 是有限小数。
