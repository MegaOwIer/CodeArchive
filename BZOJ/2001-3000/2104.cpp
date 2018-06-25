#include<bits/stdc++.h>
using namespace std;
const int MX=100005,INF=0x3f3f3f3f;

class FastIO
{
private:
	static const int MXL=200000;
	char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c;
	char *const END;
	FILE *IN,*OUT;
	int tp,bf[22];
	void flush(){fwrite(OBF,1,p3-OBF,OUT),p3=OBF;}
	char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,IN)),p1==p2?EOF:*p1++:*p1++;}
	void putchar(char x){if(p3==END)flush();*p3++=x;}

public:
	FastIO(FILE *IN,FILE *OUT):IN(IN),OUT(OUT),p1(IBF),p2(IBF),p3(OBF),END(OBF+MXL){}
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

int N,a[6][MX],M;
struct Node
{
	int ll[6][6],rr[6][6],lr[6][6];
	
	void clear()
	{
		memset(ll,0x3f,sizeof(ll));
		memset(rr,0x3f,sizeof(rr));
		memset(lr,0x3f,sizeof(lr));
	}
	bool empty()const{return ll[0][0]==INF;}
	void init(int pos)
	{
		static int sum[6];
		sum[0]=a[0][pos];
		for(int i=1;i<6;i++)sum[i]=sum[i-1]+a[i][pos];
		for(int i=0;i<6;i++)for(int j=0;j<6;j++)
			ll[i][j]=rr[i][j]=lr[i][j]=sum[max(i,j)]-((i&&j)?sum[min(i,j)-1]:0);
	}
}p[MX<<2],Ls,Rs,Md;
#define lson p[id<<1]
#define rson p[id<<1|1]

inline void merge(const Node& a,const Node& b,Node& T)
{
	static int lm[6][6],rm[6][6];
	if(a.empty()){T=b;return;}
	if(b.empty()){T=a;return;}
	T.clear();
	memset(lm,0x3f,sizeof(lm));
	memset(rm,0x3f,sizeof(rm));
	for(int k=0;k<6;k++)for(int i=0;i<6;i++)for(int j=0;j<6;j++)
		lm[i][j]=min(lm[i][j],a.lr[i][k]+b.ll[k][j]+a.rr[j][j]),
		rm[i][j]=min(rm[i][j],b.ll[i][i]+a.rr[i][k]+b.lr[k][j]);
	for(int i=0;i<6;i++)for(int j=0;j<6;j++)
	{
		T.ll[i][j]=a.ll[i][j],T.rr[i][j]=b.rr[i][j];
		T.lr[i][j]=INF;
		for(int k=0;k<6;k++)
		{
			T.ll[i][j]=min(T.ll[i][j],lm[i][k]+a.lr[j][k]-a.rr[k][k]);
			T.rr[i][j]=min(T.rr[i][j],rm[k][i]+b.lr[k][j]-b.ll[k][k]);
			T.lr[i][j]=min(T.lr[i][j],a.lr[i][k]+b.lr[k][j]);
			T.lr[i][j]=min(T.lr[i][j],lm[i][k]+rm[k][j]-a.rr[k][k]-b.ll[k][k]);
		}
	}
}
inline void build(int l,int r,int id)
{
	if(l==r)return p[id].init(l);
	int mid=l+r>>1;
	build(l,mid,id<<1),build(mid+1,r,id<<1|1);
	merge(lson,rson,p[id]);
}
inline void change(int pos,int id,int L=1,int R=N)
{
	if(L==R)return p[id].init(pos);
	int mid=L+R>>1;
	if(pos<=mid)change(pos,id<<1,L,mid);
	else change(pos,id<<1|1,mid+1,R);
	merge(lson,rson,p[id]);
}
inline Node query(int l,int r,int id,int L=1,int R=N)
{
	if(L==l&&r==R)return p[id];
	int mid=L+R>>1;
	if(mid>=r)return query(l,r,id<<1,L,mid);
	else if(l>mid)return query(l,r,id<<1|1,mid+1,R);
	else
	{
		Node ls,rs,ans;
		ls=query(l,mid,id<<1,L,mid);
		rs=query(mid+1,r,id<<1|1,mid+1,R);
		merge(ls,rs,ans);
		return ans;
	}
}
inline int ask(int sx,int sy,int tx,int ty)
{
	Ls=query(1,sy,1),Md=query(sy,ty,1),Rs=query(ty,N,1);
	int ans=Md.lr[sx][tx];
	for(int i=0;i<6;i++)for(int j=0;j<6;j++)
	{
		ans=min(ans,Md.ll[sx][i]+Ls.rr[i][j]+Md.lr[j][tx]-a[i][sy]-a[j][sy]);
		ans=min(ans,Md.lr[sx][i]+Rs.ll[i][j]+Md.rr[j][tx]-a[i][ty]-a[j][ty]);
		ans=min(ans,Ls.rr[sx][i]+Md.lr[i][j]+Rs.ll[j][tx]-a[i][sy]-a[j][ty]);
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("shortest.in","r",stdin);
	freopen("shortest.out","w",stdout);
#endif
	read(N);
	for(int i=0;i<6;i++)for(int j=1;j<=N;j++)read(a[i][j]);
	build(1,N,1);
	read(M);
	for(int i=1,op,x,y,z,w;i<=M;i++)
	{
		read(op),read(x),read(y),read(z);
		if(op&1)a[x-1][y]=z,change(y,1);
		else
		{ 
			read(w);
			if(y>w)swap(y,w),swap(x,z);
			write(ask(x-1,y,z-1,w));
		}
	}
	return 0;
}

