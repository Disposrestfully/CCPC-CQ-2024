#include <bits/stdc++.h>
constexpr int mod = 998244353;
int power (int x, int y) {int z = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) z = 1LL * z * x % mod; return z;}
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int n, c = 0; std::string s;
	std::cin >> n >> s;
	std::vector<int> a(n), p(n); std::iota(p.begin(), p.end(), 0);
	do {
		std::vector<int> r(n, 1); c++;
		for (int i: p) if (r[i]) {
			if (s[i] == 'L') for (int j = i - 1; ~j; j--) r[j] = 0;
			if (s[i] == 'R') for (int j = i + 1; j < n; j++) r[j] = 0;
		}
		for (int i = 0; i < n; i++) a[i] += r[i];
	}
	while (std::next_permutation(p.begin(), p.end())) ;
	for (int i = 0, invc = power(c, mod - 2); i < n; i++) a[i] = 1LL * a[i] * invc % mod;
	for (int i = 0; i < n; i++) std::cout << a[i] << " \n"[i == n - 1];
	return 0;
}