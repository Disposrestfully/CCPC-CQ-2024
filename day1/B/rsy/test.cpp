#include <bits/stdc++.h>

using namespace std; const int maxn = 1e5 + 5;

typedef long long ll;

const int p=1000000007;

int n,K,m,a[3005][3005],num[3005][3005],c[3005][3005];
char s[100005];

int main()
{
    scanf("%s%d%d",s,&K,&m),n=strlen(s);
    for(int i=0;i<n;++i){
        a[0][i%m]+=s[i];
        if(s[i]=='\'')++num[0][i%m];
        else ++c[0][i%m];
    }
    for(int k=1;k<=K;++k){
        for(int i=0;i<m;++i){
            int x=(i*5+2)%m;
            a[k][x]=(a[k][x]+a[k-1][i])%p;
            num[k][x]=(num[k][x]+num[k-1][i])%p;
            c[k][x]=(c[k][x]+c[k-1][i])%p;
        }
        for(int i=0;i<m;++i){
            int x=(i*5+1)%m,y=(i*5+3)%m;
            a[k][x]=(a[k][x]+num[k-1][i]*34ll+c[k-1][i]*39ll)%p;
            a[k][y]=(a[k][y]+num[k-1][i]*34ll+c[k-1][i]*39ll)%p;
            num[k][x]=(num[k][x]+c[k-1][i])%p;
            num[k][y]=(num[k][y]+c[k-1][i])%p;
            c[k][x]=(c[k][x]+num[k-1][i])%p;
            c[k][y]=(c[k][y]+num[k-1][i])%p;
            x=(i*5)%m,y=(i*5+4)%m;
            a[k][x]=(a[k][x]+num[k-1][i]*32ll+c[k-1][i]*32ll)%p;
            a[k][y]=(a[k][y]+num[k-1][i]*44ll+c[k-1][i]*44ll)%p;
            c[k][x]=(c[k][x]+(ll)num[k-1][i]+c[k-1][i])%p;
            c[k][y]=(c[k][y]+(ll)num[k-1][i]+c[k-1][i])%p;
        }
        n=5ll*n%m;
        a[k][0]=(a[k][0]-32+91)%p;
        a[k][(n+m-1)%m]=(a[k][(n+m-1)%m]-44+93)%p;
    }
    for(int i=0;i<m;++i)printf("%d%c",(a[K][i]+p)%p," \n"[i==m-1]);
    return 0;
}