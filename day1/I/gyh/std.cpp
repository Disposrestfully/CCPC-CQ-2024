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
int a[11],t;
int main(){
	t=read();
	while(t--){
		for(int i=1;i<=9;++i)a[i]=read();a[10]=0;
		while(a[1]&&a[2])--a[1],--a[2],++a[3];
		while(a[1]>=3)a[1]-=3,++a[3];
		if(a[1]==2)++a[2],a[1]-=2;
		if(a[1]){
			for(int i=2;i<=9;++i)if(a[i]){--a[i],++a[i+1];break;}
		}
		int ans=1;
		for(int i=2;i<=10;++i)
			for(int j=1;j<=a[i];++j)
				ans=1ll*i*ans%M;
		printf("%d\n",ans);
	}
}



