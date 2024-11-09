#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
const int mod=998244353;
typedef long long ll;
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

void add(int &x,int y){x=(x+y>=mod)?(x+y-mod):x+y;}
int qpow(int x,int y){int ret=1;while(y){if(y&1)ret=1ll*ret*x%mod;x=1ll*x*x%mod;y>>=1;}return ret;}
mt19937_64 rnd(time(0));
const int p=1e9;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    freopen("../data/1.in","w",stdout);
    int _=1e5;
    printf("%d\n",_);
    rep(i,1,_){
        int n=rnd()%p+1;
        int m=rnd()%n+1;
        printf("%d %d\n",n,m);
    }
	return 0;
}