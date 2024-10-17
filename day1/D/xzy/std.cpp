#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m,fir,sec;
int d[maxn],a[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,x,y;i<=m;i++)
		scanf("%d%d",&x,&y),d[x]++,d[y]++;
	if(n==1){
		printf("%d\n",a[1]);
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]>a[fir])
			sec=fir,fir=i;
		else if(a[i]>a[sec])
			sec=i;
	}
	cerr<<d[fir];
	printf("%d\n",d[fir]==1? a[sec]:a[fir]);
	return 0;
}
