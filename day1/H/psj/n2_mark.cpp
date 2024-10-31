#include<bits/stdc++.h>
using namespace std;

#define vdat vector < dat >
const int _ = 1e6 + 7;
vector < int > nxt[_]; int a[_], ans[_], cnt[_], n;
int sign(int x){return x < 0 ? -1 : (x == 0 ? 0 : 1);}

struct dat{int x, mark; dat(int _x){x = _x; mark = 0;}}; vdat bk[_];
int qval(vdat &v){
	int mk = v.back().mark; 
	if(mk){
		if(v.back().x < 0){
			if(++v.back().x == 0){v.pop_back(); if(v.size()) v.back().mark += mk;}
			if(v.size() && v.back().x > 0) v.back().x += mk;
			else v.emplace_back(mk);
			v.emplace_back(-1);
		}else{v.back().mark = 0; if(v.size() > 1) v[v.size() - 2].mark += mk;}
	}
	return v.back().x;
}

vdat dfs(int x, int p){
	vdat &bk = ::bk[x]; vector < vdat > son; set < int > ind;
	for(auto t : nxt[x])
		if(t != p){vdat ch = dfs(t, x); if(ch.size()){ind.insert(son.size()); son.push_back(ch);}}
	int pre = 0;
	while(1){
		if((p && pre + 1 != nxt[x].size()) || (!p && nxt[x].size() != pre))
			bk.emplace_back(pre - (int)nxt[x].size() + 1);
		if(ind.empty()){
			if(bk.empty() || qval(bk) < 0) bk.emplace_back(1); else ++bk.back().x;
			break;
		}
		if(p && ind.size() == 1) break;
		int newelem = nxt[x].size() - !!p - ind.size(), mn = 1e9;
		for(auto t : ind) mn = min(mn, qval(son[t]));
		if(bk.size() && qval(bk) > 0) bk.back().x += max(mn, 1);
		else bk.emplace_back(max(mn, 1));
		auto it = ind.begin();
		while(it != ind.end()){
			int t = *it; newelem += sign(qval(son[t])) == 1;
			if(!(son[t].back().x -= sign(qval(son[t])) * max(mn, 1))) son[t].pop_back();
			if(son[t].empty()) it = ind.erase(it); else ++it;
		}
		pre = newelem;
	}
	reverse(bk.begin(), bk.end());
	if(p && ind.size()){
		vdat prev = son[*ind.begin()]; ++prev.back().mark;
		prev.push_back(1); prev.insert(prev.end(), bk.begin(), bk.end()); bk = prev;
	}
	while(bk.size() && a[x])
		if(!p && qval(bk) > 0){--a[x]; cnt[x] += qval(bk); bk.pop_back();}
		else{
			int dlt = min(a[x], abs(qval(bk))); a[x] -= dlt;
			if(qval(bk) > 0){cnt[x] += dlt; a[p] += dlt;}
			if(!(bk.back().x -= sign(qval(bk)) * dlt)) bk.pop_back();
		}
	if(!p && bk.empty()){puts("-1"); exit(0);}
	a[p] += a[x]; cnt[x] += a[x]; return bk;
}
void getans(int x, int p){
	vdat &bk = ::bk[x];
	while(bk.size() && a[x]){
		int dlt = min(a[x], abs(qval(bk))); a[x] -= dlt;
		if(qval(bk) > 0) cnt[x] += dlt;
		if(!(bk.back().x -= sign(qval(bk)) * dlt)) bk.pop_back();
	}
	if(bk.size()) a[x] = nxt[x].size() - 1 + min(0, qval(bk));
	else{cnt[x] += a[x]; a[x] = nxt[x].size() - 1;}
	for(auto t : nxt[x]) if(t != p){a[t] = cnt[x]; getans(t, x);}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; if(n > 1e5){puts("-1"); return 0;}
	for(int i = 1 ; i < n ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	dfs(1, 0); getans(1, 0);
	//int r; cin >> r; dfs(r, 0); getans(r, 0);
	for(int i = 1 ; i <= n ; ++i) cout << a[i] << " \n"[i == n];
	return 0;
}