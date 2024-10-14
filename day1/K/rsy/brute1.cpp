#include <bits/stdc++.h>
constexpr int mod = 998244353;
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int n; std::string s;
	std::cin >> n >> s;
	std::vector<int> a(n), p(n); std::iota(p.begin(), p.end(), 0);
	do {
		std::vector<int> r(n, 1);
		for (int i: p) if (r[i]) {
			if (s[i] == 'L') for (int j = i - 1; ~j; j--) r[j] = 0;
			if (s[i] == 'R') for (int j = i + 1; j < n; j++) r[j] = 0;
		}
		for (int i = 0; i < n; i++) a[i] += r[i];
	}
	while (std::next_permutation(p.begin(), p.end())) ;
	for (int i = 0; i < n; i++) std::cout << a[i] << " \n"[i == n - 1];
	return 0;
}
