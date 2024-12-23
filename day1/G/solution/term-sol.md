记 $w$ 为 $b$ 的最大的不能被 $2$ 或 $5$ 整除的因数，下面证明最终答案的 $d$ 满足 $d=2^x5^yw$，其中 $x,y$ 是非负整数：

若存在质因数中不含 $2,5$ 的大于 $1$ 的正整数 $p$ 满足 $b$ 是 $p$ 的倍数而 $d$ 不是 $p$ 的倍数，那么根据 $\gcd(a,b)=1$ 可得 $a$ 也不是 $p$ 的倍数，那么 $\dfrac{a}{b}+\dfrac{c}{d}=\dfrac{ad+bc}{bd}$，其中 $bc,bd$ 均为 $p$ 的倍数而 $ad$ 不是 $p$ 的倍数，则 $\dfrac{ad+bc}{bd}$ 显然不是有限小数。

若存在质因数中不含 $2,5$ 的大于 $1$ 的正整数 $p$ 满足 $d$ 是 $p$ 的倍数而 $b$ 不是 $p$ 的倍数，那么 $bc,bd$ 均为 $p$ 的倍数，为了使 $\dfrac{ad+bc}{bd}$ 是整数或有限小数，那么 $c$ 也必须是 $p$ 的倍数，则 $c,d$ 不互质，显然不满足 $c$ 最小的条件。

综上，合法的 $d$ 的可能取值数 $D<\log_2(10^9)^2<900$，因此只需要枚举所有符合 $d=2^x5^yw$ 形式的 $d$，再分别解不定方程 $ad+bc=kbd$ 求出 $c$ 的最小非负整数解，最后取所有解中的最小值即可。

总时间复杂度约为 $O(T\log^3 L)$，其中 $L=10^9$ 为 $d$ 的取值上限。

