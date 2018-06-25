#include<bits/stdc++.h>
using namespace std;

int T,n,flag,x,SG;

int main()
{
    for(scanf("%d",&T);T--;)
    {
        SG=flag=0;
        for(scanf("%d",&n);n--;)
        {
            scanf("%d",&x);
            if(x)SG^=x,flag|=(x!=1);
        }
        puts((SG&&flag)||(!SG&&!flag)?"John":"Brother");
    }
    return 0;
}