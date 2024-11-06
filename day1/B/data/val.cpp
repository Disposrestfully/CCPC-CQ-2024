#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	std::string s = inf.readToken(); inf.readEoln();
	ensuref(1 <= (int)s.length() and (int)s.length() <= 100000, "Length of s is invalid.");
	for (char c: s) ensuref(33 <= (int)c and (int)c <= 126, "Character of s is invalid.");
	int k = inf.readInt(1, 3000); inf.readSpace();
	int p = inf.readInt(1, 3000); inf.readEoln();
	inf.readEof();
	return 0;
}