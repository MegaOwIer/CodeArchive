#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;

struct Bi {int id,n;}B[maxn];
int n,A[maxn];

bool operator < (Bi a,Bi b) {return a.n<b.n;}
bool operator > (Bi a,Bi b) {return a.id<b.id;}
template<typename T>
inline void read(T& x)
{
	x=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  x=x*10+ch-'0',ch=getchar();
}

int main()
{
	read(n);
	for(int i=1;i<=n;i++)  read(A[i]);
	for(int i=1,b;i<=n;i++)  read(b),B[i]=(Bi){i,b};
	sort(B+1,B+n+1);sort(A+1,A+n+1,greater<int>());
	for(int i=1;i<=n;i++)  B[i].n=A[i];
	sort(B+1,B+n+1,greater<Bi>());
	for(int i=1;i<=n;i++)  printf("%d ",B[i].n);
	return 0;
}
