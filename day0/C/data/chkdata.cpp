#include <bits/stdc++.h>
using namespace std;
char com[100];
int main () {
	for (int i=1;i<=40;i++) {
		printf("%d\n",i);
		sprintf(com,"val.exe < %d.in",i);
		system(com);
	}
	return 0;
}
