#include<bits/stdc++.h>
using namespace std;

const int _ = 1e6 + 7, INF = 2e9;
vector < int > nxt[_], bk[_]; int a[_], stat[_], n;

priority_queue < pair < int , int > > q[_];
int mrk[_], dsu[_], sz[_];
int find(int x){return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));}
void merge(int p, int q){sz[p] += sz[q]; dsu[q] = p;}
//dsu here is used to maintain the chain structure.

// For each vertex x that is the start of some chain (not deg-2 and with several continous deg-2 ancestors), maintain stat[x] for the state of the chain.
// In the following, 1 means full (i.e. a[x] = deg[x] - 1), 0 means not full.
// -v: 1^(len-v)01^v, in the following v add-1 operation in the top, the chain would give back 1, with 0 going upwards.
// 0: 1^(len-1)0, the following add-1 would not give back
// +v: 1^len, the following v add-1 operations would give back 1
// Behavior of -v and +v respectively would keep the same unless at least v add-1 ops occur.
// Notice further that these states correctly characterize all possible choices for one chain.
int val(int x){return x == 0 ? 1 : abs(x);}
// Calc how many ops would change the state of current vertex.
// For -v and v, v ops would change the state, while 0 can only stay for 1 ops.

int upd(int x, int p, int v, bool dwn = 1){
	// update state for vertex x (and the chain associated to it) with v add-1 ops.
	// dwn: whether x is the current root vertex in the subtree.
	// Return: if x is not merged into another chain, return x, otherwise the bottom vertex of the chain.
	if(stat[x] < 0){stat[x] += v; ++a[p]; return x;}
	// -v with v ops would change to 0.
	// Such state would always give back to its parent receiving add-1 ops, so we give it back.
	if(v < stat[x]){stat[x] -= v; mrk[x] += v; a[p] += v; return x;}
	// Here we give parents v rather than 1. Illustrated in the following.
	if(!stat[x]) ++a[x]; //If x is with state 0, the 1 is correctly passed to x, add deg of x.
	// The added degree is actually postponed from the state -(len-1) when chain length > 1, since from 0111... 10111... already add a[x] (notice x is the bottom of the chain). But actually 10111... cannot be seen as exactly deg plus one, since adding one on the top of the chain would fill in the ``gap'' between the top and bottom. We do here as if x is a single vertex, and compute the correct a[] in down(x,p).
	else{
		a[p] += (dwn ? 1 : v);
		// When dwn is true (i.e. current vertex is not the root vertex), this is the compensation for --a[x] in line 42, meaning current vertex actually give back 1. When it is the root, then we are sending extra chips to its father when firing v.
		a[x] = nxt[x].size();
		while(a[x] == nxt[x].size() && q[x].size());{
			// If p = 0 and x is the actual root, we may face the case where after one update a[x] is still full.
			a[x] = nxt[x].size() - !!p; // we only count chips back for children
			if(q[x].size()) mrk[x] = -q[x].top().first; // Find the next timestamp
			while(q[x].size() && -q[x].top().first == mrk[x]){
				int r = q[x].top().second; q[x].pop(); --a[x];
				int nr = upd(r, x, val(stat[r])); //update the corresponding children. The children may be merged to some chain after updating.
				if(stat[nr] < 1e7) q[x].emplace(-(val(stat[nr]) + mrk[x]), nr); //When stat[nr] = INF, it means the subtree is full and we simply delete it.
			}
		}
	}
	if(a[x] >= nxt[x].size()){puts("-1"); exit(0);} // After all vertices are full, we can still fire a[1], which leads to infinite loop.
	else if(a[x] == nxt[x].size() - 1) stat[x] = !p ? 1 : (q[x].empty() ? INF : -q[x].top().first - mrk[x]); // When x is ready to fire, when p != 0 and the vertex is not the root, the following (-q[x].top().first - mrk[x]) steps would be the following: give 1 to x, x fire, all children of x give back, and x give back 1 to its parent. So we need such number of steps to go to another state; For p = 0, all children of x give back would lead to iterated firing, and we only need 1 chip to trigger this iteration.
	else stat[x] = -(sz[x] - 1); // We need extra chips at x, which nead sz[x] steps to ``transport'' 0 from bottom to top.
	if(dwn && stat[x] > 0 && q[x].size() == 1){//Here for simplicity (and actually root vertex is computed in a special way), we do not join current root to any other chain. When x has the only child and the current chain is ready (i.e. all 1 along the chain), we can join current chain to its only children.
	// The reason the chain must be ready is that there may be multiple zeros along the chain otherwise.
		int r = find(q[x].top().second);
		if(stat[r]){//pushdown tags.
			if(stat[r] > 0) mrk[r] += stat[r] - (-q[x].top().first - mrk[x]);
			//Notice here that for stat[r] > 0, mrk[r] should increase by the increase of current mark. stat[r] < 0 do not increase (since mrk[x] actually record number of times that x fires and give chips to its children.)
			stat[r] = (stat[r] < 0 ? -1 : 1) * (-q[x].top().first - mrk[x]);
		}
		if(stat[r] <= 0) stat[r] -= sz[x]; //extend the height that current 0 need to climb up.
		merge(r, x); q[x].pop(); return r;
	}
	return x;
}

void dfs(int x, int p){
	for(auto t : nxt[x]) if(t != p){dfs(t, x); if(stat[t] < 1e7) q[x].emplace(-val(stat[t]), t);}
	int lft = a[x]; a[x] = 0; if(lft > n){puts("-1"); exit(0);} // To avoid exceeding values.
	stat[x] = nxt[x].size() != 1 ? 0 : (!p ? 1 : (q[x].empty() ? INF : -q[x].top().first));
	while(lft){int dlt = min(lft, val(stat[x])); upd(x, p, dlt, 0); lft -= dlt;}//keep updating current vertex (with dwn=0 meaning current is the root and we can freely pass chips to its parent) until we use up all a[x] chips.
}
void down(int x, int p){ //Pushdown all tags
	static int fa[_], dep[_]; fa[x] = p; dep[x] = dep[p] + 1;
	while(q[x].size()){
		int newmrk = q[x].top().first + val(stat[q[x].top().second]) + mrk[x];
		if(stat[q[x].top().second] < 0) stat[q[x].top().second] += newmrk; //This is the useful part, where lazytag affect the position of 0 in the chain.
		else mrk[q[x].top().second] += newmrk; //Notice that we need to push tags for positive vertices down. we can skip the update for stat[] since it is useless for stat[]>0 vertices, but its mrk[] may update other stat[]<0 vertices.
		q[x].pop();
	}
	for(auto t : nxt[x]) if(t != p) down(t, x);
	if(dsu[p] == x){ // Calculate the result for some chain.
		if(stat[x] <= 0) a[x] += (stat[x] != -sz[x] + 1); //Fix deg issue stated in line 34.
		for(int t = p; find(t) == x; t = fa[t]) //Using stat[x], it is easy to determine who is the 0 vertex.
			a[t] = nxt[t].size() - 1 - (stat[x] == -sz[x] + dep[x] - dep[t] + 1);
	}
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; for(int i = 1 ; i <= n ; ++i){dsu[i] = i; sz[i] = 1;}
	for(int i = 1 ; i < n ; ++i){int p, q; cin >> p >> q; nxt[p].push_back(q); nxt[q].push_back(p);}
	for(int i = 1 ; i <= n ; ++i) cin >> a[i];
	dfs(1, 0); down(1, 0);
	for(int i = 1 ; i <= n ; ++i) cout << a[i] << " \n"[i == n];
	/*ifstream in("../data/13.ans");
	for(int i = 1 ; i <= n ; ++i){
		int ans; in >> ans;
		if(ans != a[i]) cerr << i << ' ' << a[i] << ' ' << ans << ' ' << nxt[i].size() << endl;
	}*/
	return 0;
}