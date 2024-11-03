{{ self.title() }}

{{ s('description') }}

osu! 是一款风靡全球的音乐游戏，分为四个模式：osu!，osu!taiko，osu!catch，osu!mania。osu!mania 是一款下落式节奏游戏，像是钢琴模拟器一样。这个模式主要由 woc2006 开发并移植。它基于各种轨道式音乐游戏（例如 劲舞革命 (Dance Dance Revolution) 和 狂热节拍 (Beatmania)）。osu!mania 的吉祥物是一对双胞胎姐妹，Mani 和 Mari，拥有一头紫色或淡紫色的头发。

{{ img('osu!mania.png', size = 0.5, align = 'middle', inline = False, caption='osu!mania 游戏界面') }}

osu!mania 的每一局游戏都有若干个音符（note）组成。玩家游玩过程中，对每个音符的打击都会得到一个判定结果，分为 MAX、300、200、100、50、MISS（0）。记整局游戏中，玩家得到这些判定结果的音符个数分别为 $a, b, c, d, e, f$，则该局游戏的准确率（Accuracy，以下简称 Acc）可以按如下方式计算：

$$\text{Acc} = \frac{300a + 300b + 200c + 100d + 50e + 0f}{300(a + b + c + d + e + f)}$$

玩家每局游戏的准确率将会以百分数的形式展现，并保留两位小数。例如，在下图所示的一局游戏中，玩家的准确率为

$$\text{Acc} = \frac{300 \times 3029 + 300 \times 2336 + 200 \times 377 + 100 \times 41 + 50 \times 10 + 0 \times 61}{300 \times (3029 + 2336 + 377 + 41 + 10 + 61)} \approx 0.96202 \approx 96.20\%。$$

{{ img('acc.png', size = 0.5, align = 'middle', inline = False, caption='Acc 计算示例') }}

除准确率外，osu!mania 中还有另一个重要的衡量单曲游玩成绩的指标——个人表现（Personal Performance，以下简称 pp）。个人表现与谱面星数与判定成绩相关。谱面星数会决定在该铺面可以获得的 pp 上限，记为 $\text{ppmax}$。玩家在一局游戏中获得个人表现可以按如下方式计算（$a, b, c, d, e, f$ 的含义与 Acc 计算方式中相同）：

$$\text{pp} = \max\left(0, \frac{320a + 300b + 200c + 100d + 50e + 0f}{320(a + b + c + d + e + f)} - 80\%\right) \times 5 \times \text{ppmax}$$

例如，在 Acc 计算示例所示的成绩中，若 $\text{ppmax} = 663$，则玩家的个人表现为

$$\text{pp} = \max\left(0, \frac{320 \times 3029 + 300 \times 2336 + 200 \times 377 + 100 \times 41 + 50 \times 10 + 0 \times 61}{320 \times (3029 + 2336 + 377 + 41 + 10 + 61)} - 80\%\right) \times 5 \times 663 \approx 445。$$

**注意：实际计算 pp 时并不会四舍五入或下取整，即计算得到的 pp 可以是任意的非负有理数。**

由于 Acc 与 pp 计算方式不同，同样的 Acc 也可能对应不同的 pp。

给定一个谱面的 pp 上限 $\text{ppmax}$，求在该铺面上获得至少 $1000$ pp 时，可能的展现的准确率的最小值。数据保证在给定的谱面上能获得至少 $1000$ pp。

{{ s('input format') }}

{{ self.input_file() }}

输入共一行，包含一个正整数 $\text{ppmax}$，保证 $1000 \le \text{ppmax} \le 3000$。

{{ s('output format') }}

{{ self.output_file() }}

输出一行一个百分数表示准确率的最小值，要求按照游戏展现的形式（即保留两位小数的百分数形式）输出。

{{ s('sample', 1) }}

{{ self.sample_text() }}

上面是自动读入样例 `1.in/ans`（存储在 `down` 文件夹内） 然后渲染到题面中；如果只有一组样例，则去掉 `1` 或将其替换成空串，样例仍然保存成 `1.in/ans`。上面的 `1` 可以是字符串。

{{ self.title_sample_description() }}

这是第一组数据的样例说明。

{{ s('sample', 2) }}

{{ self.sample_file() }}

上面是只提示存在第二组样例，但不渲染到题面中。
