#include <bits/stdc++.h>
using namespace std;
const int P=998244353;
int t,ans,a[11];
int qpow (int a,int b) {
	int res=1;
	while (b) {
		if (b&1) {res=(1ll*res*a)%P;}
		a=(1ll*a*a)%P,b>>=1;
	}
	return res;
}
int main () {
	scanf("%d",&t);
	for (int ii=1;ii<=t;ii++) {
		for (int i=1;i<=9;i++) {scanf("%d",&a[i]);}
		a[10]=0,ans=1;
		if (a[1]==1) {
			for (int i=2;i<=9;i++) {
				if (a[i]) {a[i]--,a[i+1]++;break;}
			}
			a[1]=0;
		}
		for (int i=3;i<=10;i++) {ans=(1ll*ans*qpow(i,a[i]))%P;}
		int cnt2=0,cnt3=0;
		if (a[1]<=a[2]) {cnt2=a[2]-a[1],cnt3=a[1];}
		else if (a[1]==a[2]+1) {cnt2=2,cnt3=a[2]-1;}
		else {
			int res=a[1]-a[2];
			if (res%3==1) {cnt2=2,cnt3=a[2]+(res/3)-1;}
			else if (res%3==2) {cnt2=1,cnt3=a[2]+(res/3);}
			else {cnt2=0,cnt3=a[2]+(res/3);}
		}
		ans=(1ll*ans*qpow(2,cnt2))%P;
		ans=(1ll*ans*qpow(3,cnt3))%P;
		printf("%d\n",ans);
	}
	return 0;
}
