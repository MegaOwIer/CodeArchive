#include<bits/stdc++.h>
using namespace std;
const double eps=0.95;

class FastIO
{
private:
	static const int MXL=200000;
	char IBF[MXL],*p1,*p2,c;
	FILE *I;
	char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
	
public:
	FastIO(FILE *I):I(I),p1(IBF),p2(IBF){}
	template<typename T>void read(T& x)
	{
		c=getchar(),x=0;
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}IO(stdin);
#define read(x) IO.read(x)

int n,m,a[25],bl[25],sum[10];
double ave,ans=1e30;

void SA()
{
	int t,x,y;
	double tmp=0,T=10000,cur;
	memset(sum+1,0,sizeof(int)*m);
	for(int i=1;i<=n;i++)
		bl[i]=rand()%m+1,sum[bl[i]]+=a[i];
	for(int i=1;i<=m;i++)tmp+=(sum[i]-ave)*(sum[i]-ave);
	while(T>1)
	{
		T=T*eps,t=rand()%n+1,x=bl[t];
		if(T>500)y=min_element(sum+1,sum+m+1)-sum;
		else y=rand()%m+1;
		if(x==y)continue;
		cur=tmp;
		cur-=(sum[x]-ave)*(sum[x]-ave)+(sum[y]-ave)*(sum[y]-ave);
		sum[x]-=a[t],sum[y]+=a[t];
		cur+=(sum[x]-ave)*(sum[x]-ave)+(sum[y]-ave)*(sum[y]-ave);
		if(cur<tmp)bl[t]=y,tmp=cur;
		else if(rand()%10000>T)sum[x]+=a[t],sum[y]-=a[t];
		else bl[t]=y,tmp=cur;
	}
	ans=min(tmp,ans);
}

int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(a[i]),ave+=a[i];
	ave/=m;
	for(int i=1;i<=10000;i++)SA();
	printf("%.2lf",sqrt(ans/m));
	return 0;
}