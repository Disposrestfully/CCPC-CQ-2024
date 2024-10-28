#include <bits/stdc++.h>
constexpr int mod = 1000000007;
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; for (std::cin >> T; T--; ) {
		int n, ans = 0; std::cin >> n; std::vector<int> L(n), R(n), w(n);
		for (int i = 0; i < n; i++) std::cin >> L[i];
		for (int i = 0; i < n; i++) std::cin >> R[i];
		std::function<void (int)> dfs = [&] (int u) {
			if (u == n) {
				int res = 0;
				for (int i = 0; i + 1 < n; i++) res = std::max(res, std::min(w[i], w[i + 1]));
				for (int i = 0; i + 2 < n; i++) res = std::max(res, std::min(w[i], w[i + 2]));
				ans = (ans + res) % mod;
				return;
			}
			for (w[u] = L[u]; w[u] <= R[u]; w[u]++) dfs(u + 1);
		};
		dfs(0); std::cout << ans << std::endl;
	}
	return 0;
}