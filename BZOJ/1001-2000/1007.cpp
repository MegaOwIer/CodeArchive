#include<bits/stdc++.h>
using namespace std;
const int maxn=50005;
const double eps=1e-8;

struct line{double k,b;int id;}e[maxn],sta[maxn];
int n,tp;
bool ans[maxn],fl;

inline bool operator < (line a,line b){return a.k<b.k||(fabs(a.k-b.k)<eps&&a.b>b.b);}
inline double getx(line& a,line& b){return (b.b-a.b)/(a.k-b.k);}

int main()
{
	scanf("%d",&n);
	if(n==1)return puts("1"),0;
	for(int i=1;i<=n;i++)scanf("%lf%lf",&e[i].k,&e[i].b),e[i].id=i;
	sort(e+1,e+n+1);
	for(int i=1;i<=n;i++,fl=0)
	{
		while(tp)
		{
			if(fabs(sta[tp].k-e[i].k)<eps){fl=1;break;}
			if(tp>1&&getx(e[i],sta[tp])<=getx(sta[tp],sta[tp-1]))tp--;
			else break;
		}
		if(!fl)sta[++tp]=e[i];
	}
	for(int i=1;i<=tp;i++)ans[sta[i].id]=1;
	for(int i=1;i<=n;i++)if(ans[i])printf("%d ",i);
	return 0;
}
