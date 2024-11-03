#include<iostream>
#include<sstream>
#include<chrono>
#include<cstdio>
#include<windows.h>
using namespace std;
int main(){
	for(int i=1;i<=20;i++)
	{
		string str;
		stringstream tmp;tmp << i;tmp >> str;
		auto start = std::chrono::high_resolution_clock::now();
		cout<<("std.exe<"+(str)+".in>"+str+".ans").c_str()<<endl;
		system(("std.exe<"+str+".in>"+str+".ans").c_str());
		auto end = std::chrono::high_resolution_clock::now();
		auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
		printf("%d %d\n",i,duration);
	}
}
