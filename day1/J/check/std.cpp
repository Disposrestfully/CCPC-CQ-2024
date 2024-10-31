#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int Mod=998244353;
inline int read(){
    int x=0,w=1;
    char ch=0;
    while (ch<'0' || ch>'9'){
        ch=getchar();
        if (ch=='-') w=-1;
    }
    while (ch<='9' && ch>='0'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*w;
}
inline int Pow(int x,int y){
    int res=1;
    while (y){
        if (y&1) res=1ll*res*x%Mod;
        x=1ll*x*x%Mod;
        y>>=1;
    }
    return res;
}
inline void ad(int &x,int y){
    x+=y;
    if (x>=Mod) x-=Mod;
}
int n;
int fac[N],inv[N],c[N][N];
int cnt[N],f[N][N],g[N][N];
char s[N];
inline void init(){
    n=read();
    fac[0]=inv[0]=1;
    for (int i=1;i<=n;++i){
        fac[i]=1ll*fac[i-1]*i%Mod;
        inv[i]=Pow(fac[i],Mod-2);
    }
    for (int i=0;i<=n;++i)
        c[i][0]=1;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=i;++j)
            c[i][j]=(c[i-1][j]+c[i-1][j-1])%Mod;
}
int main(){
    init();
    scanf("%s",s+1);
    for (int i=1;i<=n;++i)
        cnt[i]=cnt[i-1]+(s[i]=='R');
    cnt[n+1]=cnt[n+2]=cnt[n];
    for (int l=1;l<=n;++l)
        for (int r=l;r<=n;++r){
            for (int k=l;k<=r;++k){
                if (k==l && s[k]=='L' && k!=1) continue;
                if (k==r && s[k]=='R' && k!=n) continue;
                int L,R;
                if (s[k]=='L'){
                    if (cnt[k-1]!=cnt[r]) continue;
                    if (k!=1 && cnt[k-2]-cnt[l-1]!=k-l-1) continue;
                    R=r-k,L=max(0,k-1-l);
                }else{
                    if (k!=n && cnt[k+1]!=cnt[r]) continue;
                    if (cnt[k]-cnt[l-1]!=k-l+1) continue;
                    L=k-l,R=max(0,r-k-1);
                }
                //printf("%d %d %d %d %d %d\n",l,r,L,R,r-l,c[L+R][L]);               
                if (k==1 && s[k]=='L') ad(f[l][r],c[L+R][R]);
                else if (k==n && s[k]=='R') ad(f[l][r],c[L+R][L]);
                else ad(f[l][r],1ll*(r-l)*c[L+R][L]%Mod);
            }
            f[l][r]=1ll*f[l][r]*inv[r-l+1]%Mod;
            //printf("%d %d %d\n",l,r,f[l][r]);
        }
    g[0][0]=fac[n];
    for (int i=1;i<=n;++i) 
        for (int j=1;j<=i;++j)
            for (int k=0;k<i;++k)
                ad(g[i][j],1ll*g[k][j-1]*f[k+1][i]%Mod);
    for (int i=1;i<=n;++i)
        printf("%d%c",g[n][i],(i==n)?'\n':' ');
    return 0;
}