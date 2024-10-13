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
	int o=1;
	for(re int i=1;i<=n;++i){
		if(Rnd()%500>=V)o^=1;
		putchar(o?'L':'R');
	}
}
int main(){
	ID=2;
	Gen1(10);
	Gen1(10);
	Gen2(10,400);
	Gen2(10,450);
	Gen(500,'L');
	Gen(500,'R');
	Gen1(500-Rnd()%3);
	Gen1(500-Rnd()%3);
	Gen2(500-Rnd()%3,400);
	Gen2(500-Rnd()%3,450);
	Gen2(500-Rnd()%3,480);
	Gen2(500-Rnd()%3,490);
	Gen2(500-Rnd()%3,495);
	Gen2(500-Rnd()%3,496);
	Gen2(500-Rnd()%3,497);
	Gen2(500-Rnd()%3,498);
	Gen2(500-Rnd()%3,499);
}
