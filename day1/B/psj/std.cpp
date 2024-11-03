#include<bits/stdc++.h>
using namespace std;

const int P = 1e9 + 7, _ = 3003;
string str; int k, p, f[_][_], g[_][_], h[_][_];
void inc(int &x, long long y){x = (x + y) % P;}

int main(){
	cin >> str >> k >> p;
	for(int i = 0 ; i < str.size() ; ++i){f[0][i % p] += str[i]; g[0][i % p] += (str[i] == '\''); ++h[0][i % p];}
	int len = str.size();
	for(int i = 0 ; i < k ; ++i){
		len = (len * 5) % p;
		for(int j = 0 ; j < p ; ++j){
			inc(f[i + 1][(5 * j + 2) % p], f[i][j]);
			long long val = 1ll * (h[i][j] - g[i][j] + P) * '\'' + 1ll * g[i][j] * '\"';
			inc(f[i + 1][(5 * j + 1) % p], val);
			inc(f[i + 1][(5 * j + 3) % p], val);
			inc(f[i + 1][(5 * j) % p], 1ll * h[i][j] * ' ');
			inc(f[i + 1][(5 * j + 4) % p], 1ll * h[i][j] * ',');
			for(int k = 0 ; k < 5 ; ++k) inc(h[i + 1][(5 * j + k) % p], h[i][j]);
			inc(g[i + 1][(5 * j + 1) % p], h[i][j] - g[i][j] + P);
			inc(g[i + 1][(5 * j + 2) % p], g[i][j]);
			inc(g[i + 1][(5 * j + 3) % p], h[i][j] - g[i][j] + P);
		}
		inc(f[i + 1][0], '[' - ' ' + P);
		inc(f[i + 1][(len + p - 1) % p], ']' - ',' + P);
	}
	for(int i = 0 ; i < p ; ++i) cout << f[k][i] << " \n"[i == p - 1];
	return 0;
}