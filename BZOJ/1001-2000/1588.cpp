#include<bits/stdc++.h>
using namespace std;

int f,ans,n;
char c;
set<int> s;
set<int>::iterator it1,it2;

inline void read(int& x)
{
	f=1,c=getchar(),x=0;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))x=x*10+c-'0',c=getchar();x*=f;
}

int main()
{
	s.insert(-10000000),s.insert(10000000);
	read(n),read(ans),s.insert(ans);
	for(int i=1,a;i<n;i++)
	{
		read(a);
		it1=s.lower_bound(a),it2=it1,--it1;
		ans+=min((*it2)-a,a-(*it1));
		s.insert(a);
	}
	printf("%d",ans);
	return 0;
}
