#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int t,a,sum;
int main (int argc,char* argv[]) {
	registerValidation(argc,argv);
	t=inf.readInt(1,1000);
	inf.readChar('\n');
	for (int ii=1;ii<=t;ii++) {
		sum=0;
		for (int i=1;i<=9;i++) {
			a=inf.readInt(0,100);
			inf.readChar(" \n"[i==9]);
			sum+=a;
		}
		ensuref(sum>=1,"sum >= 1\n");
	}
	inf.readEof();
	return 0;
}
