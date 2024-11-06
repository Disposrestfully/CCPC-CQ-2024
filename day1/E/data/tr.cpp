#include <bits/stdc++.h>
signed main () {
	for (int i = 1; i <= 39; i++) {
		std::ifstream fin(std::to_string(i) + ".in");
		int T; fin >> T; std::vector<std::tuple<int, std::vector<int>, std::vector<int>>> data(T);
		for (int i = 0; i < T; i++) {
			auto &[n, l, r] = data[i];
			fin >> n; l = r = std::vector<int>(n);
			for (int i = 0; i < n; i++) fin >> l[i];
			for (int i = 0; i < n; i++) fin >> r[i];
		}
		fin.close();
		std::ofstream fout(std::to_string(i) + ".in");
		fout << T << '\n';
		for (int i = 0; i < T; i++) {
			auto &[n, l, r] = data[i];
			fout << n << '\n';
			for (int i = 0; i < n; i++) fout << l[i] << " \n"[i == n - 1];
			for (int i = 0; i < n; i++) fout << r[i] << " \n"[i == n - 1];
		}
	}
	return 0;
}