#include<bits/stdc++.h>
using namespace std;
const int MX=200005;

int ans,cnt0,cnt1,lth,pos1[MX],pos0[MX],pre[MX],nxt[MX];
char s[MX];
bool vis[MX];


int main()
{
    scanf("%s",s+1);
    lth=strlen(s+1);
    for(int i=1;i<=lth;i++)
    {
    	if(s[i]=='0')pos0[++cnt0]=i;
    	else pos1[++cnt1]=i;
    	if(cnt1>cnt0)return puts("-1"),0;
    }
    cnt0=cnt1=0;
    for(int i=lth;i;i--)
    {
    	if(s[i]=='0')cnt0++;
    	else cnt1++;
    	if(cnt1>cnt0)return puts("-1"),0;
    }
    printf("%d\n",cnt0-cnt1);
    for(int i=1;i<=cnt1;i++)pre[pos1[i]]=pos0[i],nxt[pos0[i]]=pos1[i];
    for(int i=cnt1,j=cnt0;i;i--,j--)nxt[pos1[i]]=pos0[j],pre[pos0[j]]=pos1[i];
    for(int i=1;i<=lth;i++)if(!vis[i])
    {
    	int cnt=0;
    	for(int j=i;j;j=nxt[j])cnt++,vis[j]=1;
    	printf("%d ",cnt);
    	for(int j=i;j;j=nxt[j])printf("%d ",j);
    	putchar('\n');
    }
    return 0;
}
