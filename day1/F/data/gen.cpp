#include<bits/stdc++.h>
using namespace std;
#define int long long
mt19937 mrand(time(0));
ofstream fout("2.in");
#define cout fout
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t=10000;
	cout<<t<<endl;
	int s=200000;
	for(int i=2;i<=6;i++){
		for(int j=1;j<1<<i;j++){
			for(int k=1;k<1<<i;k++){
				cout<<i<<endl;
				string a,b;
				for(int l=1;l<=i;l++){
					if(j&(1<<i-l))a+='#';
					else a+='.';
					if(k&(1<<i-l))b+='#';
					else b+='.';
				}
				cout<<a<<endl<<b<<endl;
				int c=0;
				for(auto it:a){
					if(it=='#')c++;
				}
				assert(c);
				c=0;
				for(auto it:b){
					if(it=='#')c++;
				}
				assert(c);
				t--;
				s-=i;
			}
		}
	}
	cerr<<t<<' '<<s<<endl;
	int rem=t;
	for(int w=0;w<=5;w++){
		for(int i=1;i<=t/6;i++){
			int n=9+w*8;
			cout<<n<<endl;
			for(int q=0;q<=1;q++){
			string a;
			for(int j=0;j<n;j++){
				int p=mrand()%(n/3);
				if(p)a+='#';
				else a+='.';
			}
			a[mrand()%n]='#';
			int c=0;
				for(auto it:a){
					if(it=='#')c++;
				}
				assert(c);
				cout<<a<<endl;
			
			}
			s-=n;
			rem--;
		}
	}
	
	int n=s/5;
	for(int i=1;i<=5;i++){
			
			cout<<n<<endl;
			for(int q=0;q<=1;q++){
			string a;
			for(int j=0;j<n;j++){
				int p=mrand()%(n/3);
				if(p)a+='#';
				else a+='.';
			}
			a[mrand()%n]='#';
			int c=0;
				for(auto it:a){
					if(it=='#')c++;
				}
				assert(c);
				cout<<a<<endl;
			
			}
			s-=n;
			rem--;
		}
		cerr<<rem<<' '<<s<<endl;
}