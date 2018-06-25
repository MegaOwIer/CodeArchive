#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class FastIO
{
private:
	static const int MXL=200000;
	char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c;
	char *const END;
	int bf[22],tp;
	FILE *IN,*OUT;
	char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,IN)),p1==p2?EOF:*p1++:*p1++;}
	void putchar(char x){if(p3==END)flush();*p3++=x;}
	void flush(){fwrite(OBF,1,p3-OBF,OUT),p3=OBF;}

public:
	FastIO(FILE *IN,FILE* OUT):IN(IN),OUT(OUT),p1(IBF),p2(IBF),p3(OBF),END(OBF+MXL){}
	~FastIO(){flush();}
	template<typename T>void read(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	template<typename T>void write(T x)
	{
		if(x<0)putchar('-'),x=-x;
		bf[tp=1]='\n'-48;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
	}
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

int T,n,r,t;
double R;

inline int gcd(int u,int v){return v?gcd(v,u%v):u;}
inline int f(int n,int a,int b,int c)
{
	if(!n)return 0;
	int GCD=gcd(a,gcd(b,c));
	a/=GCD,b/=GCD,c/=GCD;
	LL m=(R*b+c)/a,sum=(LL)n*(n+1)/2*m;
	c-=m*a,m=(b*R+c)/a*n,sum+=n*m;
	return sum-f(m,b*b*r-c*c,a*b,-a*c);
}

int main()
{
	read(T);
	while(T--)
	{
		read(n),read(r),R=sqrt(r),t=int(R);
		if(t*t==r)write(t&1?(n&1?-1:0):n);
		else write(n+4*f(n,2,1,0)-2*f(n,1,1,0));
	}
	return 0;
}