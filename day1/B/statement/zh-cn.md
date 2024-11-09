{{ self.title() }}

{{ s('description') }}
在 `Python` 语言中，若将一个字符串先转换为序列 `list`，再转换为字符串 `str` 类型，可以得到一个新的字符串。以下控制台运行结果描述了这一过程。

{{ img('img.png', size = 0.4, align = 'middle', inline = False, label='fig:sample') }}

以下我们形式化地描述从 $s$ 到 $\text{str(list(}s))$ 的变换。为了得到 $\text{str(list(}s))$，我们需要将 $s$ 中的每个字符 $s_i \ (0 \le i < |s|)$ 替换为使用如下规则产生的长度为 $5$ 的字符串 $t_{i,0}t_{i,1}t_{i,2}t_{i,3}t_{i,4}$：

- $t_{i,2} = s_i$。
- 当 $s_i$ 不是单引号 `'` 时，$t_{i,1}$ 和 $t_{i,3}$ 均为单引号 `'` (ASCII 39)，否则 $t_{i,1}$ 和 $t_{i,3}$ 均为双引号 `"` (ASCII 34)。
- 当 $i \ne 0$ 时，$t_{i,0}$ 为空格 `' '` (ASCII 32)，否则为左中括号 `[` (ASCII 91)。
- 当 $i \ne |s|-1$ 时，$t_{i,4}$ 为逗号 `,`(ASCII 44) ，否则为右中括号 `]` (ASCII 93)。

现在，输入一个由除空白字符以外的可见字符（即 ASCII 码 33 至 126 的所有字符）构成的字符串 $s$，设 $s^0 = s$，对于整数 $i>0$，定义 $s^i = \text{str(list(}s^{i-1}))$。再输入两个整数 $k$ 和 $p$，你需要对每个 $0 \le j < p$ 求出 $s^k$ 中所有下标模 $p$ 为 $j$ 的字符的 ASCII 码的和，字符串下标从 $0$ 开始编号。若不存在下标模 $p$ 为 $j$ 的字符，认为答案为 $0$。答案可能很大，你需要将答案对 $(10^9+7)$ 取模。

{{ s('input format') }}

{{ self.input_file() }}

输入的第一行一个由除空白字符以外的可见字符构成的字符串 $s \ (1 \le |s| \le {{tl.hn(args['len'])}})$，第二行两个整数 $k, p \ (1 \le k,p \le {{tl.hn(args['k'])}})$。

{{ s('output format') }}

{{ self.output_file() }}

输出一行 $p$ 个整数，第 $(j+1)$ 个整数表示 $s^k$ 中下标模 $p$ 为 $j$ 的所有字符的 ASCII 码的和，对 $(10^9+7)$ 取模。

{{ s('sample', 1) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

该组样例的最终字符串 $s^1$ 即为题目描述的 `Python` 控制台运行过程中的 `s1`。

{{ s('sample', 2) }}

{{ self.sample_text() }}

{{ self.title_sample_description() }}

该组样例的最终字符串 $s^2$ 即为题目描述的 `Python` 控制台运行过程中的 `s2`。

{{ s('sample', 3) }}

{{ self.sample_file() }}

{{ self.title_sample_description() }}

该样例的字符串中包含了所有除空白字符以外的可见字符。
