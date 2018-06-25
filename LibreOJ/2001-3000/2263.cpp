#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

struct FastIn
{
	static const int MXL=400000;
	char bf[MXL],*p1,*p2,c;
	FILE *F;
	FastIn(FILE *F):p1(bf),p2(bf),F(F){}
	char getchar(){return p1==p2?p2=(p1=bf)+fread(bf,1,MXL,F),p1==p2?EOF:*p1++:*p1++;}
	void operator () (int& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
	void operator () (double& x)
	{
		static double tmp;
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		tmp=0.1,c=getchar();
		while(isdigit(c))x+=(c-'0')*tmp,tmp*=0.1,c=getchar();
	}
};

int win[MX],x,N,M;
char opt;
double P[MX],Q[MX],Val[MX],Ans;
FastIn IN(stdin);
set<int> S;
set<int>::iterator pre,nxt;

struct Segment
{
	struct Matrix
	{
		double val[2][2];
		Matrix(){memset(val,0,sizeof(val));}
		double* operator [] (int u){return val[u];}
		const double* operator [] (int u)const{return val[u];}
		Matrix operator + (const Matrix&);
		Matrix operator * (const Matrix&);
	}Fr,Sum;
	void set(int index)
	{
		Fr[0][0]=1-Q[index],Fr[1][0]=1-P[index];
		Fr[0][1]=Sum[0][1]=Q[index];
		Fr[1][1]=Sum[1][1]=P[index];
	}
}p[MX<<2];
inline Segment::Matrix Segment::Matrix::operator + (const Segment::Matrix& a)
{
#define work(i,j) ans[i][j]=val[i][j]+a[i][j]
	static Segment::Matrix ans;
	work(0,0),work(0,1),work(1,0),work(1,1);
	return ans;
#undef work
}
inline Segment::Matrix Segment::Matrix::operator * (const Segment::Matrix& a)
{
	static Segment::Matrix ans;
	ans[0][0]=val[0][0]*a[0][0]+val[0][1]*a[1][0];
	ans[0][1]=val[0][0]*a[0][1]+val[0][1]*a[1][1];
	ans[1][0]=val[1][0]*a[0][0]+val[1][1]*a[1][0];
	ans[1][1]=val[1][0]*a[0][1]+val[1][1]*a[1][1];
	return ans;
}
#define lson p[id<<1]
#define rson p[id<<1|1]
void build(int L,int R,int id)
{
	if(L==R)return p[id].set(L);
	int mid=L+R>>1;
	build(L,mid,id<<1),build(mid+1,R,id<<1|1);
	p[id].Fr=lson.Fr*rson.Fr;
	p[id].Sum=lson.Sum*rson.Fr+lson.Fr*rson.Sum;
}
void Query(int l,int r,int L,int R,int id,Segment::Matrix& t,Segment::Matrix& s)
{
	if(l<=L&&R<=r)
	{
		s=s*p[id].Fr+t*p[id].Sum;
		t=t*p[id].Fr;
		return;
	}
	int mid=L+R>>1;
	if(l<=mid)Query(l,r,L,mid,id<<1,t,s);
	if(r>mid)Query(l,r,mid+1,R,id<<1|1,t,s);
}
#undef lson
#undef rson
double Find(int L,int R)
{
	double res=0;
	Segment::Matrix t,s;
	t[0][0]=t[1][1]=1;
	Query(L+1,R,1,N,1,t,s);
	return Val[L]=s[win[L]][win[R]]/t[win[L]][win[R]];
}

int main()
{
	IN(N),IN(M),N++;
	memset(win,-1,sizeof(int)*N);
	IN(Q[1]);
	for(int i=2;i<N;i++)IN(P[i]),IN(Q[i]);
	S.insert(0),win[0]=0;
	S.insert(N),win[N]=0;
	build(1,N,1),Ans=Find(0,N);
	while(M--)
	{
		do opt=IN.getchar();while(!isalpha(opt));
		IN(x);
		if(opt=='a')
		{
			S.insert(x);
			pre=nxt=S.find(x);
			pre--,nxt++;
			Ans-=Val[*pre];
			IN(win[x]);
			Ans+=Find(*pre,x)+Find(x,*nxt);
		}
		else
		{
			pre=nxt=S.find(x);
			pre--,nxt++;
			Ans-=Val[*pre]+Val[x];
			Ans+=Find(*pre,*nxt);
			win[x]=-1;
			S.erase(x);
		}
		printf("%.6lf\n",Ans);
	}
	return 0;
}