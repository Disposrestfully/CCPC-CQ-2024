{{ self.title() }}

{{ s('description') }}

osu! 是一款风靡全球的音乐游戏，分为四个模式：osu!，osu!taiko，osu!catch，osu!mania。osu!mania 是一款下落式节奏游戏，像是钢琴模拟器一样。这个模式主要由 woc2006 开发并移植。它基于各种轨道式音乐游戏（例如 劲舞革命 (Dance Dance Revolution) 和 狂热节拍 (Beatmania)）。

{{ img('osu!mania.png', size = 0.5, align = 'middle', inline = False, caption='osu!mania 游戏界面') }}

osu!mania 的每一局游戏都有若干个音符（note）组成。玩家游玩过程中，对每个音符的打击都会得到一个判定结果，分为 MAX、300、200、100、50、MISS（0）。记整局游戏中，玩家得到这些判定结果的音符个数分别为 $a, b, c, d, e, f$，则该局游戏的准确率（Accuracy，以下简称 Acc）可以按如下方式计算：

$$\text{Acc} = \frac{300a + 300b + 200c + 100d + 50e + 0f}{300(a + b + c + d + e + f)} \times 100\%。$$

由于准确率可能为无限小数，游戏中将会显示其四舍五入的结果。具体地，玩家每局游戏的准确率将会被四舍五入，并保留百分数形式下的两位小数，即精确到 $10 ^ {-4}$。例如，在下图所示的一局游戏中，玩家的准确率为

$$\text{Acc} = \frac{300 \times 3029 + 300 \times 2336 + 200 \times 377 + 100 \times 41 + 50 \times 10 + 0 \times 61}{300 \times (3029 + 2336 + 377 + 41 + 10 + 61)} \approx 0.9620 = 96.20\%。$$

{{ img('acc.png', size = 0.5, align = 'middle', inline = False, caption='Acc 计算示例') }}

除准确率外，osu!mania 中还有另一个重要的衡量单曲游玩成绩的指标——个人表现（Personal Performance，以下简称 pp）。个人表现与谱面星数与判定成绩相关。谱面星数会决定在该铺面可以获得的 pp 上限，记为 $\text{ppmax}$。玩家在一局游戏中获得个人表现可以按如下方式计算（$a, b, c, d, e, f$ 的含义与 Acc 计算方式中相同）：

$$\text{pp} = \max\left(0, \frac{320a + 300b + 200c + 100d + 50e + 0f}{320(a + b + c + d + e + f)} - 80\%\right) \times 5 \times \text{ppmax}$$

玩家每局游戏的个人表现将会被四舍五入到最接近的整数。例如，在 Acc 计算示例所示的成绩中，若 $\text{ppmax} = 663$，则玩家的个人表现为

$$\text{pp} = \max\left(0, \frac{320 \times 3029 + 300 \times 2336 + 200 \times 377 + 100 \times 41 + 50 \times 10 + 0 \times 61}{320 \times (3029 + 2336 + 377 + 41 + 10 + 61)} - 80\%\right) \times 5 \times 663 \approx 445。$$

给定一个谱面的 pp 上限 $\text{ppmax}$ 与玩家在该谱面上的一局游戏的判定结果 $a, b, c, d, e, f$。求玩家该局游戏的准确率与个人表现。

{{ s('input format') }}

{{ self.input_file() }}

**本题包含多组测试数据。**

输入的第一行包含一个正整数 $T$，表示数据组数。保证 $1 \le T \le 100$。

对于每组测试数据：

输入的第一行包含一个非负整数 $\text{ppmax}$。保证 $0 \le \text{ppmax} \le 3000$。

输入的第二行包含六个非负整数 $a, b, c, d, e, f$，含义如题目描述所示。保证 $0 \le a, b, c, d, e, f \le 2 \times 10 ^ 4$。

{{ s('output format') }}

{{ self.output_file() }}

对于每组测试数据：输出一行两个数，以空格隔开。其中第一个数表示准确率，以百分数形式输出，精确到 $10 ^ {-4}$；第二个数为个人表现，以整数形式输出。

{{ s('sample', 1) }}

{{ self.sample_text() }}
