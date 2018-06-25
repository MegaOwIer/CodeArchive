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
		tp=0;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)pc(48+bf[tp--]);
	}
	void putstr(const char* s)
	{
		while(*s)pc(*s++);
		pc('\n');
	}
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)
#define puts(x) IO.putstr(x)

struct point
{
	int x,y,c,u,v;
	LL w;
	point(){}
	point(int x,int y,int c):x(x),y(y),c(c),u(x-y),v(x+y){w=4LL*(y-c)*y;}
	bool operator < (const point& a)const{return v<a.v;}
}p[MX];
int T,N,stk[MX],top,R[MX];
LL dp[MX],mx[MX];

inline int find1(int u)
{
	int l=0,r=u-1,mid;
	while(l<r)
	{
		mid=l+r+1>>1;
		if(p[mid].v<=p[u].u)l=mid;
		else r=mid-1;
	}
	return l;
}
inline LL calc(int u,int v){return dp[u]-(LL)(p[u].v-v)*(p[u].v-v);}
inline int find2(int u)
{
	int l=1,r=top,mid;
	while(l<r)
	{
		mid=l+r>>1;
		if(R[stk[mid]]>=p[u].u)r=mid;
		else l=mid+1;
	}
	return stk[l];
}
inline int find3(int u)
{
	int l=R[stk[top-1]],r=R[stk[top]],mid;
	while(l<r)
	{
		mid=(LL)l+r+1>>1;
		if(calc(stk[top],mid)<=calc(u,mid))r=mid-1;
		else l=mid;
	}
	return l;
}

int main()
{
	read(T);
	R[0]=p[0].u=p[0].v=-2100000000;
	while(T--)
	{
		read(N),stk[top=1]=0;
		for(int i=1,x,y,c;i<=N;i++)read(x),read(y),read(c),p[i]=point(x,y,c);
		sort(p+1,p+N+1);
		for(int i=1;i<=N;i++)
		{
			dp[i]=max(mx[find1(i)],calc(find2(i),p[i].u))+p[i].w;
			while(top>1&&calc(stk[top],R[stk[top-1]]+1)<=calc(i,R[stk[top-1]]+1))top--;
			R[stk[top]]=find3(i);
			R[i]=p[i].v;
			stk[++top]=i,mx[i]=max(mx[i-1],dp[i]);
		}
		write(mx[N]>>2);
		switch(mx[N]&3)
		{
			case 0:puts(".00");break;
			case 1:puts(".25");break;
			case 2:puts(".50");break;
			case 3:puts(".75");break;
		}
	}
	return 0;
}
