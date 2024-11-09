#include <bits/stdc++.h>
using namespace std;
const int N=500010;
int n,q,x,y,a[N],c[N],ans[N],fw[N];
stack <int> st[N];
vector <int> v[N];
vector < pair<int,int> > qus[N];
int query (int x) {
	int res=0;
	for (int i=x;i;i-=(i&(-i))) {res+=fw[i];}
	return res;
}
void add (int x) {
	for (int i=x;i<=n;i+=(i&(-i))) {fw[i]++;}
}
int main () {
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++) {scanf("%d",&a[i]);}
	for (int i=1;i<=n;i++) {
		scanf("%d",&c[i]);
		if (a[i]==0) {st[c[i]].push(i);}
		else {
			if (st[c[i]].size()) {
				int lf=st[c[i]].top();
				st[c[i]].pop();
				v[lf].push_back(i);
			}
		}
	}
	for (int i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		qus[x].push_back(make_pair(y,i));
	}
	for (int i=n;i>=1;i--) {
		for (auto u:v[i]) {add(u);}
		for (auto u:qus[i]) {ans[u.second]=query(u.first);}
	}
	for (int i=1;i<=q;i++) {printf("%d\n",ans[i]);}
	return 0;
}
