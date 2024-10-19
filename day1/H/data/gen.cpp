#include<iostream>
#include<algorithm>
#include<cstring>
#include<sstream>
#include<cstdio>
using namespace std;
#define N 1000012
int fa[N],rt=1,c[N];
int st[N<<2],tp;
void gen1(int n,int a)
{
	int i,j,x;st[1]=st[2]=rt;tp=2;
	for(i=1;i<=n;i++)fa[i]=0;
	for(i=2;i<=n;i++)
	{
		j=1ll*rand()*rand()%tp+1;x=st[j];swap(st[j],st[tp]);tp--;
		fa[i]=x;st[++tp]=i;while(1ll*rand()*rand()%a==0){st[++tp]=i;if(tp>2*n)swap(st[1ll*rand()*rand()%tp+1],st[tp]),tp--;}
	}
}
void genc(int n,int ty)
{
	for(int i=1;i<=n;i++)c[i]=0;
	if(ty)c[1ll*rand()*rand()%n+1]=n/2+1;
	else
	{
		int nu=n/2+1;
		while(nu--)++c[1ll*rand()*rand()%n+1];
	}
}
void Out(int n)
{
	printf("%d\n",n);int i;
	for(i=2;i<=n;i++)printf("%d %d\n",fa[i],i);
	for(i=1;i<=n;i++)printf("%d ",c[i]);
}
int main(){
	srand(1437);
	for(int i=1;i<=20;i++)
	{
		string str;
		stringstream tmp;tmp << i;tmp >> str;
		freopen((str+".in").c_str(),"w",stdout);
		if(i==1){gen1(6,2);genc(6,0);Out(6);}
		else if(i==2){gen1(12,3);genc(12,0);Out(12);}
		else if(i==3){gen1(40,4);genc(40,0);Out(40);}
		else if(i<=12){gen1(5000,50);genc(5000,1);Out(5000);}
		else if(i<=14){gen1(1000000,30);genc(1000000,1);Out(1000000);}
		else if(i<=16){gen1(1000000,1000);genc(1000000,1);Out(1000000);}
		else if(i<=18){gen1(1000000,1000000);c[1000000]=1000000-2;Out(1000000);}
		else if(i<=20){gen1(1000000,10000);genc(1000000,1);Out(1000000);}
	}
	return 0;
}
