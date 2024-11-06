#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 10); inf.readEoln();
	for (int t = 1; t <= T; t++) {
		int n = inf.readInt(3, 150); inf.readEoln();
		std::vector<int> l(n + 1);
		for (int i = 1; i <= n; i++) {
			l[i] = inf.readInt(1, 1000000000);
			if (i < n) inf.readSpace(); else inf.readEoln();
		}
		for (int i = 1; i <= n; i++) {
			inf.readInt(l[i], 1000000000);
			if (i < n) inf.readSpace(); else inf.readEoln();
		}
	}
	inf.readEof();
	return 0;
}