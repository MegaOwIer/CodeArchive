#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,1,0,-1},dy[]={1,0,-1,0};

int R,C;
char s[505][505];

int main()
{
	scanf("%d%d",&R,&C);
	for(int i=1;i<=R;i++)scanf("%s",s[i]+1);
	for(int i=1;i<=R;i++)for(int j=1;j<=C;j++)if(s[i][j]=='W')
		for(int k=0;k<4;k++)
		{
			if(s[i+dx[k]][j+dy[k]]=='S')return puts("No"),0;
			else if(s[i+dx[k]][j+dy[k]]=='.')s[i+dx[k]][j+dy[k]]='D';
		}
	puts("Yes");
	for(int i=1;i<=R;i++)printf("%s\n",s[i]+1);
	return 0;
}
