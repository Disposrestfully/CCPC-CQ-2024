#include<bits/stdc++.h>
#define re register
using namespace std;
mt19937 Rnd(1145141);
int ID;
void Gen1(int n){
	++ID;
	cerr<<"Generating test "<<ID<<"\n";
	string tmp=to_string(ID)+".in";
	freopen(tmp.c_str(),"w",stdout);
	printf("%d\n",n);
	for(re int i=1;i<=n;++i)putchar(Rnd()&1?'L':'R');
}
void Gen(int n,char c){
	++ID;
	cerr<<"Generating test "<<ID<<"\n";
	string tmp=to_string(ID)+".in";
	freopen(tmp.c_str(),"w",stdout);
	printf("%d\n",n);
	for(re int i=1;i<=n;++i)putchar(c);
}
void Gen2(int n,int V){
	++ID;
	cerr<<"Generating test "<<ID<<"\n";
	string tmp=to_string(ID)+".in";
	freopen(tmp.c_str(),"w",stdout);
	printf("%d\n",n);
	int o=Rnd()%2;
	for(re int i=1;i<=n;++i){
		if(Rnd()%500>=V)o^=1;
		putchar(o?'L':'R');
	}
}
int main(){
	ID=3;
	Gen1(10);
	Gen1(10);
	Gen2(1000-Rnd()%3,100);
	Gen2(1000-Rnd()%3,10);
	Gen2(1000-Rnd()%3,1);
	Gen2(1000-Rnd()%3,0);
	Gen1(1000-Rnd()%3);
	Gen1(1000-Rnd()%3);
	Gen(100000,'L');
	Gen(100000,'R');
	Gen1(100000-Rnd()%3);
	Gen1(100000-Rnd()%3);
	Gen2(100000-Rnd()%3,100);
	Gen2(100000-Rnd()%3,10);
	Gen2(100000-Rnd()%3,1);
	Gen2(100000-Rnd()%3,0);
}
