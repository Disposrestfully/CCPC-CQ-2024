#include <bits/stdc++.h>
#include "testlib.h"
signed main (int argc, char *argv[]) {
	registerValidation(argc, argv);
	int n = inf.readInt(1, 100000); inf.readEoln();
	std::string s = inf.readToken(); inf.readEoln();
	ensuref((int)s.length() == n, "The length of input string is not equal to n.");
	for (char c: s) ensuref(c == '0' or c == '1' or c == '2', "The string is not a ternary number.");
	s = inf.readToken(); inf.readEoln();
	ensuref((int)s.length() == n, "The length of input string is not equal to n.");
	for (char c: s) ensuref(c == '0' or c == '1' or c == '2', "The string is not a ternary number.");
	inf.readEof();
	return 0;
}