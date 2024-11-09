{{ self.title() }}



{{ s('description') }}

称一个长度为 $n$ 的 $0,1$ 序列 $a_i(1\le i \le n)$ 是 $m$-好的（$1\le m \le n$），如果它所有长度为 $m$ 的子区间和递增。具体地，记 $S_i=a_{i}+a_{i+1}+\cdots+a_{i+m-1}$，那么 $S_1\le S_2\le \cdots \le S_{n-m+1}$。 称一个序列为 $m$-极好的，如果对于任意 $m\le m'\le n$，这个数列都是 $m'$-好的。给定 $n,m$，求 $m'$-极好的序列的个数，对 $998244353$ 取模。有 $T$ 组数据，你需要回答所有的询问。

{{ s('input format') }}

{{ self.input_file() }}

第一行一个整数 $T(1 \le T\le 10^5)$ 表示询问组数。

接下来 $T$ 行，每一行两个整数 $n,m(1 \le m \le n \le 10^9)$，表示一组询问。

{{ s('output format') }}

{{ self.output_file() }}

对于每一组询问，输出一行一个整数，表示答案。

{{ s('sample', 1) }}

{{ self.sample_text() }}


{{ self.title_sample_description() }}

长度为 $3$ 的序列中，$1$-极好的有 $000,001,011,111$；$2$-极好的还有 $010,101$；$3$-极好的还有 $100,110$。 

