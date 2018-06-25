#include<bits/stdc++.h>
using namespace std;
const int MX=205;
const char s[]="WING";

int W,I,N,G,L;
bool dp[MX][MX][4],trans[4][4][4],res;
char t[MX];

inline int getid(char c)
{
    if(c=='W')return 0;
    if(c=='I')return 1;
    if(c=='N')return 2;
    if(c=='G')return 3;
}

int main()
{
    scanf("%d%d%d%d",&W,&I,&N,&G);
    for(int i=1;i<=W;i++)
    {
        scanf("%s",t+1);
        trans[getid(t[1])][getid(t[2])][0]=true;
    }
    for(int i=1;i<=I;i++)
    {
        scanf("%s",t+1);
        trans[getid(t[1])][getid(t[2])][1]=true;
    }
    for(int i=1;i<=N;i++)
    {
        scanf("%s",t+1);
        trans[getid(t[1])][getid(t[2])][2]=true;
    }
    for(int i=1;i<=G;i++)
    {
        scanf("%s",t+1);
        trans[getid(t[1])][getid(t[2])][3]=true;
    }
    scanf("%s",t+1),L=strlen(t+1);
    for(int i=1;i<=L;i++)dp[i][1][getid(t[i])]=true;
    for(int j=2;j<=L;j++)for(int i=1;i+j-1<=L;i++)
        for(int k=i;k<i+j-1;k++)
            for(int c1=0;c1<4;c1++)if(dp[i][k-i+1][c1])
                for(int c2=0;c2<4;c2++)if(dp[k+1][i+j-1-k][c2])
                    for(int c3=0;c3<4;c3++)if(trans[c1][c2][c3])
                        dp[i][j][c3]=true;
    for(int i=0;i<4;i++)if(dp[1][L][i])putchar(s[i]),res=true;
    if(!res)puts("The name is wrong!");
    return 0;
}