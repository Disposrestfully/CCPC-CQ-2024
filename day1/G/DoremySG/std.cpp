#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>p;
const int limit1=1e18;
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
int exgcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - a / b * y;
    return r;
}
signed main(){
	
	for(int i=0;i<=50;i++){
	    for(int j=0;j<=30;j++){
	        int res=pow(2,i)*pow(5,j);
	        if(res>limit1)break;
	        p.push_back(res);
	    }
	}
	sort(p.begin(),p.end());
	int t;
	cin>>t;
	while(t--){
	    int a,b,c=1e9,d;
	    cin>>a>>b;
	    int r=b,q=a;
//	    int g=gcd(r,q);
//	    r/=g,q/=g;
        int w=1;
	    while(r%2==0){
	        r/=2;
	        w*=2;
	    }
	    while(r%5==0){
	        r/=5;
	        w*=5;
	    }
	    int x=r;
	    bool ok=1;
	    for(int i=0;i<p.size();i++){
	        int y=x*p[i];
	        if(y>limit2){
	            ok=0;
	            break;
	        }/*
	        if((w*p[i])%(r-(q*p[i])%r)==0){
	            c=c*p[i]*w/(r-(q*p[i])%r);
	            if(c>limit2)continue;
	            cout<<c<<endl;
	            break;
	        }*/
	        /*
	        if((q*p[i]+w)%r==0){
	            c=c*p[i];
	            cout<<c<<endl;
	            break;
	        }
	        */
	        int res=r-(q*p[i])%r;
	  //      cerr<<res<<endl;
	        int u=exgcd(w,r,t1,t2);
	        res=(res/u*t1%(r/u)+r/u)%(r/u);
	        if(res<c){
	            c=res;
	            d=x*p[i];
	        }
	    }
	 //   cerr<<endl;
	    cout<<c<<' '<<d<<endl;
	}
}
