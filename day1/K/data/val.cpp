#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(2, 100000); inf.readEoln();
	std::string s = inf.readToken(); inf.readEoln();
	ensuref((int)s.length() == n, "The length of s is not equal to n.");
	for (char c: s) ensuref(c == 'L' or c == 'R', "The characters int s are not only L and R.");
	inf.readEof();
	return 0;
}