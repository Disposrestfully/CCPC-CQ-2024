#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7;
vector < int > nxt[_], bk[_]; int a[_], ans[_], stat[_], n;
int sign(int x){return x < 0 ? -1 : (x == 0 ? 0 : 1);}

priority_queue < pair < int , int > > q[_]; int mrk[_];
void upd(int x, int p, int v, bool top = 1){
	if(v < stat[x]){stat[x] -= v; mrk[x] += v; a[p] += v; return;}
	if(a[x] != nxt[x].size() - 1) ++a[x];
	else{
		a[p] += (top ? 1 : v);
		do{
			a[x] = nxt[x].size() - !!p; 
			if(q[x].size()) mrk[x] = -q[x].top().first;
			while(q[x].size() && -q[x].top().first == mrk[x]){
				int r = q[x].top().second; q[x].pop(); --a[x];
				upd(r, x, stat[r]); if(stat[r] < 1e7) q[x].emplace(-(stat[r] + mrk[x]), r);
			}
		}while(a[x] == nxt[x].size() && q[x].size());
	}
	if(!p && a[x] == nxt[x].size()){puts("-1"); exit(0);} // a[1] > deg[1]
	else if(a[x] == nxt[x].size() - 1)
		stat[x] = !p ? 1 : (q[x].empty() ? 1e9 : -q[x].top().first - mrk[x]);
	else stat[x] = 1;
}

void dfs(int x, int p){
	for(auto t : nxt[x]) if(t != p){dfs(t, x); if(stat[t] < 1e7) q[x].emplace(-stat[t], t);}
	int lft = a[x]; a[x] = 0; stat[x] = nxt[x].size() != 1 ? 1 : 1e9;
	while(lft || !stat[x]){int dlt = min(lft, stat[x]); upd(x, p, dlt, 0); lft -= dlt;}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	cin >> n; if(n > 1e5){puts("-1"); return 0;}
	for(int i = 1 ; i < n ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	dfs(1, 0);
	for(int i = 1 ; i <= n ; ++i) cout << a[i] << " \n"[i == n];
	return 0;
}