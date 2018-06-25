#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

class FastIO
{
private:
    static const int MXL=200000;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c;
    char *const ED;
    int tp,bf[22];
    FILE *I,*O;
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
    void putchar(char c){if(p3==ED)flush();*p3++=c;}
    void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
public:
    FastIO(FILE *I,FILE *O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),ED(OBF+MXL){}
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

struct edge
{
	int u,v,w;
	bool operator < (const edge& a){return w<a.w;}
}e[500005];
int n,m,fa[200005],res;
LL ans;

inline int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}

int main()
{
	read(n),read(m),res=n-1;
	for(int i=1;i<=m;i++)read(e[i].u),read(e[i].v),read(e[i].w);
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(e+1,e+m+1);
	for(int i=1,f1,f2;res;i++)
	{
		f1=find(e[i].u),f2=find(e[i].v);
		if(f1==f2)continue;
		fa[f1]=f2,ans+=e[i].w,res--;
	}
	write(ans);
	return 0;
}