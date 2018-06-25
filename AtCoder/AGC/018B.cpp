#include<bits/stdc++.h>
using namespace std;
const int MX=305;

class FastIO
{
private:
	static const int MXL=200000;
	char IBF[MXL],OBF[MXL],*p1,*p2,*p3,c;
	char *const END;
	int tp,bf[22],f;
	FILE *I,*O;
	char gc(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
	void pc(char c){if(p3==END)flush();*p3++=c;}
	void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
	
public:
	FastIO(FILE *I,FILE *O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),END(OBF+MXL){}
	~FastIO(){flush();}
	template<typename T>void read(T& x)
	{
		c=gc(),x=0,f=0;
		while(!isdigit(c)){if(c=='-')f=1;c=gc();}
		while(isdigit(c))x=x*10+c-'0',c=gc();
		if(f)x=-x;
	}
	template<typename T>void write(T x)
	{
		if(x<0)putchar('-'),x=-x;
		bf[tp=1]='\n'-48;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)pc(48+bf[tp--]);
	}
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

int N,M,a[MX][MX],it[MX],ans=400,tmp,cnt[MX];
bool used[MX];

int main()
{
	read(N),read(M);
	for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)read(a[i][j]);
	for(int i=1;i<=N;i++)it[i]=1;
	for(int i=1,mx;i<=M;i++)
	{
		memset(cnt+1,0,sizeof(int)*M);
		for(int j=1;j<=N;j++)
		{
			while(used[a[j][it[j]]])it[j]++;
			cnt[a[j][it[j]]]++;
		}
		mx=0;
		for(int j=1;j<=M;j++)if(cnt[j]>cnt[mx]&&!used[j])mx=j;
		ans=min(ans,cnt[mx]),used[mx]=1;
	}
	write(ans);
	return 0;
}
