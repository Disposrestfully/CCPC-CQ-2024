#include"testlib.h"
using namespace std;
int a,b,p,q,g;
const long long maxc=1e9;
long long gcd(long long a1,long long a2){
    if(a2==0)return a1;
    else return gcd(a2,a1%a2);
}
void readInput(){
    a=inf.readInt();
    b=inf.readInt();
    q=b,p=a;
}
long long readAns(InStream& in,int test){
    long long c=in.readLong(0,maxc);
    long long d=in.readLong(1,maxc);
    if(c<0){
       quitf(_wa,"Invalid answer(c=%lld).(Testcase %d)",c,test);
        //quitf(_wa,"Invalid answer");
    }
    long long k=p*d+q*c,w=q*d;
    long long g=gcd(k,w);
    w/=g;
    while(w%2==0){
        w/=2;
    }
    while(w%5==0){
        w/=5;
    }
    if(w>1){
        quitf(_wa,"The result is not terminating.(Testcase %d)",test);
     //   quitf(_wa,"The result is not terminating.");
    }
    return c;
}
int main(int argc,char* argv[]){
	// registerTestlibCmd(4,argv);
	//registerTestlibCmd(argc,argv);
	registerLemonChecker(argc, argv);
	int t=inf.readInt();
	for(int i=1;i<=t;i++){
	    readInput();
	    long long jans=readAns(ans,i);
	    long long pans=readAns(ouf,i);
	    if(jans<pans){
	        quitf(_wa,"Jury found better answer than participant's %lld < %lld (Testcase %d)",jans,pans,i);
	    //	quitf(_wa,"Jury found better answer than participant's");
	    }
	    if(jans>pans){
	        quitf(_fail,"Participant found better answer than jury's %lld > %lld (Testcase %d)",jans,pans,i);
	    	//quitf(_fail,"Participant found better answer than jury's");
	    }
	}
	quitf(_ok,"%d case(s)",t);
}
