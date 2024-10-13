#include <bits/stdc++.h>
constexpr int mod = 998244353;
void inc (int &x, int y) {if ((x += y) >= mod) x -= mod;}
int power (int x, int y) {int z = 1; for (; y; y >>= 1, x = 1LL * x * x % mod) if (y & 1) z = 1LL * z * x % mod; return z;}
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int n; std::string s;
	std::cin >> n >> s;
	std::vector<int> a(n), inv(n + 1, 1), pl(n), pr(n);
	for (int i = 2; i <= n; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 3; i <= n; i++) inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
	for (int i = 0; i < n; i++) pl[i] = pr[i] = 1;
	for (int i = 0; i < n; i++) for (int j = i - 1; ~j; j--) pl[i] = 1LL * pl[i] * (i - j + (s[j] == 'L')) % mod;
	for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++) pr[i] = 1LL * pr[i] * (j - i + (s[j] == 'R')) % mod;
	for (int i = 0; i < n; i++) pl[i] = 1LL * (s[i] == 'L') * inv[i + 1] * pl[i] % mod, pr[i] = 1LL * (s[i] == 'R') * inv[n - i] * pr[i] % mod;
	for (int i = 0, p; i <= n; i++) {
		p = 1LL * (i == 0 ? 1 : pl[i - 1]) * (i == n ? 1 : pr[i]) % mod;
		if (i > 0) inc(a[i - 1], p);
		if (i < n) inc(a[i], p);
	}
	for (int i = 0; i < n; i++) std::cout << a[i] << " \n"[i == n - 1];
	return 0;
}