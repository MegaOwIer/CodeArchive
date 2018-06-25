#include<bits/stdc++.h>
using namespace std;

int n,sta[250005],ans,top,h;
char c;

inline void read(int& x)
{
	x=0,c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
}

int main()
{
	read(n),ans=n;
	while(n--)
	{
		read(h),read(h);
		while(top&&h<=sta[top])ans-=(sta[top--]==h);
		sta[++top]=h;
	}
	printf("%d",ans);
	return 0;
}
