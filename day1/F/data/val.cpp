#include "testlib.h"
using namespace std;
int main(int argc,char **argv){
	registerValidation();
	int T=inf.readInt(1,10000,"T");	inf.readEoln();
	int cn=0;
	for(;T;--T){
		int n=inf.readInt(1,100000,"n");
		cn+=n;
		inf.readEoln();
		ensuref(cn<=200000,"sum of n should <= 200000");
		string s1=inf.readToken("[\\.#]{1,100000}","s1");
		ensuref(s1.length()==n,"length of s1 should be n");
		bool ok=0;
		for(int i=0;i<n;++i)if(s1[i]=='#')ok=1;
		ensuref(ok,"s1 should contain at least one '#'");
		inf.readEoln();
		string s2=inf.readToken("[\\.#]{1,100000}","s2");
		ensuref(s2.length()==n,"length of s2 should be n");
		ok=0;
		for(int i=0;i<n;++i)if(s2[i]=='#')ok=1;
		ensuref(ok,"s2 should contain at least one '#'");
		inf.readEoln();
	}
	inf.readEof();
	printf("Validation passed\n");
	return 0;
}
