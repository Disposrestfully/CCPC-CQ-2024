{{ self.title() }}

签到题。

根据矩阵生成方式，可以发现：从高到低依次考虑每一个三进制位，如果 $n_1,n_2$ 在这一位上都不是 $1$ 则答案为 $0$，否则需要再判定下一位。

因此，当且仅当两个三进制数在每一位上都至少有一个是 $1$ 时答案为 $1$，否则为 $0$。
