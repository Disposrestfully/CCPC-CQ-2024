#include <bits/stdc++.h>
constexpr int mod = 1000000007;
void inc (int &x, int y) {if ((x += y) >= mod) x -= mod;}
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	std::vector<int> inv(200, 1);
	for (int i = 2; i < 200; i++) inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
	for (int i = 3; i < 200; i++) inv[i] = 1LL * inv[i - 1] * inv[i] % mod;
	int T; for (std::cin >> T; T--; ) {
		int n, ans = 0; std::cin >> n; std::vector<int> L(n + 1), R(n + 1), w(1, 1);
		for (int i = 1; i <= n; i++) std::cin >> L[i], w.emplace_back(L[i]);
		for (int i = 1; i <= n; i++) std::cin >> R[i], w.emplace_back(++R[i]);
		std::sort(w.begin(), w.end()); w.resize(std::unique(w.begin(), w.end()) - w.begin());
		auto calc = [&] (int x) {
			std::vector<int> f(4); f[0] = 1;
			for (int i = 1; i <= n; i++) {
				std::vector<int> g(4); std::swap(f, g);
				int w0 = L[i] < x ? std::min(R[i], x) - L[i] : 0;
				int w1 = R[i] > x ? R[i] - std::max(L[i], x) : 0;
				f[0] = (1LL * g[0] * w0 + 1LL * g[2] * w0) % mod;
				f[1] = 1LL * g[0] * w1 % mod; f[2] = 1LL * g[1] * w0 % mod;
				f[3] = (1LL * g[1] * w1 + 1LL * g[2] * w1 + 1LL * g[3] * (w0 + w1)) % mod;
			}
			return f[3];
		};
		for (int i = 0; i + 1 < (int)w.size(); i++)
			if (w[i + 1] - w[i] < n + 2) for (int j = w[i]; j < w[i + 1]; j++) inc(ans, calc(j));
			else {
				std::vector<int> pre(n + 4, 1), suf(n + 4, 1);
				for (int j = 1; j <= n + 2; j++) pre[j] = 1LL * pre[j - 1] * (w[i + 1] - w[i] - j) % mod;
				for (int j = n + 2; j >= 1; j--) suf[j] = 1LL * suf[j + 1] * (w[i + 1] - w[i] - j) % mod;
				for (int j = 1, y = 0, r; j <= n + 2; j++)
					inc(y, calc(w[i] + j - 1)),
					r = 1LL * y * pre[j - 1] % mod * suf[j + 1] % mod * inv[j - 1] % mod * inv[n + 2 - j] % mod,
					inc(ans, (n - j) & 1 ? mod - r : r);
			}
		std::cout << ans << std::endl;
	}
	return 0;
}