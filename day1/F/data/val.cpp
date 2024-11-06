#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int T = inf.readInt(1, 10000); inf.readEoln();
	int sumn = 0;
	for (int t = 1; t <= T; t++) {
		int n = inf.readInt(2, 100000); inf.readEoln(); sumn += n;
		std::string a = inf.readToken(); inf.readEoln();
		ensuref((int)a.length() == n, "The length of a is not equal to n.");
		std::string b = inf.readToken(); inf.readEoln();
		ensuref((int)b.length() == n, "The length of b is not equal to n.");
		for (int i = 0; i < n; i++)
			ensuref(a[i] == '.' or a[i] == '#', "There is another type of character in a."),
			ensuref(b[i] == '.' or b[i] == '#', "There is another type of character in b.");
	}
	ensuref(sumn <= 200000, "The sum of n exceeds 200,000.");
	inf.readEof();
	return 0;
}