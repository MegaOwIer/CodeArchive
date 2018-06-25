#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;
#define endl "\n"

int N;
LL a[MX],b[MX],c[MX];

int main()
{
    ios::sync_with_stdio(0);
    cin>>N;
    for(int i=1;i<=N;i++)cin>>a[i];
    sort(a+1,a+N+1,greater<LL>());
    for(int i=1,nxt,tp=0;i<=N;i=nxt)
    {
        int hb,ntp=0,mtp=0,cnt=0;
        for(hb=60;hb>=0&&(a[i]>>hb&1)==0;hb--);
        for(nxt=i;nxt<=N&&(a[nxt]>>hb&1);nxt++);
        for(int j=1;j<=tp;j++)cnt+=b[j]>>hb&1;
        if(nxt-i>cnt+1)return puts("No"),0;
        for(int j=i;j<nxt;j++)
        {
            c[++ntp]=a[j],c[++ntp]=b[++mtp];
            while(mtp<tp&&(b[mtp]>>hb&1)==0)c[++ntp]=b[++mtp];
        }
        while(mtp<tp)c[++ntp]=b[++mtp];
        tp=ntp;
        memcpy(b+1,c+1,sizeof(LL)*tp);
    }
    cout<<"Yes"<<endl;
    for(int i=1;i<=N;i++)cout<<b[i]<<' ';
    return 0;
}