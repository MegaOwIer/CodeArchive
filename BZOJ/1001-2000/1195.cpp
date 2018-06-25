 
#include<bits/stdc++.h>
using namespace std;
const int MX=12,INF=0x3f3f3f3f;
 
int N,dp[1<<MX][MX],anslen=INF,f[MX][MX],S,cnt=0;
bool invalid[MX];
string str[MX],ansstr[1<<MX][MX],res;
 
int DP(int S,int ed)
{
    if((1<<ed)==S)return str[ed].length();
    if(~dp[S][ed])return dp[S][ed];
    int ans=INF;
    string res;
    for(int i=0,tmp;i<N;i++)if(i!=ed&&((S>>i)&1))
    {
        tmp=DP(S^(1<<ed),i)+str[ed].length()-f[i][ed];
        if(tmp<ans)res=ansstr[S^(1<<ed)][i]+str[ed].substr(f[i][ed]),ans=tmp;
        else if(ans==tmp)res=min(res,ansstr[S^(1<<ed)][i]+str[ed].substr(f[i][ed]));
    }
    ansstr[S][ed]=res;
    return dp[S][ed]=ans;
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=0;i<N;i++)cin>>str[i];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)if(i!=j&&!invalid[j])
            if(str[j].find(str[i])!=string::npos)invalid[i]=1;
    for(int i=0;i<N;i++)if(!invalid[i])str[cnt++]=str[i];
    N=cnt,S=(1<<N)-1;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)if(i!=j)
    {
        int li=str[i].length(),lj=str[j].length();
        for(int k=min(li,lj);k;k--)
            if(str[i].substr(li-k,k)==str[j].substr(0,k))
                {f[i][j]=k;break;}
    }
    for(int i=0;i<N;i++)ansstr[1<<i][i]=str[i];
    memset(dp,-1,sizeof(dp));
    for(int i=0,tmp;i<N;i++)
    {
        tmp=DP(S,i);
        if(tmp<anslen)res=ansstr[S][i],anslen=tmp;
        else if(tmp==anslen)res=min(res,ansstr[S][i]);
    }
    cout<<res<<endl;
    return 0;
}
