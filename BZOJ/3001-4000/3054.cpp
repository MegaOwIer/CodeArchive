#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=100001;
typedef long long LL;

int n,an,o,xo,mxbt;
LL ans[35][3],all;
double tot[3];
bool A[maxn][35];
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
}

int main()
{
	read(n),all=1LL*n*n;
	for(int i=1,a,bit;i<=n;i++)
	{
		read(a),bit=0;
		while(a)
		{
            A[i][++bit]=1&a;
            a>>=1;
        }
        if(bit>mxbt)mxbt=bit;
	}
	for(int i=1;i<=mxbt;i++)
	{
		ans[i][1]=1LL*n*n,an=o=xo=0;
		for(int j=1;j<=n;j++)
		{
			if(A[j][i])
			{
				an++;
				if(!A[j-1][i])ans[i][1]-=1LL*o*o,o=0;
			}
			else
			{
				o++;
				if(A[j-1][i])ans[i][0]+=1LL*an*an,an=0;
			}
		}
		if(A[n][i])ans[i][0]+=1LL*an*an,an=0;
		else ans[i][1]-=1LL*o*o,o=0;
		for(int j=1;j<=n;j++)
		{
			A[j][i]^=A[j-1][i];
			if(A[j][i])xo++;
		}
		ans[i][2]=2LL*xo*(n+1-xo);
		for(int j=1;j<=n;j++)if(A[j][i]^A[j-1][i])ans[i][2]--;
	}
	for(int i=mxbt;i;i--)for(int j=0;j<3;j++) tot[j]=tot[j]*2+1.0*ans[i][j]/all;
	printf("%.3lf %.3lf %.3lf",tot[2],tot[0],tot[1]);
	return 0;
}
