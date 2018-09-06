#include<bits/stdc++.h>
using namespace std;

#define endl "\n"
const int MX=10005;

int N,K,a[MX];
char s[MX];

inline void update(int &u,int v){if(u<v)u=v;}
int work(int N,int K)
{
    int head=0,tail=0,top=0;
    cin>>(s+1);
    for(int i=1,j=1;i<=N;i++)if(s[i]=='1')
    {
        j=i;
        while(s[j+1]=='1')j++;
        if(i==1)head=j;
        else if(j==N)tail=N-i+1;
        else a[++top]=j-i+1;
        i=j;
    }
    sort(a+1,a+top+1,greater<int>());
    for(int i=1;i<=top;i++)a[i]+=a[i-1];
    int cost=top*2+(head!=0)+(tail!=0)-(head!=0||top);
    if(cost<=K)return head+tail+a[top];
    if(K==0)return head;
    if(K==1)return max(head+tail,a[1]);
    int ans=0;
    update(ans,head+a[K/2]);
    update(ans,head+tail+a[(K-1)/2]);
    update(ans,a[(K+1)/2]);
    update(ans,tail+a[K/2]);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    while(cin>>N>>K)cout<<work(N,K)<<endl;
    return 0;
}
