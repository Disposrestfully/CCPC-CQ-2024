#include <bits/stdc++.h>
#include "testlib.h"
int fa[1 << 20];
int find (int x) {return fa[x] == x ? x : fa[x] = find(fa[x]);}
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 1000000); inf.readEoln();
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i < n; i++) {
		int u = inf.readInt(1, n); inf.readSpace();
		int v = inf.readInt(1, n); inf.readEoln();
		fa[find(v)] = find(u);
	}
	for (int i = 2; i <= n; i++) ensuref(find(1) == find(i), "The input is not a tree.");
	for (int i = 1; i <= n; i++) {
		inf.readInt(0, 1000000000);
		if (i < n) inf.readSpace(); else inf.readEoln();
	}
	inf.readEof();
	return 0;
}