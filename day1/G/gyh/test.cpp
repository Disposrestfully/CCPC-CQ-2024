#include<bits/stdc++.h>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[1000002],ans,A,B,R[1000002],stk[1000002],tp,inf=1e9,ax,ay;
char s[1000002];
signed main(){
	t=read();
	while(t--){
		A=read(),B=read();
		re int o=B;
		ax=1e9;
		while(o%2==0)o>>=1;
		while(o%5==0)o/=5;
		for(re int x=B;x<=inf;x*=2)
			for(re int y=x;y<=inf;y*=5){
				re int nx=o-((A*y/B-1)%o+1),ny=y,G=__gcd(nx,ny);nx/=G,ny/=G;
				if(nx<ax)ax=nx,ay=ny;
			}
		printf("%lld %lld\n",ax,ay);
	}
}



