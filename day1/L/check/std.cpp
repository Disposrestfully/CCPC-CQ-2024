#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
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
int n;
char s1[N],s2[N];
int main(){
    n=read();
    assert(n>=1 && n<=100000);
    scanf("%s",s1+1);
    assert(strlen(s1+1)==n);
    scanf("%s",s2+1);
    assert(strlen(s2+1)==n);
    int flag=1;
    for (int i=1;i<=n;++i){
        assert(s1[i]=='0' || s1[i]=='1' || s1[i]=='2');
        assert(s2[i]=='0' || s2[i]=='1' || s2[i]=='2');
        if (s1[i]!='1' && s2[i]!='1') flag=0;
    }
    printf("%d\n",flag);
    return 0;
}