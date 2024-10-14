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
int n,W[502][502],C[502][502],lst[502][2],nxt[502][2],inv[502],fac[502],f[502][502];
char s[502];
int main(){
	n=read();
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	for(re int i=C[0][0]=1;i<=n;++i)
		for(re int j=C[i][0]=1;j<=i;++j)
			C[i][j]=Mod(C[i-1][j-1]+C[i-1][j]);
	scanf("%s",s+1);
	for(re int i=1;i<=n;++i){
		lst[i][0]=lst[i-1][0];
		lst[i][1]=lst[i-1][1];
		lst[i][s[i]=='R']=i;
	}
	nxt[n+1][0]=nxt[n+1][1]=n+1;
	for(re int i=n;i;--i){
		nxt[i][0]=nxt[i+1][0];
		nxt[i][1]=nxt[i+1][1];
		nxt[i][s[i]=='R']=i;
	}
	for(re int l=1;l<=n;++l){
		for(re int r=l;r<=n;++r){
			for(re int k=l;k<=r;++k){
				if(k==l&&k!=1&&s[k]=='L')continue;
				if(k==r&&k!=n&&s[k]=='R')continue;
				re int L=0,R=0;
				if(s[k]=='L'){
					if(nxt[k][1]<=r)continue;
					R=r-k;
					if(k>1&&lst[k-2][0]>=l)continue;
					L=max(0,k-1-l);
				}
				if(s[k]=='R'){
					if(k<n&&nxt[k+2][1]<=r)continue;
					R=max(0,r-k-1);
					if(lst[k][0]>=l)continue;
					L=k-l;
				}
				if((k==1&&s[k]=='L')||(k==n&&s[k]=='R'))add(W[l][r],C[L+R][L]);
				else add(W[l][r],1ll*(r-l)*C[L+R][L]%M);
			}
		//	printf("%d %d %d\n",l,r,W[l][r]);
			W[l][r]=1ll*W[l][r]*inv[r-l+1]%M;
		}
	}
	f[0][0]=fac[n];
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=i;++j)
			for(re int k=1;k<=i;++k)
				add(f[i][j],1ll*f[k-1][j-1]*W[k][i]%M);
	for(re int i=1;i<n;++i)printf("%d ",f[n][i]);printf("%d\n",f[n][n]); 
	
}



