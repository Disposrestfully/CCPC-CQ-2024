#include<bits/stdc++.h>
using namespace std;

int main(){
	int N = 1e6; cout << N << '\n';
	for(int i = 1 ; i <= 1000 ; ++i){
		int cur = (i - 1) * 1000;
		for(int j = 2 ; j <= 500 ; ++j) cout << cur + j - 1 << ' ' << cur + j << '\n';
		for(int j = 501 ; j <= 1000 ; ++j) cout << cur + 500 << ' ' << cur + j << '\n';
		if(i != 1) cout << cur - 1000 + 1 << ' ' << cur + 1 << '\n';
	}
	cout << 988888 << ' ';
	for(int i = 2 ; i <= 1e6 ; ++i) cout << 0 << ' ';
	return 0;	
}