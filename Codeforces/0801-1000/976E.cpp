#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=200005;

int N,a,b,hp[MX],dmg[MX],id[MX],del[MX],cnt;
LL sum,tms,d0,tmp,ans;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>a>>b;
    tms=1LL<<a;
    for(int i=1;i<=N;i++)
    {
        cin>>hp[i]>>dmg[i];
        del[i]=hp[i]-dmg[i];
        sum+=dmg[i],id[i]=i;
    }
    if(b==0)return cout<<sum<<endl,0;
    sort(id+1,id+N+1,[](int a,int b){return del[a]>del[b];});
    for(cnt=1;cnt<=N&&del[id[cnt]]>0;cnt++);
    cnt--;
    if(cnt<b)
    {
        for(int i=1;i<=cnt;i++)d0+=del[id[i]];
        for(int i=1;i<=cnt;i++)
            tmp=max(tmp,hp[id[i]]*(tms-1));
        for(int i=cnt+1;i<=N;i++)
            tmp=max(tmp,tms*hp[id[i]]-dmg[id[i]]);
        cout<<sum+d0+tmp<<endl;
    }
    else
    {
        for(int i=1;i<=b;i++)d0+=del[id[i]];
        for(int i=1;i<=b;i++)
            tmp=max(tmp,hp[id[i]]*(tms-1));
        ans=sum+d0+tmp;
        d0-=del[id[b]],tmp=0;
        for(int i=b+1;i<=N;i++)
            tmp=max(tmp,hp[id[i]]*tms-dmg[id[i]]);
        cout<<max(ans,sum+d0+tmp)<<endl;
    }
    return 0;
}