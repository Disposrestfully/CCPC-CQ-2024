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
void exgcd(int a,int b,int &x,int &y){
	if(!b)x=1,y=0;
	else{
		exgcd(b,a%b,x,y);
		int t=x;x=y;
		y=t-a/b*y;
	}
}
inline int Gcd(re int x,re int y){
	return y?Gcd(y,x%y):x;
}
int t,A,B,inf=1e9,ax,ay;
signed main(){
	t=read();
	while(t--){
		A=read(),B=read();
		re int o=B;
		ax=1e9;
		while(o%2==0)o>>=1;
		while(o%5==0)o/=5;
		if(o==1){
			puts("0 1");
			continue;
		}
		for(re int x=o;x<=inf;x*=2)
			for(re int y=x;y<=inf;y*=5){
				int L=y/Gcd(y,B)*B,ov=L/B*A%o,v=L/y%o,a,b,tmp=Gcd(v,o);
				ov=o-ov;if(!v)continue;
				exgcd(v,o,a,b);
				a*=ov;
				a%=(o/tmp),a+=o/tmp,a%=o/tmp;
				if(a<ax)ax=a,ay=y;
			}
		printf("%lld %lld\n",ax,ay);
	}
}



