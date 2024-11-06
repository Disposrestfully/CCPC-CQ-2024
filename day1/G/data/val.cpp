#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 10000); inf.readEoln();
	for (int t = 1; t <= T; t++) {
		int a = inf.readInt(1, 1000000); inf.readSpace();
		int b = inf.readInt(1, 1000000); inf.readEoln();
		ensuref(std::gcd(a, b) == 1, "gcd(a, b) is not equal to 1.");
	}
	inf.readEof();
	return 0;
}