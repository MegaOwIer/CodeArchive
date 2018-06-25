#include<bits/stdc++.h>
using namespace std;
const int MX=10005;

int N;
double ex[MX],ans=1.0;

int main()
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++)ex[i]=ex[i-1]+(double)N/(N-i+1);
	for(int i=1;i<N;i++)
		ans+=2*ex[i]*N/(N-i)+(double)N*(N+i)/(N-i)/(N-i);
	printf("%.2lf",(ex[N]+ans)/2);
	return 0;
}
