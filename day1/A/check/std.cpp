#include<bits/stdc++.h>
using namespace std;
const int N=3005;
const int S=(1<<16)+5;
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
struct num{
    int val,s;
};
vector<num>a[N];
int tot,all=(1<<16)-1;
int prime[N],p[N];
int id[N],phi[N];
int c[S];
inline void init(){
    p[1]=phi[1]=prime[0]=1;
    for (int i=2;i<N;++i){
        if (!p[i]) prime[id[i]=++tot]=i,phi[i]=i-1;
        for (int j=1;j<=tot && i*prime[j]<N;++j){
            p[i*prime[j]]=1;

            if (i%prime[j]==0){
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    for (int i=0;i<=all;++i){
        c[i]=1;
        for (int j=1;j<=16;++j)
            if (i&(1<<(j-1))){
                c[i]=1ll*c[i]*(prime[j]-1)%Mod;
                c[i]=1ll*c[i]*Pow(prime[j],Mod-2)%Mod;
            }
    }
}   
inline void geta(){
    int x=read();
    assert(x>=1 && x<=3000);
    num now=(num){x,0};
    for (int i=2;i*i<=3000;++i)
        if (x%i==0){
            now.s|=(1<<(id[i]-1));
            while (x%i==0) x/=i;
            //printf("%d ",i);
        }
    //printf("[%d]\n",x);
    now.val/=x;
    a[id[x]].push_back(now);
}
int n,tp;
int dp[2][S][2];
int main(){
    init();
    n=read();
    assert(n>=1 && n<=2000);
    for (int i=1;i<=n;++i)
        geta();
    dp[tp=0][0][0]=1;
    for (int i=0;i<=tot;++i){
        if (a[i].empty()) continue;
        int now=prime[i],fir=max(1,now-1);
        for (int j=0,sz=a[i].size();j<sz;++j){
            tp^=1;
            memset(dp[tp],0,sizeof(dp[tp]));
            for (int k=0;k<=all;++k){
                if (!dp[tp^1][k][0] && !dp[tp^1][k][1])
                    continue;
                int nxt=k|a[i][j].s,nw=nxt^k;
                ad(dp[tp][k][0],dp[tp^1][k][0]);
                ad(dp[tp][k][1],dp[tp^1][k][1]);
                int tmp=1ll*dp[tp^1][k][0]*fir%Mod;
                ad(tmp,1ll*dp[tp^1][k][1]*now%Mod);
                tmp=1ll*tmp*a[i][j].val%Mod;
                tmp=1ll*tmp*c[nw]%Mod;
                ad(dp[tp][nxt][1],tmp);
            }
        }
        tp^=1;
        memset(dp[tp],0,sizeof(dp[tp]));
        for (int k=0;k<=all;++k)
            dp[tp][k][0]=(dp[tp^1][k][0]+dp[tp^1][k][1])%Mod;
    }
    int ans=0;
    for (int k=0;k<=all;++k){
        ad(ans,dp[tp][k][0]);
        ad(ans,dp[tp][k][1]);
    }
    printf("%d\n",ans);
    return 0;
}