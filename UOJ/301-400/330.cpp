#include<bits/stdc++.h>
using namespace std;

int T,n,w,lth,cnt,sta[105],fa[105],it,ans,ans0;
char cpl[105],s[105],xh[105];
bool CE,ctrb[105],E[105];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %s\n",&n,cpl);
        w=CE=cnt=ans=0;
        memset(ctrb+1,0,n),memset(E+1,0,n),memset(fa+1,0,n<<2);
        if(cpl[2]!='1')
            for(int i=4;isdigit(cpl[i]);i++)w=w*10+cpl[i]-'0';
        for(int i=1,it,x,y;i<=n;i++)
        {
            gets(s);
            if(s[0]=='E')
            {
                E[i]=1;
                if(!cnt)CE=1;
                cnt--;
                continue;
            }
            xh[i]=s[2],sta[++cnt]=i;
            for(int j=1;j<cnt;j++)if(xh[i]==xh[sta[j]]){CE=1;break;}
            if(CE)continue;
            it=4,x=0,y=0;
            if(s[it]=='n')x=1000000,it++;
            else while(isdigit(s[it]))x=x*10+s[it]-48,it++;
            it++;
            if(s[it]=='n')y=1000000,it++;
            else while(isdigit(s[it]))y=y*10+s[it]-48,it++;
            if(x>y){fa[i]=-1;continue;}
            if(y-x>200)ctrb[i]=1;
            for(int j=i-1,ccc=0;~j;j--)
            {
                if(E[j]){ccc++;continue;}
                if(!ccc){fa[i]=j;break;}
                ccc--;
            }
            for(int j=i,ans0=0;;j=fa[j])
            {
                if(j<0)break;
                if(ctrb[j])ans0++;
                if(!j){ans=max(ans,ans0);break;}
            }
        }
        if(CE||cnt)puts("ERR");
        else puts(ans==w?"Yes":"No");
    }
    return 0;
}
