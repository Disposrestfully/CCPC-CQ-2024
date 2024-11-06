#include<bits/stdc++.h>
using namespace std;
const int N=3005;
inline int read(){
    int x=0,w=1;
    char ch=0;
    while (ch<'0' || ch>'9'){
        ch=getchar();
        if (ch=='-') w=-1;
    }
    while (ch<='9' && ch>='0'){
        x=(x<<1)+(x<<3)+ch-'0';
        ch=getchar();
    }
    return x*w;
}
double ppmax;
double a,b,c,d,e,f;
double acc,pp;
int main(){
	for (int T = read(); T--; ) {
		ppmax=read();
		assert(ppmax>=0 && ppmax<=3000);
		a=read(),b=read(),c=read(),d=read(),e=read(),f=read();
		assert(a>=0 && a<=20000.0);
		assert(b>=0 && b<=20000.0);
		assert(c>=0 && c<=20000.0);
		assert(d>=0 && d<=20000.0);
		assert(e>=0 && e<=20000.0);
		assert(f>=0 && f<=20000.0);
		acc=(300.0*a+300.0*b+200.0*c+100.0*d+50.0*e)/(300.0*(a+b+c+d+e+f));
		double tmp=(320.0*a+300.0*b+200.0*c+100.0*d+50.0*e)/(320.0*(a+b+c+d+e+f));
		if (tmp>0.8) tmp-=0.8;
		else tmp=0;
		pp=ppmax*5.0*tmp;
		printf("%.2lf%c %d\n",acc*100, '\%',(int)pp);
	}
    return 0;
}