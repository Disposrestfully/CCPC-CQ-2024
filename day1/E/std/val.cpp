#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;
int t,n,l[159],r[159];
int main(int argc,char *argv[]){
	registerValidation(argc,argv);
	t = inf.readInt(1,10,"t");
	inf.readEoln();
	while (t --){
		n = inf.readInt(3,150,"n");
		inf.readEoln();
		for (int i = 1;i <= n;i += 1){
			l[i] = inf.readInt(1,1'000'000'000,"l_i");
			inf.readSpace();
		}
		inf.readEoln();
		for (int i = 1;i <= n;i += 1){
			r[i] = inf.readInt(l[i],1'000'000'000,"r_i");
			inf.readSpace();
		}
		inf.readEoln();
	}
	inf.readEof();
	return 0;
}
