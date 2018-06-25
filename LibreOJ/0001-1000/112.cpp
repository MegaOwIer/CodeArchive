#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=100005;

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

struct data
{
	int a,b,c,ans;
	bool operator < (const data& v){return a<v.a;}
}d[MX],tmp[MX];
int n,k,cnt[MX],tr[MX<<1];

inline void insert(int x,int f){for(;x<=k;x+=x&-x)tr[x]+=f;}
inline int ask(int x){int ans=0;for(;x;x-=x&-x)ans+=tr[x];return ans;}
void solve(int l,int r,int L,int R)
{
	if(l>=r)return;
	if(L==R)
	{
		sort(d+l,d+r+1);
		for(int i=l,j=l;j<=r;j++)
		{
			while(i<=r&&d[i].a==d[j].a)insert(d[i++].b,1);
			d[j].ans+=ask(d[j].b)-1;
		}
		for(int i=l;i<=r;i++)insert(d[i].b,-1);
		return;
	}
	int mid=L+R>>1,p1=l-1,p2=r+1,i,j;
	for(i=l;i<=r;i++)
	{
		if(d[i].c<=mid)tmp[++p1]=d[i];
		else tmp[--p2]=d[i];
	}
	memcpy(d+l,tmp+l,sizeof(data)*(r-l+1));
	sort(d+l,d+p1+1),sort(d+p2,d+r+1);
	for(i=l,j=p2;j<=r;j++)
	{
		while(i<=p1&&d[i].a<=d[j].a)insert(d[i++].b,1);
		d[j].ans+=ask(d[j].b);
	}
	for(j=l;j<i;j++)insert(d[j].b,-1);
	solve(l,p1,L,mid),solve(p2,r,mid+1,R);
}

int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++)read(d[i].a),read(d[i].b),read(d[i].c);
	solve(1,n,1,k);
	for(int i=1;i<=n;i++)cnt[d[i].ans]++;
	for(int i=0;i<n;i++)write(cnt[i]);
	return 0;
}