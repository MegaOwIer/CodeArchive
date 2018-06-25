#include<bits/stdc++.h>
using namespace std;
const int MX=23;
const double eps=1e-8;

int N,M,t,p,idn[MX],idm[MX];
double a[MX][MX],res[MX],b[MX];

inline void pivot(int l,int p)
{
	swap(idm[l],idn[p]);
	double tmp=-a[l][p];
	a[l][p]=-1;
	for(int i=0;i<=N;i++)
		if(fabs(a[l][i])<=eps)a[l][i]=0;
		else a[l][i]/=tmp;
	for(int i=0;i<=M;i++)if(i^l)
		if(fabs(a[i][p])<=eps)a[i][p]=0;
		else
		{
			tmp=a[i][p],a[i][p]=0;
			for(int j=0;j<=N;j++)a[i][j]+=a[l][j]*tmp;
		}
}
double simplex()
{
	int l,p;
	double mn,tmp;
	while(1)
	{
		l=M+1,p=N+1;
		idm[l]=idn[p]=N+M+1;
		mn=1e18;
		for(int i=1;i<=N;i++)
			if(a[0][i]>eps&&idn[i]<idn[p])
				p=i;
		if(p==N+1)return a[0][0];
		for(int i=1;i<=M;i++)if(a[i][p]<-eps)
		{
			tmp=a[i][0]/-a[i][p];
			if(tmp<mn-eps||tmp<eps+mn&&idm[i]<idm[l])
				l=i,mn=tmp;
		}
		if(l==M+1)puts("Unbounded"),exit(0);
		pivot(l,p);
	}
}
double solve()
{
	double tmp=0;
	int p=0;
	for(int i=1;i<=M;i++)if(a[i][0]<tmp)
		tmp=a[i][0],p=i;
	for(int i=1;i<=N;i++)idn[i]=i;
	for(int i=1;i<=M;i++)idm[i]=N+i;
	if(fabs(tmp)<eps)return simplex();
	for(int i=0;i<=N;i++)b[i]=a[0][i],a[0][i]=0;
	idn[++N]=0,a[0][N]=-1;
	for(int i=1;i<=M;i++)a[i][N]=1;
	pivot(p,N);
	if(simplex()<-eps)puts("Infeasible"),exit(0);
	for(int i=1;i<=M;i++)if(!idm[i])
	{
		for(int j=1;j<=N;j++)if(fabs(a[i][j])>eps)
		{
			pivot(i,j);
			break;
		}
		break;
	}
	p=0;
	for(int i=1;i<=N;i++)if(!idn[i])p=i;
	for(int i=0;i<=M;i++)swap(a[i][p],a[i][N]);
	swap(idn[p],idn[N]),N--;
	for(int i=1;i<=M;i++)if(idm[i]<=N)
		for(int j=0;j<=N;j++)a[0][j]+=a[i][j]*b[idm[i]];
	for(int i=1;i<=N;i++)if(idn[i]<=N)a[0][i]+=b[idn[i]];
	return simplex();
}

int main()
{
	scanf("%d%d%d",&N,&M,&t);
	for(int i=1;i<=N;i++)scanf("%lf",&a[0][i]);
	for(int i=1;i<=M;i++)
	{
		for(int j=1;j<=N;j++)
			scanf("%lf",&a[i][j]),a[i][j]=-a[i][j];
		scanf("%lf",&a[i][0]);
	}
	printf("%.10lf\n",solve());
	if(t)
	{
		for(int i=1;i<=M;i++)
			if(idm[i]<=N)res[idm[i]]=a[i][0];
		for(int i=1;i<=N;i++)printf("%.10lf ",res[i]);
	}
	return 0;
}
