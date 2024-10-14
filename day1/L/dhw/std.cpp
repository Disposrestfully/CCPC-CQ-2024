#include<iostream>
#include<cstdio>
using namespace std;
int n;char s1[100005],s2[100005];
int main()
{
	cin>>n;
	cin>>s1;cin>>s2;
	for(int i=0;i<n;i++)
	{
		if(s1[i]!='1'&&s2[i]!='1')
		{
			cout<<0;return 0;
		}
	}
	cout<<1;
	return 0;
}
