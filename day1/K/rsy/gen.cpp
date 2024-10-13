#include <bits/stdc++.h>
signed main () {
	std::mt19937 rnd(time(0)); puts("10");
	for (int i = 0; i < 10; i++) putchar("LR"[rnd() & 1]);
	puts("");
}