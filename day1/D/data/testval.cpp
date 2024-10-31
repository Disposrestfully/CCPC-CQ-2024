#include <bits/stdc++.h>
using namespace std;
int n=50;
char com[100];
int main () {
	for (int i=1;i<=n;i++) {
		printf("Testcase: %d\n",i);
		sprintf(com,"val.exe < ./%d.in",i);
		system(com);
	}
	return 0;
}
