#include<bits/stdc++.h>
using namespace std;

const int prm[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53} , P = 998244353;
int poww(long long a , int b){
	int tms = 1; while(b){if(b & 1) tms = tms * a % P; a = a * a % P; b >>= 1;} return tms;
}
int N , bitmask[3003]; map < int , vector < int > > pot;
int dp[2][1 << 16];

int main(){
	cin >> N;
	for(int i = 1 ; i <= 3000 ; ++i)
		for(int j = 0 ; j < 16 ; ++j)
			if(i % prm[j] == 0) bitmask[i] |= 1 << j;
	for(int i = 1 ; i <= N ; ++i){
		int a; cin >> a; int tmp = a;
		for(int j = 0 ; j < 16 ; ++j)
			while(tmp % prm[j] == 0) tmp /= prm[j];
		pot[tmp].push_back(a);
	}
	dp[0][0] = 1;
	for(auto t : pot){
		for(auto p : t.second)
			for(int j = (1 << 16) - 1, val = bitmask[p] ; ~j ; --j)
				dp[1][j | val] = (dp[1][j | val] + 1ll * (dp[0][j] + dp[1][j]) * p) % P;
		int w = t.first == 1 ? 1ll : 1ll * poww(t.first , P - 2) * (t.first - 1) % P;
		for(int j = 0 ; j < 1 << 16 ; ++j){
			dp[0][j] = (dp[0][j] + 1ll * w * dp[1][j]) % P; dp[1][j] = 0;
		}
	}
	int ans = 0;
	for(int i = 0 ; i < 1 << 16 ; ++i){
		int tms = dp[0][i];
		for(int j = 0 ; j < 16 ; ++j)
			if(i >> j & 1) tms = 1ll * tms * poww(prm[j] , P - 2) % P * (prm[j] - 1) % P;
		ans = (ans + tms) % P;
	}
	cout << ans;
	return 0;
}