#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod[]={0,20029,22277,23333};
 
int n,m,a[4][105],lth;
LL res;
bool vis[4][30000],fl,fail;
char A[10006];
vector<int> ans;
 
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=n;~i;i--)
    {
        scanf("%s",A),fl=0;
        if(A[0]=='-')fl=1,A[0]=48;
        lth=strlen(A);
        for(int j=1;j<4;j++)
        {
            for(int k=0;k<lth;k++)a[j][i]=(a[j][i]*10+A[k]-48)%mod[j];
            if(fl)a[j][i]=mod[j]-a[j][i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(vis[1][i%mod[1]]||vis[2][i%mod[2]]||vis[3][i%mod[3]])continue;
        fail=0;
        for(int k=1;k<4;k++)
        {
            res=0;
            for(int j=0;j<=n;j++)res=(res*i+a[k][j])%mod[k];
            if(res)vis[k][i%mod[k]]=1,fail=1;
        }
        if(!fail)ans.push_back(i);
    }
    printf("%d\n",ans.size());
    for(vector<int>::iterator it=ans.begin();it!=ans.end();++it)printf("%d\n",*it);
    return 0;
}
