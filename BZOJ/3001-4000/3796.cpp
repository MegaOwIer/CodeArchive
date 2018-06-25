#include<bits/stdc++.h>
using namespace std;
const int MX=100005,MN=10005;

int l1,l2,l3,nxt[MN],L,flag[MX],SA[MX],rk[MX],Height[MX],tp[MX];
char s[MX<<1],t[MN];
bool vis[3];

inline void RadixSort(int m)
{
    static int num[MX];
    memset(num+1,0,sizeof(int)*m);
    for(int i=1;i<=L;i++)num[rk[tp[i]]]++;
    for(int i=2;i<=m;i++)num[i]+=num[i-1];
    for(int i=L;i;i--)SA[num[rk[tp[i]]]--]=tp[i];
}
inline int getid(int x,int lth)
{
    if(1<=x&&x<=l1&&(lth<l3||flag[x-1]==flag[x+lth-l3]))
        return 1;
    if(l1+2<=x&&x<=L&&(lth<l3||flag[x-1]==flag[x+lth-l3]))
        return 2;
    return 0;
}
inline bool check(int val)
{
    vis[1]=vis[2]=false;
    vis[getid(SA[1],val)]=true;
    for(int i=2;i<=L;i++)
        if(Height[i]>=val)vis[getid(SA[i],val)]=true;
        else
        {
            if(vis[1]&&vis[2])return true;
            vis[1]=vis[2]=false;
            vis[getid(SA[i],val)]=true;
        }
    return vis[1]&&vis[2];
}

int main()
{
    scanf("%s",s+1),l1=strlen(s+1);
    s[l1+1]='a'-1;
    scanf("%s",s+l1+2),l2=strlen(s+l1+2);
    L=l1+l2+1;
    scanf("%s",t+1),l3=strlen(t+1);
    nxt[1]=0;
    for(int i=2,j=0;i<=l3;i++)
    {
        while(j&&t[j+1]!=t[i])j=nxt[j];
        if(t[j+1]==t[i])j++;
        nxt[i]=j;
    }
    for(int i=1,j=0;i<=L;i++)
    {
        while(j&&s[i]!=t[j+1])j=nxt[j];
        if(s[i]==t[j+1])j++;
        if(j==l3)flag[i-l3+1]=1,j=nxt[j];
    }
    for(int i=1;i<=L;i++)flag[i]+=flag[i-1];
    for(int i=1;i<=L;i++)rk[i]=s[i],tp[i]=i;
    RadixSort(127);
#define cmp (tp[SA[i]]==tp[SA[i-1]]&&tp[SA[i]+w]==tp[SA[i-1]+w])
    for(int w=1,m=127,p,i;w<=L;w<<=1,m=p)
    {
        for(p=0,i=L-w+1;i<=L;i++)tp[++p]=i;
        for(i=1;i<=L;i++)if(SA[i]>w)tp[++p]=SA[i]-w;
        RadixSort(m),memcpy(tp+1,rk+1,sizeof(int)*L);
        rk[SA[1]]=p=1;
        for(i=2;i<=L;i++)rk[SA[i]]=cmp?p:++p;
    }
#undef cmp
    for(int i=1,j,k=0;i<=L;Height[rk[i++]]=k)
        for(k=k?k-1:k,j=SA[rk[i]-1];s[i+k]==s[j+k];k++);
    int l=0,r=L,mid,ans;
    while(l<=r)
        check(mid=l+r>>1)?l=mid+1,ans=mid:r=mid-1;
    printf("%d",ans);
    return 0;
}
