#include<bits/stdc++.h>
#include"sorting.h"
using namespace std;

const int MX=200005;

int p[MX],pi[MX],s[MX],si[MX];
vector<pair<int,int> > res;

int findSwapPairs(int N,int *a,int M,int *X,int *Y,int *P,int *Q)
{
	auto check=[N,X,Y,a](int val)
	{
		memcpy(s,a,sizeof(int)*N);
		for(int i=0;i<val;i++)swap(s[X[i]],s[Y[i]]);
		int used=0;
		for(int i=0;i<N;i++)while(s[i]!=i)swap(s[i],s[s[i]]),used++;
		return used<=val;
	};

    M=N-1;
    int L=0,R=M,ans=-1;
	while(L<=R)
	{
		int mid=L+R>>1;
		if(check(mid))R=(ans=mid)-1;
		else L=mid+1;
	}
	for(int i=0;i<N;i++)p[i]=pi[i]=i;
	for(int i=0;i<ans;i++)
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
	for(int i=0,x,y;i<ans;i++)
	{
		x=pi[X[i]],y=pi[Y[i]];
		swap(p[x],p[y]);
		pi[p[x]]=x,pi[p[y]]=y;
		pair<int,int> &cur=res[i];
		x=si[cur.first],y=si[cur.second];
		cur.first=p[x],cur.second=p[y];
		swap(s[x],s[y]);
		si[s[x]]=x,si[s[y]]=y;
	}
	for(int i=0;i<ans;i++)P[i]=res[i].first,Q[i]=res[i].second;
	return ans;
}
