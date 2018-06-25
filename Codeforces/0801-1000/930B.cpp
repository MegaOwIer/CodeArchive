#include<bits/stdc++.h>
using namespace std;

int len,ans,res;
char s[10005],tmp[5005];
vector<int> v[30];

inline int check(int index,int pos)
{
    int cnt=0,ans=0;
    for(int i:v[index])tmp[++cnt]=s[i+pos];
    sort(tmp+1,tmp+cnt+1);
    for(int i=1,j=1;i<=cnt;i=j)
    {
        while(tmp[i]==tmp[j]&&j<=cnt)j++;
        if(j-i==1)ans++;
    }
    return ans;
}

int main()
{
    scanf("%s",s+1),len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        s[len+i]=s[i];
        v[s[i]-'a'].push_back(i);
    }
    for(int i=0;i<26;i++)if(!v[i].empty())
    {
        res=0;
        for(int j=1;j<len;j++)res=max(res,check(i,j));
        ans+=res;
    }
    printf("%.8lf",(double)ans/len);
    return 0;
}
