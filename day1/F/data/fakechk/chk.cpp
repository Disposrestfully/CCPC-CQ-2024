#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;
#define int long 
string a,b;
int n;
const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};
int check(InStream &in,int test){
	string s=in.readToken();
	for(auto &it:s){
		if('a'<=it and it<='z')it-=32;
	}
	if(s!="YES" and s!="NO")in.quitf(_wa,"expected YES or NO, found %s",s.c_str());
	if(s=="NO"){
		return 0;
	}
	string res[10];
	int cnt=0;
	for(int i=1;i<=7;i++){
		res[i]=in.readToken();
		if(res[i].length()!=n)in.quitf(_wa,"Incorrect matrix size.(testcase %d)",test);
		for(auto it:res[i]){
			if(!(it=='.' or it=='#'))in.quitf(_wa,"Invalid character: found %c. (testcase %d)",it,test);
			if(it=='#'){
				cnt++;
			}
		}
	}
	if(res[1]!=a)in.quitf(_wa,"Row 1 does not match with a.(testcase %d)",test);
	if(res[7]!=b)in.quitf(_wa,"Row 7 does not match with b.(testcase %d)",test);
	for(int i=1;i<=6;i++){
		for(int j=0;j<n-1;j++){
			int c=0;
			for(int k=0;k<=3;k++)if(res[i+k/2][j+k%2]=='#')c++;
			if(c==3){
				in.quitf(_wa,"Condition failed: rectangular.(testcase %d)",test);
			}
		}
	}
	for(int i=1;i<=7;i++){
		for(int j=0;j<n-1;j++){
			if(res[i][j]=='#'){
				queue<pair<int,int>>q;
				q.push({i,j});
				res[x][y]='.';
				cnt--;
				while(!q.empty()){
					int x=q.front().first,y=q.front().second;
					for(int k=0;k<8;k++){
						int px=x+dx[k],py=y+dy[k];
						if(px>=0 and px<=6 and py>=0 and py<n and res[px][py]=='#'){
							q.push({px,py});
							cnt--;
							res[px][py]='.';
						}
					}
				}
				if(cnt)in.quitf(_wa,"Condition failed: connected.(testcase %i)",test);
			}
		}
	}
	return 1;
}
signed main(signed argc,char** argv){
	registerTestlibCmd(argc,argv);
	int t=inf.readInt();
	for(int i=1;i<=t;i++){
		n=inf.readInt();
		a=inf.readToken();
		b=inf.readToken();
	   	int j=check(ans);
	   	int p=check(ouf);
	   	if(j<p)quitf(_fail,"Answer should exists.(testcase %d)",i);
	   	if(j>p)quitf(_wa,"Answer exists but not found.(testcases %d)",i);
	}
	quitf(_ok,"Nice.");
}
