#include<bits/stdc++.h>
using namespace std;
const int MX=2005;

int N,P,cnt[5],num;
char s[MX];
bool flag;

inline int getid(char s){return isdigit(s)?s-48:2;}

int main()
{
    ios::sync_with_stdio(0);
    cin>>N>>P>>(s+1);
    for(int i=1;i<=P;i++)
    {
        num=cnt[0]=cnt[1]=cnt[2]=0;
        for(int j=i;j<=N;j+=P)cnt[getid(s[j])]++;
        num=cnt[0]+cnt[1]+cnt[2];
        if(num==1)
            if(s[i]=='.')s[i]='0';
            else;
        else
        {
            if(num==cnt[0]||num==cnt[1])continue;
            flag=true;
            if(num==cnt[0]+cnt[1])continue;
            if(num==cnt[2])
            {
                s[i]='1';
                for(int j=i+P;j<=N;j+=P)s[j]='0';
                continue;
            }
            for(int j=i;j<=N;j+=P)if(s[j]=='.')
                s[j]=cnt[0]?'1':'0';
        }
    }
    if(!flag)puts("No");
    else cout<<(s+1)<<endl;
    return 0;
}
