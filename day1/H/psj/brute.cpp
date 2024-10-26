#include<bits/stdc++.h>
using namespace std;

const int _ = 1e5 + 7;
vector < int > nxt[_], elem[_], back[_]; int a[_], ans[_], cnt[_], n, maxsize;
vector < int > dfs(int x, int p){
	vector < int > back;
	vector < vector < int > > son, tmp;
	for(auto t : nxt[x])
		if(t != p){vector < int > ch = dfs(t, x); if(ch.size()) son.push_back(ch);}
	elem[x].push_back(0);
	while(1)
		if(elem[x].back() != nxt[x].size()){back.push_back(0); elem[x].push_back(elem[x].back() + 1);}
		else{
			++back.back(); elem[x].pop_back(); if(son.empty()) break;
			int newelem = nxt[x].size() - !!p - son.size(); tmp.clear();
			for(auto &t : son){
				newelem += t.back(); t.pop_back();
				if(t.size()) tmp.push_back(t);
			}
			son = tmp; elem[x].push_back(newelem);
		}
	maxsize = max(maxsize, (int)elem[x].size());
	reverse(elem[x].begin(), elem[x].end()); reverse(back.begin(), back.end());
	while(back.size() && a[x]){--a[x]; elem[x].pop_back(); a[p] += back.back(); cnt[x] += back.back(); back.pop_back();}
	if(x == 1 && a[x]){puts("-1"); exit(0);}
	a[p] += a[x]; cnt[x] += a[x];
	::back[x] = back; return back;
}
void getans(int x, int p){
	vector < int > back = ::back[x];
	while(back.size() && a[x]){--a[x]; elem[x].pop_back(); cnt[x] += back.back(); back.pop_back();}
	if(elem[x].size()) a[x] = elem[x].back();
	else{cnt[x] += a[x]; a[x] = nxt[x].size() - 1;}
	for(auto t : nxt[x]) if(t != p){a[t] = cnt[x]; getans(t, x);}
}

int main(){
	ios::sync_with_stdio(0); 
	cin >> n; if(n > 1e5){puts("-1"); return 0;}
	for(int i = 1 ; i < n ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	dfs(1,0); getans(1, 0);
	cerr << maxsize << endl;
	for(int i = 1 ; i <= n ; ++i) cout << a[i] << " \n"[i == n];
	return 0;
}