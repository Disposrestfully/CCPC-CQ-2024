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
void solve(){
    int n,m;
    cin>>n>>m;
    assert(n>=1 && n<=1000000000);
    assert(m>=1 && m<=n);
    int ans=1ll*(n-m+2)*qpow(2,m-1)%mod;
    printf("%d\n",ans);
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
    int _;cin>>_;
    assert(_>=1 && _<=100000);
    while(_--)solve();
	return 0;
}
