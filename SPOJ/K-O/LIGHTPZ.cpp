#include<bits/stdc++.h>
using namespace std;

class FastIn
{
private:
	static const int MXL=200000;
	char BF[MXL],*p1,*p2,c;
	char getchar(){return p1==p2?p2=(p1=BF)+fread(BF,1,MXL,stdin),p1==p2?EOF:*p1++:*p1++;}
public:
	FastIn():p1(BF),p2(BF){}
	template<typename T>void operator()(T& x)
	{
		x=0,c=getchar();
		while(!isdigit(c))c=getchar();
		while(isdigit(c))x=x*10+c-'0',c=getchar();
	}
}IN;
int T,N,a[55][55],ls[2505],tot,num,ans,vis[55],find_cnt,lm[55],rm[55];

inline bool find(int u,int mn,int mx)
{
	for(int i=1;i<=N;i++)if(a[u][i]>=mn&&a[u][i]<=mx&&vis[i]!=find_cnt)
	{
		vis[i]=find_cnt;
		if(!rm[i]||find(rm[i],mn,mx))
		{
			rm[i]=u,lm[u]=i;
			return 1;
		}
	}
	return 0;
}
inline bool Hungary(int mn,int mx)
{
	for(int i=1;i<=N;i++)if(!lm[i])
	{
		find_cnt++;
		if(!find(i,mn,mx))return 0;
	}
	return 1;
}

int main()
{
	IN(T);
	while(T--)
	{
		IN(N);
		tot=0,ans=2147483647;
		memset(lm+1,0,sizeof(int)*N);
		memset(rm+1,0,sizeof(int)*N);
		for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
			IN(a[i][j]),ls[++tot]=a[i][j];
		sort(ls+1,ls+tot+1),num=unique(ls+1,ls+tot+1)-ls-1;
		for(int l=1,r=1,mn;l<=num;l++)
		{
			mn=2147483647;
			while(!Hungary(ls[l],ls[r]))
				if(r<num)r++;
				else goto END_TAG;
			for(int i=1;i<=N;i++)mn=min(a[i][lm[i]],mn);
			while(ls[l]!=mn)l++;
			for(int i=1;i<=N;i++)if(a[i][lm[i]]==ls[l])rm[lm[i]]=0,lm[i]=0;
			ans=min(ans,ls[r]-ls[l]);
		}
END_TAG:
		printf("%d\n",ans);
	}
	return 0;
}
