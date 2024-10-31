#include"testlib.h"
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e6, MAXV = 1e9; int fa[MAXN + 7];
int find(int x){return fa[x] == x ? x : (fa[x] = find(fa[x]));}

int main(int argc, char **argv){
	assert(argc == 1);
	registerValidation();
	int n = inf.readInt(1, MAXN); inf.readEoln();
	for(int i = 1 ; i <= n ; ++i) fa[i] = i;
	for(int i = 1 ; i < n ; ++i){
		int x = inf.readInt(1, n); inf.readSpace();
		int y = inf.readInt(1, n); inf.readEoln();
		ensuref(find(x) != find(y), "The input is not a tree.");
		fa[find(x)] = find(y);
	}
	for(int i = 1 ; i <= n ; ++i){
		inf.readInt(0, MAXV);
		if(i != n) inf.readSpace();
		else inf.readEoln();
	}
	inf.readEof();
}