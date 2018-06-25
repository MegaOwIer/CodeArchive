#include<bits/stdc++.h>
using namespace std;
const int ans[]={0,1,1,2,3,0,3,3,1,4,0,4,4,3,2,0,2,2,4,1};

int N,x;
char s[2000500],*p=s;

inline void read(int& x)
{
    static char c;
    x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
}

int main()
{
    read(N);
    while(N--)read(x),*p++=48+ans[x%20],*p++='\n';
    fwrite(s,1,p-s,stdout);
    return 0;
}