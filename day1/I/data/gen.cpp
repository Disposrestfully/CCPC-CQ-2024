#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp;
char s[1000002];
int main(){
	mt19937 rnd(1145141);
	/*
	freopen("2.in","w",stdout);
	t=1000;
	printf("%d\n",t);
	while(t--){
		ans=0;
		while(!ans){
			for(int i=1;i<=9;++i)a[i]=rnd()%101;
			ans=0;
			for(int i=1;i<=9;++i)ans+=a[i];		
		}
		for(int i=1;i<9;++i)printf("%d ",a[i]);printf("%d\n",a[9]);
	}
	*/
	freopen("3.in","w",stdout);
	t=1000;
	printf("%d\n",t);
	for(int ii=1;ii<=9;++ii){
		for(int i=1;i<=9;++i)a[i]=0;
		a[ii]=1;
		for(int i=1;i<9;++i)printf("%d ",a[i]);printf("%d\n",a[9]);
		--t;
	}
	for(int ii=1;ii<=9;++ii)
		for(int jj=ii;jj<=9;++jj){
			for(int i=1;i<=9;++i)a[i]=0;
			++a[ii],++a[jj];
			for(int i=1;i<9;++i)printf("%d ",a[i]);printf("%d\n",a[9]);
			--t;
		}
	while(t--){
		for(int i=1;i<=9;++i)a[i]=0;
		a[1]=3+rnd()%98;
		for(int i=2;i<=9;++i)a[i]=rnd()%max(1,6-i);
		for(int i=1;i<9;++i)printf("%d ",a[i]);printf("%d\n",a[9]);
	}
}



