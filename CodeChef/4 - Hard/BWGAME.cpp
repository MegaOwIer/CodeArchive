#include<bits/stdc++.h>
#include<ext/pb_ds/priority_queue.hpp>
using namespace std;

#define cin A_FAKE_ISTREAM
using pii=pair<int,int>;
const int MX=100005;

int T,N,pos[MX],id[MX];
__gnu_pbds::priority_queue<pii,greater<pii> > Q[MX];

struct Istream
{
	static const int MXL=2000000;
	char bf[MXL],*p1,*p2;
	FILE *F;
	
	Istream(FILE *F):p1(bf),p2(bf),F(F){}
	char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
	Istream& operator >> (int& x)
	{
		x=0;int c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		return *this;
	}
}cin(stdin);

int main()
{
	cin>>T;
	while(T--)
	{
		int res=1;
	    cin>>N;
		for(int i=1;i<=N;i++)Q[i].clear();
		for(int i=1;i<=N;i++)pos[i]=i,id[i]=i;
	    for(int i=1,L,R;i<=N;i++)
			cin>>L>>R,Q[L].push(make_pair(R,i));
		for(int i=1,tmp;i<=N&&res;i++)
		{
			while(!Q[i].empty()&&Q[i].top().first<i)Q[i].pop();
			if(Q[i].empty())res=0;
			else
			{
				if(pos[tmp=Q[i].top().second]!=i)
				{
					pos[id[i]]=pos[tmp];
					id[pos[tmp]]=id[i];
					res=-res;
				}
				int R=Q[i].top().first;
				Q[i].pop(),Q[R+1].join(Q[i]);
			}
		}
		if(!res)puts("Draw");
		else puts(res==1?"Alex":"Fedor");
	}
	return 0;
}
