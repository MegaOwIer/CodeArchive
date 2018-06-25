#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

int Q,mod,T,num[MX<<2];

inline int read()
{
    int x=0,c=getchar();
    while(!isdigit(c))c=getchar();
    while(isdigit(c))x=x*10+c-'0',c=getchar();
    return x;
}
void modify(int pos,int v,int L,int R,int id)
{
    if(L==R){num[id]=v;return;}
    int mid=L+R>>1;
    if(pos<=mid)modify(pos,v,L,mid,id<<1);
    else modify(pos,v,mid+1,R,id<<1|1);
    num[id]=(LL)num[id<<1]*num[id<<1|1]%mod;
}

int main()
{
    for(T=read();T--;)
    {
        Q=read(),mod=read();
        fill(num+1,num+(Q<<2)+1,1);
        for(int i=1;i<=Q;i++)
        {
            int op=read(),v=read();
            if(op==1)modify(i,v,1,Q,1);
            else modify(v,1,1,Q,1);
            printf("%d\n",num[1]);
        }
    }
    return 0;
}