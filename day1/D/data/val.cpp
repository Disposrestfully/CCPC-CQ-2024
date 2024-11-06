#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 100000); inf.readSpace();
	int m = inf.readInt(0, 100000); inf.readEoln();
	for (int i = 1; i <= n; i++) {
		inf.readInt(1, n);
		if (i < n) inf.readSpace(); else inf.readEoln();
	}
	std::set<std::pair<int, int>> s;
	for (int i = 1; i <= m; i++) {
		int x = inf.readInt(1, n); inf.readSpace();
		int y = inf.readInt(1, n); inf.readEoln();
		ensuref(x != y, "There is a self-loop.");
		ensuref(!s.count(std::make_pair(x, y)) and !s.count(std::make_pair(y, x)), "There are duplicate edges.");
		s.insert(std::make_pair(x, y));
	}
	inf.readEof();
	return 0;
}