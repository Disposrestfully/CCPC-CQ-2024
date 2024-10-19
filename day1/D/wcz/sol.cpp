#include <bits/stdc++.h>
using namespace std;
const int N=100010;
int n,m,a,x,y,mx,pos,smx,dgr[N];
int main () {
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) {
		scanf("%d",&a);
		if (a>mx) {
			smx=mx;
			mx=a;
			pos=i;
		} else if (a>smx) {
			smx=a;
		}
	}
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		dgr[x]++,dgr[y]++;
	}
	if (n==1||dgr[pos]>1) {printf("%d\n",mx);}
	else {printf("%d\n",smx);}
	return 0;
}
