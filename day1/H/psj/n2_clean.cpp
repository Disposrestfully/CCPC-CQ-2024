#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7;
vector < int > nxt[_], back[_]; int a[_], ans[_], cnt[_], n;
int sign(int x){return x < 0 ? -1 : (x == 0 ? 0 : 1);}

vector < int > dfs(int x, int p){
	vector < int > back; vector < vector < int > > son; set < int > ind;
	for(auto t : nxt[x])
		if(t != p){vector < int > ch = dfs(t, x); if(ch.size()){ind.insert(son.size()); son.push_back(ch);}}
	int pre = 0;
	while(1){
		if((p && pre + 1 != nxt[x].size()) || (!p && nxt[x].size() != pre))
			back.push_back(pre - (int)nxt[x].size() + 1);
		if(ind.empty()){
			if(back.empty() || back.back() < 0) back.push_back(1); else ++back.back();
			break;
		}
		int newelem = nxt[x].size() - !!p - ind.size(), mn = 1e9;
		for(auto t : ind) mn = min(mn, son[t].back());
		if(back.size() && back.back() > 0) back.back() += max(mn, 1);
		else back.push_back(max(mn, 1));
		auto it = ind.begin();
		while(it != ind.end()){
			int t = *it; newelem += sign(son[t].back()) == 1;
			if(!(son[t].back() -= sign(son[t].back()) * max(mn, 1))) son[t].pop_back();
			if(son[t].empty()) it = ind.erase(it); else ++it;
		}
		pre = newelem;
	}
	reverse(back.begin(), back.end());
	while(back.size() && a[x])
		if(!p && back.back() > 0){--a[x]; cnt[x] += back.back(); back.pop_back();}
		else{
			int dlt = min(a[x], abs(back.back())); a[x] -= dlt;
			if(back.back() > 0){cnt[x] += dlt; a[p] += dlt;}
			if(!(back.back() -= sign(back.back()) * dlt)) back.pop_back();
		}
	if(!p && back.empty()){puts("-1"); exit(0);}
	a[p] += a[x]; cnt[x] += a[x]; ::back[x] = back; return back;
}
void getans(int x, int p){
	vector < int > back = ::back[x];
	while(back.size() && a[x]){
		int dlt = min(a[x], abs(back.back())); a[x] -= dlt;
		if(back.back() > 0) cnt[x] += dlt;
		if(!(back.back() -= sign(back.back()) * dlt)) back.pop_back();
	}
	if(back.size()) a[x] = nxt[x].size() - 1 + min(0, back.back());
	else{cnt[x] += a[x]; a[x] = nxt[x].size() - 1;}
	for(auto t : nxt[x]) if(t != p){a[t] = cnt[x]; getans(t, x);}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; if(n > 1e5){puts("-1"); return 0;}
	for(int i = 1 ; i < n ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	dfs(1, 0); getans(1, 0);
	for(int i = 1 ; i <= n ; ++i) cout << a[i] << " \n"[i == n];
	return 0;
}