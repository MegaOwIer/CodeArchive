#include<bits/stdc++.h>
using namespace std;

const int MX=200005;
#define cin FAKE_ISTREAM

int N,M,a[MX],X[MX],Y[MX];
int p[MX],pi[MX],s[MX],si[MX];
vector<pair<int,int> > res;

struct Istream
{
	static const int MXL=2000000;
	char bf[MXL],*p1,*p2;
	FILE *F;
	Istream(FILE *F):p1(bf),p2(bf),F(F){}
	char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
	Istream& operator >> (int& x)
	{
		x=0;  int c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
		return *this;
	}
}cin(stdin);

bool check(int val)
{
	static int s[MX];
	memcpy(s,a,sizeof(int)*N);
	for(int i=1;i<=val;i++)swap(s[X[i]],s[Y[i]]);
	int used=0;
	for(int i=0;i<N;i++)while(s[i]!=i)swap(s[i],s[s[i]]),used++;
	return used<=val;
}

int main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>a[i];
	cin>>M;
	M=N-1;
	for(int i=1;i<=M;i++)cin>>X[i]>>Y[i];
	int L=0,R=M,ans;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))R=(ans=mid)-1;
		else L=mid+1;
	}
	printf("%d\n",ans);
	for(int i=0;i<N;i++)p[i]=pi[i]=i;
	for(int i=1;i<=ans;i++)
	{
		int x=pi[X[i]],y=pi[Y[i]];
		swap(p[x],p[y]);
		pi[p[x]]=x,pi[p[y]]=y;
	}
	for(int i=0;i<N;i++)s[i]=a[i],si[s[i]]=i;
	for(int i=0;i<N&&res.size()<=ans;i++)if(p[si[i]]!=i)
	{
		res.push_back(make_pair(i,s[pi[i]]));
		int x=si[i],y=si[s[pi[i]]];
		swap(s[x],s[y]),si[s[x]]=x,si[s[y]]=y;
	}
	while(res.size()<ans)res.push_back(make_pair(0,0));
	for(int i=0;i<N;i++)p[i]=pi[i]=i;
	for(int i=0;i<N;i++)s[i]=a[i],si[s[i]]=i;
	for(int i=1,x,y;i<=ans;i++)
	{
		x=pi[X[i]],y=pi[Y[i]];
		swap(p[x],p[y]);
		pi[p[x]]=x,pi[p[y]]=y;
		pair<int,int> &cur=res[i-1];
		x=si[cur.first],y=si[cur.second];
		cur.first=p[x],cur.second=p[y];
		swap(s[x],s[y]);
		si[s[x]]=x,si[s[y]]=y;
	}
	for(int i=0;i<ans;i++)printf("%d %d\n",res[i].first,res[i].second);
	return 0;
}

