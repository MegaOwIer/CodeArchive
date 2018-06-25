#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn=5e5+5,mod=232792561;
const LL w[]={0,1,232792560,5331435,102916856,168224104,5331436,16078828,117818975,
			    141493246,225776535,141975138,98826811,230306895,225314559,214938804,
				177346687,106275302,212741745,122332946,55698974,45613627,4511271};
#define mp make_pair
#define st first
#define nd second

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
		bf[tp=1]='\n'-48;
		do bf[++tp]=x%10,x/=10;while(x);
		while(tp)pc(48+bf[tp--]);
	}
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

int n,m,g[25][25],tot,res,xxj_cnt,jie[25];
LL A[maxn],k,tmp[25],x[25],TR[2][25][25],cc[25][25];
vector<pair<int,int> > d[25];

inline LL Pow(LL a,int b)
{
	LL ans=1;
	for(;b;b>>=1,a=a*a%mod)if(b&1)ans=ans*a%mod;
	return ans;
}
inline void dfs(int &id,int pos)
{
	if(pos>=m)
	{
		memcpy(TR[0][id],x,sizeof(LL)*m),id++;
		return;
	}
	int vecsiz=jie[pos]-1;
	LL tmp=w[vecsiz],gb=w[vecsiz];
	for(int i=1;i<=vecsiz;i++,tmp=tmp*gb%mod)
	{
		x[pos]=tmp;
		for(auto u:d[pos])if(x[u.st]*x[u.nd]%mod!=x[g[u.st][u.nd]])
			goto NXT_LOOP;
		dfs(id,pos+1);
NXT_LOOP:
		if(id>=m)return;
	}
	x[pos]=0;
	for(auto u:d[pos])if(x[u.st]*x[u.nd]%mod!=x[g[u.st][u.nd]])
		goto END_DFS;
	dfs(id,pos+1);
END_DFS:
	return;
}
inline void init()
{
	for(int i=0,j;i<m;i++)
		for(jie[i]=2,j=g[i][i];j!=i;j=g[j][i],jie[i]++);
	for(int i=0;i<m;i++)for(int j=0;j<=i;j++)
	{
		if(g[i][j]>i)d[g[i][j]].push_back(mp(i,j));
		else d[i].push_back(mp(i,j));
	}
	dfs(res,0);
	for(int i=0;i<m;i++)TR[1][i][i]=1;
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)cc[i][j]=TR[0][i][j];
	for(int i=0,j,k;i<m;i++)
	{
		if(!cc[i][i])for(j=i+1;j<m;j++)if(cc[j][i])
			{swap(cc[i],cc[j]),swap(TR[1][i],TR[1][j]);break;}
		for(j=i+1;j<m;j++)if(cc[j][i])
		{
			int u=cc[i][i],v=cc[j][i];
			for(k=0;k<m;k++)cc[i][k]=cc[i][k]*v%mod,TR[1][i][k]=TR[1][i][k]*v%mod;
			for(k=0;k<m;k++)cc[j][k]=cc[j][k]*u%mod,TR[1][j][k]=TR[1][j][k]*u%mod;
			for(k=0;k<m;k++)
				cc[j][k]=(cc[j][k]-cc[i][k]+mod)%mod,TR[1][j][k]=(TR[1][j][k]-TR[1][i][k]+mod)%mod;
		}
	}
	for(int i=m-1,j,k;~i;i--)
	{
		int tmp=Pow(cc[i][i],mod-2);
		for(j=0;j<m;j++)TR[1][i][j]=TR[1][i][j]*tmp%mod;
		for(j=i-1;~j;j--)for(k=0;k<m;k++)
			TR[1][j][k]=(TR[1][j][k]-TR[1][i][k]*cc[j][i]%mod+mod)%mod;
	}
}
inline void FWT(int l,int r,int f)
{
	if(l+1==r)return;
	int d=(r-l)/m;
	register int i,j,k,p;
	for(i=0;i<m;i++)FWT(l+d*i,l+d*(i+1),f);
	for(i=0;i<d;i++)
	{
		for(j=l,k=0;k<m;j+=d,k++)tmp[k]=A[j+i];
		for(j=l,k=0;k<m;j+=d,k++)
		{
			A[j+i]=0;
			for(p=0;p<m;p++)A[j+i]=(A[j+i]+TR[f][k][p]*tmp[p])%mod;
		}
	}
}

int main()
{
	read(n),read(m),read(k);
	k=(k+1)%(mod-1),tot=Pow(m,n);
	for(int i=0;i<m;i++)for(int j=0;j<m;j++)read(g[i][j]);
	init();
	for(int i=0;i<tot;i++)read(A[i]);
	FWT(0,tot,0);
	for(int i=0;i<tot;i++)A[i]=Pow(A[i],k);
	FWT(0,tot,1);
	for(int i=0;i<tot;i++)write(A[i]);
	return 0;
}
