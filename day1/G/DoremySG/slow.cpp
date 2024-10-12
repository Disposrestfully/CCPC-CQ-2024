#include<bits/stdc++.h>
using namespace std;
#define int long long
const int limit1=1e12;
const int limit2=1e9;
int pow(int p,int b){
    int ans=1;
    for(int i=1;i<=b;i++){
        ans*=p;
    }
    return ans;
}
int t1,t2;
int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<int>p;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	for(int i=0;i<=50;i++){
	    for(int j=0;j<=30;j++){
	        int res=pow(2,i)*pow(5,j);
	        if(res>limit1)break;
	        p.push_back(res);
	    }
	}
	sort(p.begin(),p.end());
	
	while(t--){
		int a,b;
		cin>>a>>b;
		int s=b-a+1,q=b,ansd=b;
		while(q%2==0)q/=2;
		while(q%5==0)q/=5;
		if(q==1){
			cout<<"0 1"<<endl;
			continue;
		}
		for(auto it:p){
			if(it*q>limit2)break;
			for(int i=1;i<s;i++){
					int pa=it*q*a+b*i,pb=it*b*q;
				int g=gcd(pa,pb);
				pa/=g;
				pb/=g;
				while(pb%2==0)pb>>=1;
				while(pb%5==0)pb/=5;
				//cerr<<pa<<' '<<pb<<endl;
				if(pb==1){
					s=i;
					ansd=it*q;
				}
			}
			if(s==1)break;
		}
		int pa=a*ansd+b*s,pb=ansd*b;
		int g=gcd(pa,pb);
		pb/=g;
		while(pb%2==0)pb>>=1;
		while(pb%5==0)pb/=5;
		assert(pb==1);
		cout<<s<<" "<<ansd<<endl;
	}
}