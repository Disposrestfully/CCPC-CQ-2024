#include<bits/stdc++.h>
#define re register
using namespace std;
struct Poly998244353{
	const int M=998244353;
	inline int ksm(re int x,re int y){
		re int s=1;
		while(y){
			if(y&1)s=1ll*s*x%M;
			x=1ll*x*x%M,y>>=1;
		}
		return s;
	}
	inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
	inline int Mod(re int x){return x>=M?x-M:x;}
	inline void Out(vector<int>A){
		puts("\n--------");
		printf("%d\n",A.size());
		for(re int i=0;i<A.size();++i)printf("%d ",A[i]);
		puts("");
		puts("--------\n");
	}
	int N,W[2097152],rev[2097152],wi[2097152];
	inline void pre(re int n){
		re int wn=ksm(3,(M-1)/n);N=n;
		for(re int i=W[0]=1;i<n;++i)W[i]=1ll*W[i-1]*wn%M;
	}
	inline int make(re int n){
		re int l=ceil(log2(n));n=1<<l;
		for(re int i=0;i<n;++i)rev[i]=rev[i>>1]>>1|((i&1)<<(l-1));
		return n;
	}
	inline void NTT(vector<int>&A,re int n,re int f){
		for(re int i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
		for(re int i=1;i<n;i<<=1){
			for(re int j=0;j<i;++j)wi[j]=W[f==1?j*(N/(i<<1)):(j?(N-j*(N/(i<<1))):j)];
			for(re int j=0;j<n;j+=i<<1)
				for(re int k=j;k<j+i;++k){
					re int x=A[k],y=1ll*A[k+i]*wi[k-j]%M;
					add(A[k],y),A[k+i]=Mod(x-y+M);
				}
		}
		if(f==-1){
			re int iv=ksm(n,M-2);
			for(re int i=0;i<n;++i)A[i]=1ll*A[i]*iv%M;
		}
	}
	inline void mul(vector<int>A,vector<int>B,vector<int>&C){
		re int k=make(A.size()+B.size()-1),o=A.size()+B.size()-1;
		A.resize(k),B.resize(k),C.resize(k);
		NTT(A,k,1),NTT(B,k,1);
		for(re int i=0;i<k;++i)C[i]=1ll*A[i]*B[i]%M;
		NTT(C,k,-1),C.resize(o);
	}
}Poly998;
struct Poly1004535809{
	const int M=1004535809;
	inline int ksm(re int x,re int y){
		re int s=1;
		while(y){
			if(y&1)s=1ll*s*x%M;
			x=1ll*x*x%M,y>>=1;
		}
		return s;
	}
	inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
	inline int Mod(re int x){return x>=M?x-M:x;}
	inline void Out(vector<int>A){
		puts("\n--------");
		printf("%d\n",A.size());
		for(re int i=0;i<A.size();++i)printf("%d ",A[i]);
		puts("");
		puts("--------\n");
	}
	int N,W[2097152],rev[2097152],wi[2097152];
	inline void pre(re int n){
		re int wn=ksm(3,(M-1)/n);N=n;
		for(re int i=W[0]=1;i<n;++i)W[i]=1ll*W[i-1]*wn%M;
	}
	inline int make(re int n){
		re int l=ceil(log2(n));n=1<<l;
		for(re int i=0;i<n;++i)rev[i]=rev[i>>1]>>1|((i&1)<<(l-1));
		return n;
	}
	inline void NTT(vector<int>&A,re int n,re int f){
		for(re int i=0;i<n;++i)if(i<rev[i])swap(A[i],A[rev[i]]);
		for(re int i=1;i<n;i<<=1){
			for(re int j=0;j<i;++j)wi[j]=W[f==1?j*(N/(i<<1)):(j?(N-j*(N/(i<<1))):j)];
			for(re int j=0;j<n;j+=i<<1)
				for(re int k=j;k<j+i;++k){
					re int x=A[k],y=1ll*A[k+i]*wi[k-j]%M;
					add(A[k],y),A[k+i]=Mod(x-y+M);
				}
		}
		if(f==-1){
			re int iv=ksm(n,M-2);
			for(re int i=0;i<n;++i)A[i]=1ll*A[i]*iv%M;
		}
	}
	inline void mul(vector<int>A,vector<int>B,vector<int>&C){
		re int k=make(A.size()+B.size()-1),o=A.size()+B.size()-1;
		A.resize(k),B.resize(k),C.resize(k);
		NTT(A,k,1),NTT(B,k,1);
		for(re int i=0;i<k;++i)C[i]=1ll*A[i]*B[i]%M;
		NTT(C,k,-1),C.resize(o);
	}
}Poly100;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
const int HM=10000019;
struct Hash{
	int H[HM+1],cnt,nx[4000002],id[4000002],to[4000002];
	inline Hash(){memset(H,cnt=0,sizeof(H));}
	inline int& operator [] (const int x){
		int p=x%HM;
		for(int i=H[p];i;i=nx[i])if(to[i]==x)return id[i];
		return nx[++cnt]=H[p],to[H[p]=cnt]=x,id[cnt];
	}
	inline bool Ask(const int x){
		int p=x%HM;
		for(int i=H[p];i;i=nx[i])if(to[i]==x)return 1;
		return 0;
	}
}mp;
int n,G,pw,B,Log[100002],Inv,Iv=ksm(1004535809-M,M-2),L[100002],R[100002],ans[100002];
char s[100002],ip[100002];
inline int Ask(int x){
	int s=0;
	while(!mp.Ask(x))x=1ll*x*Inv%M,++s;
	return mp[x]+s;
}
inline vector<int> Conv(vector<int>A,vector<int>B){
	vector<int>C1,C2,C;
	Poly998.pre(Poly998.make(A.size()+B.size())),Poly100.pre(Poly100.make(A.size()+B.size()));
	Poly998.mul(A,B,C1),Poly100.mul(A,B,C2),C.resize(C1.size());
	for(re int i=0;i<C.size();++i){
		long long tmp=C2[i];
		int dlt=Mod(C1[i]-C2[i]%M+M);
		tmp+=1ll*dlt*Iv%M*1004535809;
		C[i]=tmp%(M-1);
	}
	return C;
}
int main(){
	n=read(),G=3,B=300,Log[1]=0,pw=1;
	for(int i=1;i<=B;++i)pw=1ll*pw*G%M;
	re int ss=1;Inv=ksm(3,M-2);
	for(int i=0;i<=M;i+=B)mp[ss]=i,ss=1ll*ss*pw%M;
	for(int i=2;i<=n;++i){
		if(!ip[i]){
			Log[i]=Ask(i);
			for(int j=2;j*i<=n;++j)
				Log[j*i]=(Log[i]+Log[j])%(M-1),ip[j*i]=1;
		}
	}
	scanf("%s",s+1);
	vector<int>A,B,C;A.resize(n+1),B.resize(n+1);
	for(re int i=0;i<=n;++i)A[i]=(Log[i]-Log[i+1]+M-1)%(M-1);
	for(re int i=1;i<=n;++i)B[i]=(s[i]=='R')?1:0;
	C=Conv(A,B);
	for(re int i=1;i<=n;++i)L[i]=C[i];
	for(re int i=1;i<=n;++i)B[i]=(s[i]=='L')?1:0;
	reverse(A.begin(),A.begin()+n+1);
	C=Conv(A,B);
	for(re int i=1;i<=n;++i)R[i]=C[i+n];
	for(re int i=1;i<n;++i)if(s[i]=='L'&&s[i+1]=='R')ans[i]=ans[i+1]=ksm(3,L[i]+R[i+1]);
	if(s[1]=='R')ans[1]=ksm(3,R[1]);
	if(s[n]=='L')ans[n]=ksm(3,L[n]);
	re int fac=1;
	for(re int i=1;i<=n;++i)fac=1ll*i*fac%M;
	for(re int i=1;i<n;++i)printf("%d ",1ll*ans[i]*fac%M);printf("%d",1ll*fac*ans[n]%M);
}



