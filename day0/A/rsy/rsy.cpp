#include <bits/stdc++.h>
constexpr int mod = 998244353;
int power (int x, int y) {int z = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) z = 1LL * z * x % mod; return z;}
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T, n, m; for (std::cin >> T; T--; ) std::cin >> n >> m, std::cout << 1LL * (n - m + 2) * power(2, m - 1) % mod << '\n';
	return 0;
}