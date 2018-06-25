#include<bits/stdc++.h>
using namespace std;
const int mod=19650827,MX=1005;

class FastIO
{
private:
    static const int MXL=200000;
    FILE *I,*O;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c,*const ED;
    int bf[22],tp;
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
    void putchar(char x){if(p3==ED)flush();*p3++=x;}
    void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
public:
    FastIO(FILE *I,FILE* O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),ED(OBF+MXL){}
    ~FastIO(){flush();}
    template<typename T>void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>void write(T x)
    {
        bf[tp=1]='\n'-48;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
    }
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

int n,a[MX],dp[MX][MX][2];

int main()
{
	read(n);
	for(int i=1;i<=n;i++)read(a[i]),dp[i][i][0]=1;
	for(int i=n-1;i;i--)for(int j=i+1;j<=n;j++)
	{
		if(a[i]<a[i+1])dp[i][j][0]+=dp[i+1][j][0];
		if(a[i]<a[j])dp[i][j][0]+=dp[i+1][j][1];
		if(a[j]>a[i])dp[i][j][1]+=dp[i][j-1][0];
		if(a[j]>a[j-1])dp[i][j][1]+=dp[i][j-1][1];
		dp[i][j][0]%=mod,dp[i][j][1]%=mod;
	}
	write((dp[1][n][0]+dp[1][n][1])%mod);
	return 0;
}