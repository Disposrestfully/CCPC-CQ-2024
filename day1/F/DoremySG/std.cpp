#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n;
		string a,b;
		cin>>n>>a>>b;
		string ans[10];
		string s(n,'.');
		bool pa=0,pb=0;
		for(int i=0;i<n;i++){
			if(a[i]=='.')pa=1;
			if(b[i]=='.')pb=1;
		}
		if(pa^pb){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
		if(!pa){
			for(int i=1;i<=7;i++)cout<<a<<endl;
			continue;
		}
		for(int i=1;i<=7;i++)ans[i]=s;
		ans[1]=a;
		ans[7]=b;
		for(int i=0;i<n;i++){
			ans[2][i]='.'+'#'-a[i];
			ans[6][i]='.'+'#'-b[i];
		}
		int  c1=0,c2=0;
		for(int i=0;i<n;i++){
			if(!c1 and ans[2][i]=='.' and ((i>0 and ans[2][i-1]=='#') or (i<n-1 and ans[2][i+1]=='#'))){
				ans[3][i]='#';
				c1=i+1;
			}
			if(!c2 and ans[6][i]=='.' and ((i>0 and ans[6][i-1]=='#') or (i<n-1 and ans[6][i+1]=='#'))){
				ans[5][i]='#';
				c2=i+1;
			}
		}
		c1--;
		c2--;
		if(c1>c2)swap(c1,c2);
		if(c2-c1<=1)ans[4][c1]='#';
		else for(int i=c1+1;i<c2;i++)ans[4][i]='#';
		for(int i=1;i<=7;i++)cout<<ans[i]<<endl;
	}
}