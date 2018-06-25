#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

class FastIO
{
private:
	static const int MXL=200000;
	char IBF[MXL],OBF[MXL],*p1,*p2,*p3,c;
	char *const END;
	int tp,bf[22],f;
	FILE *I,*O;
	char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
	void putchar(char c){if(p3==END)flush();*p3++=c;}
	void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
	
public:
	FastIO(FILE *I,FILE *O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),END(OBF+MXL){}
	~FastIO(){flush();}
	template<typename T>void read(T& x)
	{
		c=getchar(),x=0,f=0;
		while(!isdigit(c)){if(c=='-')f=1;c=getchar();}
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		if(f)x=-x;
	}
	template<typename T>void write(T x)
	{
		if(x<0)putchar('-'),x=-x;
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)putchar(48+bf[tp--]);
		putchar('.'),putchar('0'),putchar('\n');
	}
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

int N,x[MX],M,id[MX],siz,a[MX];
LL K,k0,ans;
bool vis[MX];
vector<int> q;

int main()
{
	read(N);
	for(int i=1;i<=N;i++)read(x[i]);
	for(int i=N;i>1;i--)x[i]-=x[i-1];
	for(int i=1;i<=N;i++)id[i]=i;
	read(M),read(K);
	for(int i=1,u;i<=M;i++)read(u),swap(id[u],id[u+1]);
	for(int i=2;i<=N;i++)if(!vis[i])
	{
		q.clear();
		for(int j=i;!vis[j];j=id[j])q.push_back(j),vis[j]=1;
		siz=q.size(),k0=K%siz;
		for(int j=0;j<siz;j++)id[q[j]]=q[(j+k0)%siz];
	}
	for(int i=1;i<=N;i++)ans+=x[id[i]],write(ans);
	return 0;
}
