#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=998244353,MX=100005;

int N,c,d,b[MX],x[MX],f[MX],inv[MX];

struct FastIn
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*p2;
    FILE *F;

    FastIn(FILE* F):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F),p1==p2)?EOF:*p1++;}
    int operator () ()
    {
        int x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return x;
    }
}IN(stdin);

struct FastOut
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*const p2;
    int dig[13],top;
    FILE *F;
    
    FastOut(FILE *F):F(F),p1(bf),p2(bf+MXL){}
    ~FastOut(){flush();}
    void flush(){fwrite(bf,1,p1-bf,F),p1=bf;}
    void putchar(char c){if(p1==p2)flush();*p1++=c;}
    void operator () (int x,char end)
    {
        if(x<0)putchar('-'),x=-x;
        dig[top=1]=end-48;
        do dig[++top]=x%10,x/=10;while(x);
        while(top)putchar(48+dig[top--]);
    }
}OUT(stdout);

int getinv(int u){return u==1?1:LL(mod-mod/u)*getinv(mod%u)%mod;}
inline int Pow(int a,int b)
{
    int ans=1;
    for(;b;b>>=1,a=(LL)a*a%mod)
        if(b&1)ans=(LL)ans*a%mod;
    return ans;
}
inline void MobiusTransfer(int *f)
{
    for(int i=1;i<=N;i++)for(int j=i+i;j<=N;j+=i)
        f[j]=(f[j]-f[i]+mod)%mod;
}

int main()
{
    N=IN(),c=IN(),d=IN(),c-=d;
    d%=mod-1,c%=mod-1;
    if(c<0)c+=mod-1;
    for(int i=1;i<=N;i++)inv[i]=Pow(i,mod-1-d);
    for(int i=1;i<=N;i++)f[i]=Pow(i,c);
    MobiusTransfer(f);
    for(int i=1;i<=N;i++)if(f[i])f[i]=getinv(f[i]);
    for(int Q=IN();Q--;)
    {
        for(int i=1;i<=N;i++)b[i]=(LL)IN()*inv[i]%mod;
        MobiusTransfer(b);
        bool fail=false;
        for(int i=1;i<=N;i++)
        {
            if(b[i]&&!f[i])
            {
                fail=true;
                break;
            }
            b[i]=(LL)b[i]*f[i]%mod;
        }
        if(fail){OUT(-1,'\n');continue;}
        for(int i=N;i;i--)for(int j=i+i;j<=N;j+=i)
            b[i]=(b[i]-b[j]+mod)%mod;
        for(int i=1;i<=N;i++)OUT((LL)b[i]*inv[i]%mod,' ');
        OUT.putchar('\n');
    }
    return 0;
}
