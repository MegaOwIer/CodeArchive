#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,M,a[MX];
vector<int> pos;

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=1;i<=M;i++)
    {
        cin>>a[i];
        if(a[i]&1)pos.push_back(i);
    }
    if(pos.size()>2)return puts("Impossible"),0;
    if(M==1)
    {
        if(N==1)puts("1\n1\n1");
        else printf("%d\n2\n1 %d",a[1],a[1]-1);
        return 0;
    }
    if(pos.size()==1)swap(a[1],a[pos.front()]);
    if(pos.size()==2)swap(a[1],a[pos.front()]),swap(a[M],a[pos.back()]);
    for(int i=1;i<=M;i++)printf("%d ",a[i]);
    a[1]++,a[M]--;
    if(a[M]==0)M--;
    printf("\n%d\n",M);
    for(int i=1;i<=M;i++)printf("%d ",a[i]);
    return 0;
}
