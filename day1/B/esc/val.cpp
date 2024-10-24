#include<bits/stdc++.h>
#define cmin(a,b) (a>(b)?a=(b),1:0)
#define cmax(a,b) (a<(b)?a=(b),1:0)
#define dmin(a,b) ((a)<(b)?(a):(b))
#define dmax(a,b) ((a)>(b)?(a):(b))
namespace io{
	int F(){
		int n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
	long long G(){
		long long n=0,F=0;
		char ch;
		while((ch=getchar())!='-'&&(ch<'0'||ch>'9'));
		ch=='-'?F=1:n=ch-'0';
		while((ch=getchar())>='0'&&ch<='9')n=n*10+ch-'0';
		return F?-n:n;
	}
}
const int M=1000000007;
char s[111111];
int sum[2][3005];
int sq[2][3005];
int cnt[2][3005];
int lenp,len;
int main(){
	scanf("%s",s);
    int k=io::F(),p=io::F();
    len=strlen(s);
    assert(len>=1&&len<=100000);
    assert(k>=1&&k<=3000);
    assert(p>=1&&p<=3000);
    lenp=len%p;
    for(int i=0;i<len;++i){
        assert(s[i]>=33&&s[i]<=126);
        if(s[i]=='\''){
            sq[0][i%p]+=1;
        }
        sum[0][i%p]+=s[i];
        cnt[0][i%p]+=1;
    }
    int *f=sum[0],*g=sum[1];
    int *x=sq[0],*y=sq[1];
    int *c=cnt[0],*d=cnt[1];
    for(int i=1;i<=k;++i){
        memset(g,0,sizeof(sum[0]));
        memset(y,0,sizeof(sq[0]));
        memset(d,0,sizeof(cnt[0]));
        #define UPD(x,id,v) x[(id)%p]=(x[(id)%p]+1ll*v)%M 
        for(int j=0;j<p;++j){
            UPD(g,j*5,c[j]*' ');
            UPD(g,j*5+1,x[j]*'"');
            UPD(g,j*5+1,(c[j]+M-x[j])*'\'');
            UPD(g,j*5+2,f[j]);
            UPD(g,j*5+3,x[j]*'"');
            UPD(g,j*5+3,(c[j]+M-x[j])*'\'');
            UPD(g,j*5+4,c[j]*',');

            UPD(y,j*5+1,c[j]+M-x[j]);
            UPD(y,j*5+3,c[j]+M-x[j]);

            for(int o=0;o<=4;++o){
                UPD(d,j*5+o,c[j]);
            }
        }
        UPD(g,0,M+'['-' ');
        UPD(g,lenp*5+p-1,M+']'-',');
        lenp=5ll*lenp%p;
        std::swap(f,g);
        std::swap(x,y);
        std::swap(c,d);
    }
    for(int i=0;i<p;++i){
        printf("%d%c",f[i]," \n"[i==p-1]);
    }
	return 0;
}