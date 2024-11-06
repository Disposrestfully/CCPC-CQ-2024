#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 100); inf.readEoln();
	for (int t = 1; t <= T; t++) {
		inf.readInt(0, 3000); inf.readEoln();
		int s = 0;
		for (int i = 1; i <= 6; i++) {
			s += inf.readInt(0, 20000);
			if (i < 6) inf.readSpace(); else inf.readEoln();
		}
		ensuref(s >= 1, "a + b + c + d + e + f is less than 1.");
	}
	inf.readEof();
	return 0;
}