#include <bits/stdc++.h>
constexpr int mod = 1000000007;
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; for (std::cin >> T; T--; ) {
		int n, ans = 0; std::cin >> n; std::vector<int> L(n + 1), R(n + 1), w(1, 1);
		for (int i = 1; i <= n; i++) std::cin >> L[i], w.emplace_back(L[i]);
		for (int i = 1; i <= n; i++) std::cin >> R[i], w.emplace_back(++R[i]);
		std::sort(w.begin(), w.end()); w.resize(std::unique(w.begin(), w.end()) - w.begin());
		auto calc = [&] (int x) {
			/*
				0: end with 0
				1: end with 1
				2: end with 10
				3: found 11 or 101
			*/
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
		for (int i = 0; i + 1 < (int)w.size(); i++) {
			for (int j = w[i]; j < w[i + 1]; j++) ans = (ans + calc(j)) % mod;
		}
		std::cout << ans << std::endl;
	}
	return 0;
}