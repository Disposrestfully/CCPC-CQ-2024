#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<map>
using namespace std;
#define N 1000012
#define LL long long
#define MAX_READ 1048576
inline char gc(void)
{
	static char buf[MAX_READ],*l=buf,*r=buf;
	if(l==r)r=(l=buf)+fread(buf,1,MAX_READ,stdin);return l==r?(~0):*(l++);
}
inline int re(){int X=0;char ch=0;while('0'>ch)ch=gc();while('0'<=ch)X=(X<<3)+(X<<1)+(ch^48),ch=gc();return X;}
char CH[10000012];int cn=0;
inline void wr(int x){int v=x/10;if(x>=10)wr(v);CH[++cn]=(x-v*10)^48;}
int n,a[N],b[N],h[N],cnt=0;
struct Edge{int to,next;}e[N<<1];
inline void AddEdge(int x,int y){e[++cnt]=(Edge){y,h[x]};h[x]=cnt;}
int g[N],g1[N],dfst=0,ld[N],rd[N];bool sc[N];
int tot=0,c[N][2],fa[N],r1[N],rt[N],s[N],nul,mx[N],mi[N],id[N];LL w[N],L[N],R[N],A[N],B[N];
inline bool Get(int x){return (c[fa[x]][1]==x);}
inline void pus(int x)
{
	s[x]=s[c[x][0]]+s[c[x][1]]+1;L[x]=c[x][0]?L[c[x][0]]:w[x];R[x]=c[x][1]?R[c[x][1]]:w[x];
	mx[x]=max(max(mx[c[x][0]],mx[c[x][1]]),id[x]);mi[x]=min(min(mi[c[x][0]],mi[c[x][1]]),id[x]);
}
inline void rot(int x,int &f)
{
	int y=fa[x],z=fa[y],px=Get(x),&v=c[x][px^1];
	if(y==f)f=x;else c[z][Get(y)]=x;fa[fa[(v?fa[v]:nul)=y]=x]=z;c[y][px]=v;v=y;pus(y);pus(x);
}
inline void Ad(int x,LL a,LL b){if(!x)return;w[x]+=1ll*(s[c[x][0]]+1)*a+b;L[x]+=a+b;R[x]+=s[x]*a+b;A[x]+=a;B[x]+=b;}
inline void pd(int x){LL &a=A[x],&b=B[x];if(a||b){if(c[x][0])Ad(c[x][0],a,b);if(c[x][1])Ad(c[x][1],a,b+a*(s[c[x][0]]+1));a=b=0;}}
void Push(int x,int f){if(x!=f)Push(fa[x],f);pd(x);}
inline void spl(int x,int &f){Push(x,f);for(int y;x!=f;rot(x,f))if((y=fa[x])!=f)rot((Get(y)^Get(x))?x:y,f);}
void Ins(int &p,LL v,int la,int &rt,int hd){if(!p){fa[p=hd]=la;L[p]=R[p]=w[p]=v;s[p]=1;spl(p,rt);return;}pd(p);Ins(c[p][w[p]<=v],v,p,rt,hd);}
int st[N],tp=0;
void Dtc(int p){if(!p)return;pd(p);Dtc(c[p][0]);st[++tp]=p;Dtc(c[p][1]);c[p][0]=c[p][1]=fa[p]=0;}
void dfs(int p){if(!p)return;pd(p);dfs(c[p][0]);st[++tp]=p;dfs(c[p][1]);}
int Fin(int &rt,LL v){int p=rt,la=0,res=0;while(p){la=p;pd(p);p=(w[p]<=v)?(res=p,c[p][1]):c[p][0];}if(la)spl(la,rt);return res;}
LL Seh(int &rt,LL nw,int d)
{
	LL lt=rt?(L[rt]-1):(4ll*n*n*n);if(nw-lt<=d)return max(0ll,nw-d);
	int p=rt,v=0,la=0;LL res=lt;
	while(p)
	{
		la=p;pd(p);
		if(res==w[p])
		{
			v+=s[c[p][0]]+1;
			lt=c[p][1]?max(res,L[c[p][1]]-1):(4ll*n*n*n);
			if(nw-v-lt<=d){res+=max(0ll,nw-v-res-d);break;}
			p=c[p][1];
		}
		else
		{
			lt=max(R[c[p][0]],w[p]-1);
			if(nw-v-s[c[p][0]]-lt<=d){p=c[p][0];continue;}
			res=w[p];v+=s[c[p][0]]+1;
			lt=c[p][1]?max(res,L[c[p][1]]-1):(4ll*n*n*n);
			if(nw-v-lt<=d){res+=max(0ll,nw-v-res-d);break;}
			p=c[p][1];
		}
	}
	spl(la,rt);return res;
}
int dfs(int x,int prt)
{
	ld[x]=++dfst;int i,j,y,lf=1,nw=a[x],d=0;
	for(i=h[x];i;i=e[i].next)
	if((y=e[i].to)!=prt)
	{
		lf=0;++d;nw+=dfs(y,x);
		if(s[rt[x]]<s[rt[y]])sc[y]=1,swap(rt[x],rt[y]);
		tp=0;Dtc(rt[y]);for(j=1;j<=tp;j++)Ins(rt[x],w[st[j]],0,rt[x],st[j]);
	}
	if(lf){b[x]=0;return a[x];}g[x]=nw;
	int res=Seh(rt[x],nw,d),v=0,p;g1[x]=res;
	p=Fin(rt[x],res);
	v=p?(spl(p,rt[x]),s[c[p][0]]+1):0;
	b[x]=nw-v-res;
	if(p)r1[x]=p,rt[x]=c[p][1],pd(p),fa[c[p][1]]=0,c[p][1]=0,pus(p);
	if(res)Ad(rt[x],0,-res);
	v=d-b[x];
	while(v--)++tot,id[tot]=mx[tot]=mi[tot]=ld[x],Ins(rt[x],0,0,rt[x],tot);
	Ad(rt[x],1,0);rd[x]=dfst;return res;
}
vector<int>son;
void sp1(int p,int r){if(mx[p]<=r)return;pd(p);sp1(c[p][0],r);if(id[p]>r)st[++tp]=p;sp1(c[p][1],r);}
void sp2(int p,int r){if(mi[p]>r)return;pd(p);sp2(c[p][0],r);if(id[p]<=r)st[++tp]=p;sp2(c[p][1],r);}
inline int las(int &rt){int p=rt;while(c[p][1])p=c[p][1];if(p)spl(p,rt);return p;}
void dfs2(int x,int prt,LL t)
{
	int i,j,y,lf=1,d=0,ls,rs,p,o;LL nw=g[x]+t;
	for(i=h[x];i;i=e[i].next)if((y=e[i].to)!=prt)lf=0,++d;if(lf)return;
	LL res,v;p=Fin(rt[x],t);res=t-(p?(spl(p,rt[x]),s[c[p][0]]+1):0)+g1[x];
	Ad(rt[x],-1,0);p=Fin(rt[x],0);if(p)spl(p,rt[x]),pd(p),rt[x]=c[p][1],fa[c[p][1]]=0,c[p][1]=0;
	if(g1[x])Ad(rt[x],0,g1[x]);if(p=r1[x]){if(!rt[x])rt[x]=p;else{pd(p),c[p][1]=rt[x],fa[rt[x]]=p,pus(p),rt[x]=p;}}
	p=Fin(rt[x],res);v=p?(spl(p,rt[x]),s[c[p][0]]+1):0;a[x]=nw-v-res;
	son.clear();for(i=h[x];i;i=e[i].next)if((y=e[i].to)!=prt)son.push_back(y);
	while(!son.empty())
	{
		y=son.back();son.pop_back();tp=0;sc[y]?sp2(rt[x],ld[y]-1):sp1(rt[x],ld[y]-1);
		int &q=rt[y];q=0;p=0;
		for(j=1;j<=tp;j++)
		{
			o=st[j],spl(o,rt[x]),pd(o),ls=c[o][0],rs=c[o][1];
			if(ls){if(p){pd(p);c[p][1]=ls;fa[ls]=p;}else fa[p=ls]=0;c[o][0]=0;las(p);}
			rt[x]=rs,fa[rs]=0,c[o][1]=0,pus(o);
			if(q){las(q);pd(q);c[q][1]=o;fa[o]=q;pus(q);}else q=o;
		}
		if(rt[x]){if(p)pd(p),fa[c[p][1]=rt[x]]=p;else p=rt[x];las(p);}rt[x]=p;
		if(sc[y])swap(rt[x],q);
	}
	for(i=h[x];i;i=e[i].next)if((y=e[i].to)!=prt)dfs2(y,x,res);
}
int sum=0;LL w1[N];
int main(){
	mi[0]=0x3f3f3f3f;
	//freopen("sp.in","r",stdin);
	//freopen("sp.out","w",stdout);
	n=re();int i,x,y,d=0;
	for(i=1;i<n;i++)x=re(),y=re(),AddEdge(x,y),AddEdge(y,x);
	for(i=1;i<=n;i++)a[i]=re(),sum+=a[i];if(sum>n-2){printf("-1");return 0;}
	for(i=h[1];i;i=e[i].next)a[1]+=dfs(e[i].to,1),++d;
	for(i=2;i<=n;i++)a[i]=b[i];
	tp=0;for(i=h[1];i;i=e[i].next)dfs(rt[e[i].to]);
	sort(st+1,st+tp+1,[](int x,int y){return w[x]<w[y];});
	for(i=1;i<=tp;i++)w1[i]=w[st[i]];
	LL l=0,r=4ll*n*n*n,mid,res=-1,nw=a[1],v;
	while(l<=r){mid=(l+r)>>1;v=0;v=upper_bound(w1+1,w1+tp+1,mid)-w1-1;if(nw-v<d){res=mid;a[1]=nw-v;r=mid-1;}else l=mid+1;}
	for(i=h[1];i;i=e[i].next)dfs2(e[i].to,1,res);
	for(i=1;i<=n;i++)wr(a[i]),CH[++cn]=(i<n)?' ':'\n';fwrite(CH+1,1,cn,stdout);return 0;
}
