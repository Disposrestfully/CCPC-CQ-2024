#include <bits/stdc++.h>
#include "testlib.h"
int fa[1 << 20];
int find (int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 1000); inf.readEoln();
	for (int t = 1; t <= T; t++) {
		int s = 0;
		for (int i = 1; i <= 9; i++) {
			s += inf.readInt(0, 100);
			if (i < 9) inf.readSpace(); else inf.readEoln();
		}
		ensuref(s >= 1, "The sum of ai is less than 1.");
	}
	inf.readEof();
	return 0;
}