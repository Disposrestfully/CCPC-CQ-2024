#include <bits/stdc++.h>
std::string strlist (std::string s) {
	std::string t;
	for (int i = 0; i < (int)s.length(); i++) {
		t += i == 0 ? '[' : ' ';
		t += s[i] == '\'' ? '\"' : '\'';
		t += s[i];
		t += s[i] == '\'' ? '\"' : '\'';
		t += i + 1 == (int)s.length() ? ']' : ',';
	}
	return t;
}
constexpr int mod = 1000000007;
signed main () {
	std::string s; int k, p; std::cin >> s >> k >> p;
	for (int i = 1; i <= k; i++) s = strlist(s);
	for (int i = 0; i < p; i++) {
		int w = 0;
		for (int j = i; j < (int)s.length(); j += p) w = (w + (int)s[j]) % mod;
		std::cout << w << " \n"[i + 1 == p];
	}
	return 0;
}