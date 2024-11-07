#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
int n,q,x,y;
int main (int argc,char* argv[]) {
	registerValidation(argc,argv);
	n=inf.readInt(1,500000);
	inf.readSpace();
	q=inf.readInt(1,500000);
	//inf.readEoln();
	inf.readChar('\n');
	for (int i=1;i<=n;i++) {
		x=inf.readInt(0,1);
		inf.readSpace();
		//if (i==n) {inf.readEoln();}
		if (i==n) {inf.readChar('\n');}
	}
	for (int i=1;i<=n;i++) {
		x=inf.readInt(1,n);
		inf.readSpace();
		//if (i==n) {inf.readEoln();}
		if (i==n) {inf.readChar('\n');}
	}
	for (int i=1;i<=q;i++) {
		x=inf.readInt(1,n);
		inf.readSpace();
		y=inf.readInt(x,n);
		//inf.readEoln();
		inf.readChar('\n');
	}
	inf.readEof();
	return 0;
}
