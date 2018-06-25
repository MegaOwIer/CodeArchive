#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1000005,mod=1000000007;

int a,b,c,d;
string N,M;

struct Matrix
{
    int a[2][2];

    int* operator [] (int u){return a[u];}
    const int* operator [] (int u)const{return a[u];}
    void init(){a[0][0]=a[1][1]=1,a[0][1]=a[1][0]=0;}
    Matrix operator * (const Matrix& x)
    {
        static Matrix ans;
        for(int i=0;i<2;i++)for(int j=0;j<2;j++)
            ans[i][j]=((LL)a[i][0]*x[0][j]+(LL)a[i][1]*x[1][j])%mod;
        return ans;
    }
}C,L,TR;

inline void decrease(string &N)
{
    reverse(N.begin(),N.end()),N[0]--;
    for(int i=0;N[i]<'0';i++)N[i]+=10,N[i+1]--;
    if(N.empty())N="0";
    reverse(N.begin(),N.end());
}
Matrix Pow(Matrix a,int b)
{
    static Matrix ans;
    ans.init();
    for(;b;b>>=1,a=a*a)if(b&1)ans=ans*a;
    return ans;
}
Matrix Pow(Matrix a,string b)
{
    static Matrix ans,pw[10];
    ans.init();
    pw[0].init();
    for(int i=1;i<10;i++)pw[i]=pw[i-1]*a;
    for(int i=0;i<b.length();i++)
        ans=Pow(ans,10)*pw[b[i]-'0'];
    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>M>>C[0][0]>>C[0][1]>>L[0][0]>>L[0][1];
    C[1][1]=L[1][1]=1;
    decrease(N),decrease(M);
    C=Pow(C,M),TR=C*L;
    TR=Pow(TR,N)*C;
    cout<<(TR[0][0]+TR[0][1])%mod<<endl;
    return 0;
}
