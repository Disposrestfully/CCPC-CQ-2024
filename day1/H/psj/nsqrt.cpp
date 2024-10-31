#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
const int _ = 1e6 + 7, INF = 2e9;
vector < int > nxt[_], bk[_]; int a[_], stat[_], n, deg[_];

priority_queue < pair < int , int > > q[_]; int mrk[_], dsu[_], sz[_];
int find(int x){return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));}
void merge(int p, int q){sz[p] += sz[q]; dsu[q] = p;}

int val(int x){return x == 0 ? 1 : abs(x);}
int upd(int x, int p, int v, bool dwn = 1){
	if(stat[x] < 0){stat[x] += v; ++a[p]; return x;}
	if(v < stat[x]){stat[x] -= v; mrk[x] += v; a[p] += v; return x;}
	if(!stat[x]) ++a[x];
	else{
		a[p] += (dwn ? 1 : v); a[x] = deg[x];
		while(a[x] == deg[x] && q[x].size()){
			a[x] = deg[x] - !!p; 
			if(q[x].size()) mrk[x] = -q[x].top().fi;
			while(q[x].size() && -q[x].top().fi == mrk[x]){
				int r = q[x].top().se; q[x].pop(); --a[x];
				int nr = upd(r, x, val(stat[r]));
				if(stat[nr] < 1e7) q[x].emplace(-(val(stat[nr]) + mrk[x]), nr);
			}
		}
	}
	if(a[x] >= deg[x]){puts("-1"); exit(0);}
	else if(a[x] == deg[x] - 1) stat[x] = !p ? 1 : (q[x].empty() ? INF : -q[x].top().fi - mrk[x]);
	else stat[x] = -(sz[x] - 1);
	if(dwn && stat[x] > 0 && q[x].size() == 1){
		int r = find(q[x].top().se);
		if(stat[r]){
			if(stat[r] > 0) mrk[r] += stat[r] - (-q[x].top().fi - mrk[x]);
			stat[r] = (stat[r] < 0 ? -1 : 1) * (-q[x].top().fi - mrk[x]);
		}
		if(stat[r] <= 0) stat[r] -= sz[x];
		merge(r, x); q[x].pop(); return r;
	}
	return x;
}

void dfs(int x, int p){
	for(auto t : nxt[x]) if(t != p){dfs(t, x); if(stat[t] < 1e7) q[x].emplace(-val(stat[t]), t);}
	int lft = a[x]; a[x] = 0; stat[x] = deg[x] != 1 ? 0 : (!p ? 1 : (q[x].empty() ? INF : -q[x].top().fi));
	if(lft > n){puts("-1"); exit(0);}
	while(lft){int dlt = min(lft, val(stat[x])); upd(x, p, dlt, 0); lft -= dlt;}
}
void down(int x, int p){
	static int fa[_], dep[_]; fa[x] = p; dep[x] = dep[p] + 1;
	while(q[x].size()){
		int newmrk = q[x].top().fi + val(stat[q[x].top().se]) + mrk[x];
		if(stat[q[x].top().se] < 0) stat[q[x].top().se] += newmrk;
		else mrk[q[x].top().se] += newmrk;
		q[x].pop();
	}
	for(auto t : nxt[x]) if(t != p) down(t, x);
	if(dsu[p] == x){
		if(stat[x] <= 0) a[x] += (stat[x] != -sz[x] + 1);
		for(int t = p; find(t) == x; t = fa[t])
			a[t] = deg[t] - 1 - (stat[x] == -sz[x] + dep[x] - dep[t] + 1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for(int i = 1 ; i <= n ; ++i){dsu[i] = i; sz[i] = 1;}
	for(int i = 1 ; i < n ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= n ; ++i){cin >> a[i]; deg[i] = nxt[i].size();}
	dfs(1, 0); down(1, 0); for(int i = 1 ; i <= n ; ++i) cout << a[i] << " \n"[i == n];
	return 0;
}