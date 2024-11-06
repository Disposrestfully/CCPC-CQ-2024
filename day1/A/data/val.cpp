#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 2000); inf.readEoln();
	for (int i = 1; i <= n; i++) {
		inf.readInt(1, 3000);
		if (i < n) inf.readSpace(); else inf.readEoln();
	}
	inf.readEof();
	return 0;
}