#include <bits/stdc++.h>
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; for (std::cin >> T; T--; ) {
		int ppmax, a, b, c, d, e, f;
		std::cin >> ppmax >> a >> b >> c >> d >> e >> f;
		int acc = (10000LL * (300 * (a + b) + 200 * c + 100 * d + 50 * e) + 150 * (a + b + c + d + e + f)) / (300 * (a + b + c + d + e + f));
		int pp = (1LL * ppmax * std::max(5 * (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) - 4 * 320 * (a + b + c + d + e + f), 0) + 160 * (a + b + c + d + e + f)) / (320 * (a + b + c + d + e + f));
		int u = (320 * a + 300 * b + 200 * c + 100 * d + 50 * e), v = 320 * (a + b + c + d + e + f), g = std::gcd(u, v);
		u /= g; v /= g; std::cerr << u << " " << v << std::endl;
		std::cout << acc / 100 << '.' << acc / 10 % 10 << acc % 10 << "\% " << pp << '\n';
	}
	return 0;
}