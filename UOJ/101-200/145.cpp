#include<bits/stdc++.h>
using namespace std;

int n,x,y,ans[42][42];

int main()
{
    scanf("%d",&n),x=1,y=n+1>>1;
    for(int i=1;i<=n*n;i++)
    {
        ans[x][y]=i;
        x--;if(!x)x=n;y++;if(y>n)y=1;
        if(ans[x][y])
        {
            x+=2;if(x>n)x-=n;
            y--;if(!y)y=n;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)printf("%d ",ans[i][j]);
        puts("");
    }
    return 0;
}
