#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const unsigned MX=1000005,mod=2012182013;

struct Matrix
{
    ULL a[3][3];
    inline void clear(){memset(a,0,sizeof(ULL)*7),a[2][2]=1;}
    Matrix(){clear();}
    inline void init(){clear(),a[0][0]=a[1][1]=1;}
    inline ULL* operator [](int u){return a[u];}
    inline Matrix operator * (Matrix& b)
    {
        static Matrix ans;
        ans[0][0]=(a[0][0]*b[0][0]+a[0][1]*b[1][0])%mod;
        ans[0][1]=(a[0][0]*b[0][1]+a[0][1]*b[1][1])%mod;
        ans[0][2]=(a[0][0]*b[0][2]+a[0][1]*b[1][2]+a[0][2])%mod;
        ans[1][0]=(a[1][0]*b[0][0]+a[1][1]*b[1][0])%mod;
        ans[1][1]=(a[1][0]*b[0][1]+a[1][1]*b[1][1])%mod;
        ans[1][2]=(a[1][0]*b[0][2]+a[1][1]*b[1][2]+a[1][2])%mod;
        return ans;
    }
    inline void operator *= (Matrix& b){*this=*this*b;}
}A,B,C,D,PW[10];
ULL a,b,c,d,e,f;
unsigned Lm,Ln;
char n[MX],m[MX],ch;
 
template<typename T>inline void read(T& x)
{
    ch=getchar(),x=0;
    while(!isdigit(ch))ch=getchar();
    while(isdigit(ch))x=(x*10+ch-'0')%mod,ch=getchar();
}
inline Matrix Pow_10(Matrix& A,char* b)
{
    static Matrix ans,tmp;
    register int i;
    ans.init();
    for(i=1;i<10;++i)PW[i]=PW[i-1]*A;
    for(i=0;b[i];++i)
	{
		tmp=ans*ans;
		ans=tmp,ans*=ans,ans*=ans,ans*=tmp;
		ans*=PW[b[i]-48];
	}
    return ans;
}
 
int main()
{
	scanf("%s%s",n+1,m+1),PW[0].init();
    Lm=strlen(m+1),Ln=strlen(n+1);
    read(a),read(b),read(c),read(d),read(e),read(f);
    A[0][0]=b,A[0][1]=a,A[0][2]=c,A[1][0]=1;
    B[0][0]=e,B[0][1]=d,B[0][2]=f,B[1][0]=1;
    register int i;
    m[Lm]-=2;for(i=Lm;m[i]<'0';--i)m[i]+=10,m[i-1]--;
    n[Ln]--;for(i=Ln;n[i]<'0';--i)n[i]+=10,n[i-1]--;
    C=(D=Pow_10(A,m+1))*B*B,D=Pow_10(C,n+1)*D;
    printf("%llu",(D[0][0]+D[0][1]+D[0][2])%mod);
    return 0;
}
