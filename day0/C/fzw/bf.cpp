#include<bits/stdc++.h>
#define ll long long
#define dd double
#define ull unsigned ll
#define LL __int128
#define siz(A) ((int)A.size())
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
char ST;
const int xx=5e5+5;
int lb(int x){return x&-x;}
int sum[xx];
void add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

int n,q,a[xx],c[xx],ans[xx];
struct nod
{
	int l,r,i;
}Q[xx];
vector<int>v[xx];
int t[xx];

char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
//	freopen("a.in","r",stdin);
	n=read(),q=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)c[i]=read();
	
	for(int i=1;i<=q;i++)
	{
		int l=read(),r=read(),re=0;
		for(int j=l;j<=r;j++)
		{
			if(a[j]==0)t[c[j]]++;
			else if(t[c[j]])++re,--t[c[j]];
		}
		for(int j=l;j<=r;j++)t[c[j]]=0;
		cout<<re<<"\n";
	}
		
	
	pc('1',1);
	return 0;
}
