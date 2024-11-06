#include <bits/stdc++.h>
signed main () {
	std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
	int T; for (std::cin >> T; T--; ) {
		int ppmax, a, b, c, d, e, f;
		std::cin >> ppmax >> a >> b >> c >> d >> e >> f;
		double facc = 1.0 * (300 * (a + b) + 200 * c + 100 * d + 50 * e) / (300 * (a + b + c + d + e + f));
		double pp = std::max(ppmax * 5.0 * (320 * a + 300 * b + 200 * c + 100 * d + 50 * e) / 320 / (a + b + c + d + e + f) - ppmax * 4.0, 0.0);
		std::cout << std::fixed << std::setprecision(2) << facc * 100 << "\% " << (int)round(pp) << '\n';
	}
	return 0;
}