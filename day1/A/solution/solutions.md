#### prodphisum

我们知道，$\phi(x) = x \times \prod_{p \in \text{Prime}} [p \mid x] \frac{p-1}{p}$。故我们可以将所求式子重写为如下形式：$$\sum_{S \subseteq [n]} \prod_{i \in S} a_i \prod_{p \in \text{Prime}} [p \mid \prod_{i \in S} a_i] \frac{p-1}{p}.$$

如果 $\prod_{i \in [n]} a_i$ 的质因子个数很少，不妨设其质因子集合为 $P$ 且 $\lvert P \rvert \le 10$，我们可以对所有 $p \in P$ 记录 $[p \mid \prod_{i \in S} a_i]$ 是否为真，依次加入 $a_i$ 进行状压 DP：设 $f_{j,Q}$，其中 $Q \subseteq P$，表示如下式子的值：$$\sum_{S \subseteq [j]} \prod_{i \in S} a_i [\forall p \in P, p \mid \prod_{i \in S} a_i \iff p \in Q],$$ 即 $Q$ 记录了 $\prod_{i \in S} a_i$ 出现的质因子集合。依次考虑是否加入 $a_{j+1}$，容易得到转移。最后答案为 $\sum_{Q \subseteq P} f_{n,Q} \prod_{p \in Q} \frac{p-1}{p}$，即把之前省略的部分再乘上去就行了。复杂度为 $n2^{\lvert P \rvert}$。

尽管在实际情况里 $\lvert P \rvert$ 很大，但注意到如下事实：一个不超过 $V$ 的数至多有一个大于根号 $V$ 的因子。因此大于根号 $V$ 的因子是否出现是“独立”的：要求某个 $p>\sqrt{V}$ 出现需要某个数集 $P \subseteq [n]$ 与选择的数集 $S$ 有交，而另一个 $q > \sqrt{V}$ 出现所限制的集合 $Q$ 一定是和 $P$ 无交的。

因此考虑按照大于根号 $V$ 的因子归类输入的数，并一类一类地加入，进行以上 DP。加入第一类的数时，$P$ 包含所有不超过 $\sqrt{V}$ 的质数，以及当前类对应的唯一的大于 $\sqrt{V}$ 的质因子 $p_1$。第一类数加完之后，$p_1$ 是否出现就已经确定了，因为之后加入的数一定不包含质因子 $p_1$，所以我们可以直接把 $p_1$ 的贡献（即 $p_1$ 出现时的 $\frac{p_1-1}{p_1}$）在此处计算，并把 $p_1$ 从 $P$ 中移除，继续加第二类数。

如此，$\lvert P \rvert$ 被限制在不超过 $\sqrt{V}$ 的质数数量+1。本题范围 $V=3000$，共有 $16$ 个不超过 $\sqrt{V}$ 的质数，如此实现可以通过所有数据。