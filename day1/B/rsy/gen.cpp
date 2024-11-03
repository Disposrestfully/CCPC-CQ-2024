#include <bits/stdc++.h>
signed main () {
	std::mt19937 rnd(time(0) ^ getpid());
	int n = 10, k = rnd() % 3 + 1, p = rnd() % 100 + 100;
	std::string s;
	for (int i = 1; i <= n; i++) s += (char)(rnd() % (126 - 33 + 1) + 33);
	std::cout << s << "\n" << k << " " << p << std::endl;
	return 0;
}