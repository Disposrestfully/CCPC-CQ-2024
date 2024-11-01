#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
int n;
string a,b,out[7];
int id[7][100005],fa[700005];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
int main(int argc,char **argv){
	registerTestlibCmd(argc,argv);
	int t=inf.readInt();
	for(int l=1;l<=t;++l){
		n=inf.readInt();
		a=inf.readToken();
		b=inf.readToken();
		string p=upperCase(ouf.readToken());
		string j=upperCase(ans.readToken());
		if(p!=j)quitf(_wa,"Testcase %d: output is %s, but jury's answer is %s.",l,p.c_str(),j.c_str());
		if(j=="NO")continue;
		for(int i=0;i<7;++i){
			out[i]=ouf.readToken("[\\.#]{1,100000}","map");
			if(out[i].size()!=n)quitf(_wa,"Testcase %d: incorrect matrix size.", l);
			ans.readToken();
		}
		if(out[0]!=a)quitf(_wa,"Testcase %d: Row 1 doesn't match with a",l);
		if(out[6]!=b)quitf(_wa,"Testcase %d: Row 7 doesn't match with b",l);
		for(int i=0;i<6;++i)for(int j=0;j+1<n;++j){
			int s=0;
			for(int x=0;x<2;++x)for(int y=0;y<2;++y)s+=out[i+x][j+y]=='#';
			if(s==3)quitf(_wa,"Testcase %d: Rectangular condition failed.",l);
		}
		int c=0;
		for(int i=0;i<7;++i)for(int j=0;j<n;++j)if(out[i][j]=='#'){
			id[i][j]=++c;
			fa[c]=c;
		}
		for(int i=0;i<7;++i)for(int j=0;j<n;++j)if(out[i][j]=='#'){
			for(int x=-1;x<=1;++x)for(int y=-1;y<=1;++y)if(i+x>=0 && i+x<7 && j+y>=0 && j+y<n && out[i+x][j+y]=='#'){
				fa[find(id[i][j])]=find(id[i+x][j+y]);
			}
		}
		for(int i=2;i<=c;++i)if(find(i)!=find(1))quitf(_wa,"Testcase %d: Connected condition failed.",l);
	}
	quitf(_ok,"Correct.");
	return 0;
}
