#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 100000, "T"); inf.readEoln();
	for (int i = 1; i <= T; i++) {
		int n = inf.readInt(1, 1000000000, "n"); inf.readSpace();
		inf.readInt(1, n, "m"); inf.readEoln();
	}
	inf.readEof();
	return 0;
}