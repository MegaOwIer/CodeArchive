#include<bits/stdc++.h>
using namespace std;

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}

int main()
{
    for(int T=read();T--;)
    {
        int N=read(),d=read(),cnt=0;
        for(int i=1;i<=N;i++)cnt+=(read()==1);
        if(d==1)puts(cnt==N&&N%3==0?"No":"Yes");
        else puts(cnt==N&&N%3==1||cnt+1==N&&N%3==1||N%3==0&&cnt+1==N?"No":"Yes");
    }
    return 0;
}
