#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using LD=long double;
const int MX=1<<18|3;
#define endl "\n"
#define cin __JUMPMELON_DA_ZUI_ZI__

struct Istream
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*p2;
    FILE *F;
    Istream(FILE *F=stdin):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
    Istream& operator >> (int& x)
    {
        int c=0;x=0;
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return *this;
    }
}cin;

int N,a[MX],Q;
LL sum;

int main()
{
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(10);
    cin>>N>>Q;
    for(int i=0;i<(1<<N);i++)cin>>a[i],sum+=a[i];
    cout<<(LD)sum/(1<<N)<<endl;
    while(Q--)
    {
        int u,x;
        cin>>u>>x;
        sum=sum-a[u]+x;
        a[u]=x;
        cout<<(LD)sum/(1<<N)<<endl;
    }
    return 0;
}
