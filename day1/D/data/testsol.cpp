#include <bits/stdc++.h>
using namespace std;
int n=50;
char com[100];
int main () {
	for (int i=1;i<=n;i++) {
		printf("Testcase: %d\n",i);
		sprintf(com,"sol.exe < %d.in > tmp.out",i);
		system(com);
		sprintf(com,"type %d.ans",i);
		system(com);
		sprintf(com,"type tmp.out");
		system(com);
		sprintf(com,"fc %d.ans tmp.out",i);
		system(com);
	}
	return 0;
}
