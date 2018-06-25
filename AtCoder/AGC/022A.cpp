#include<bits/stdc++.h>
using namespace std;

int lth,vis[30];
char s[30];

int main()
{
    scanf("%s",s+1),lth=strlen(s+1);
    for(int i=1;i<=lth;i++)vis[s[i]-'a']=i;
    if(lth<26)
    {
        for(int i=0;i<26;i++)if(!vis[i])
            return printf("%s%c",s+1,'a'+i),0;
    }
    else for(int i=26;i;i--)
        for(int j=s[i]-'a'+1;j<26;j++)if(vis[j]>i)
        {
            s[i]='a'+j,s[i+1]=0;
            return printf("%s",s+1),0;
        }
    return puts("-1"),0;
}