#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,p[12],dead[12],ans[12];
char s[12];
int main(){
	n=read();
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i)p[i]=i;
	do{
		for(re int i=1;i<=n;++i)dead[i]=0;
		for(re int i=1;i<=n;++i){
			re int x=p[i];
			if(dead[x])continue;
			if(s[x]=='L'){
				re int z=x-1;
				while(z&&dead[z])--z;
				dead[z]=1;
			}
			if(s[x]=='R'){
				re int z=x+1;
				while(z<=n&&dead[z])++z;
				dead[z]=1;
			}
		}
		re int s=0;
		for(re int i=1;i<=n;++i)s+=!dead[i];
		++ans[s];
	}while(next_permutation(p+1,p+n+1));
	for(re int i=1;i<n;++i)printf("%d ",ans[i]);printf("%d\n",ans[n]); 
}



