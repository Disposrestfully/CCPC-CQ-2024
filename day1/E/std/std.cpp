#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll t,n,ans,tot,a[159],b[159],tmp[309],f[159][3];
inline ll read(){
	ll s = 0,w = 1;
	char ch = getchar();
	while (ch > '9' || ch < '0'){ if (ch == '-') w = -1; ch = getchar();}
	while (ch <= '9' && ch >= '0') s = (s << 1) + (s << 3) + (ch ^ 48),ch = getchar();
	return s * w;
}
inline void add(ll &x,ll y){x += y; if (x >= mod) x -= mod;}
ll qp(ll x,ll y){
	ll a = 1,b = x;
	while (y){
		if (y & 1) a = a * b % mod;
		b = b * b % mod,y >>= 1;
	}
	return a;
}
ll calc(ll x){
	f[0][0] = 1;
	for (ll i = 1;i <= n;i += 1){
		if (x > a[i]) f[i][0] = (f[i - 1][0] + f[i - 1][1]) * (min(b[i],x - 1) - a[i] + 1) % mod;
		else f[i][0] = 0;
		if (x > a[i]) f[i][1] = f[i - 1][2] * (min(b[i],x - 1) - a[i] + 1) % mod;
		else f[i][1] = 0;
		if (b[i] >= x) f[i][2] = f[i - 1][0] * (b[i] - max(a[i],x) + 1) % mod;
		else f[i][2] = 0;
	}
	return (tot - f[n][0] - f[n][1] - f[n][2] + 3 * mod) % mod;
}
ll work(ll l,ll r){
	ll res = 0,cur = 0;
	if (r - l + 1 <= n + 2){
		for (ll i = l;i <= r;i += 1) add(res,calc(i));
		return res;
	}
	for (ll i = l;i <= l + n + 1;i += 1){
		ll coef1 = 1,coef2 = 1;
		for (ll j = l;j <= l + n + 1;j += 1){
			if (i == j) continue;
			coef1 = coef1 * (r - j + mod) % mod;
			coef2 = coef2 * (i - j + mod) % mod;
		}
		add(cur,calc(i));
		add(res,coef1 * qp(coef2,mod - 2) % mod * cur % mod);
	}
	return res;
}
int main(){
	t = read();
	while (t --){
		n = read(),ans = 0,tot = 1;
		for (ll i = 1;i <= n;i += 1) a[i] = tmp[i] = read();
		for (ll i = 1;i <= n;i += 1) b[i] = tmp[i + n] = read();
		for (ll i = 1;i <= n;i += 1) tot = tot * (b[i] - a[i] + 1) % mod;
		sort(tmp + 1,tmp + 2 * n + 1);
		for (ll i = 1;i <= 2 * n;i += 1) add(ans,work(tmp[i - 1] + 1,tmp[i]));
		printf("%lld\n",ans);
	}
	return 0;
}
