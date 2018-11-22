#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int MX=100;
#define fi first
#define se second

int mx,mn,tmp,pos;
char s[MX];
vector<pii> res;

void output(int l,int r,int f)
{
    if(l<=-32768&&r>=32767)puts("true"),exit(0);
    if(l<=-32768)printf("x <= %d ",r);
    else if(r>=32767)printf("x >= %d ",l);
    else printf("x >= %d && x <= %d ",l,r);
    if(f)puts("||");
}

int main()
{
    freopen("hard.in","r",stdin);
    freopen("hard.out","w",stdout);
    while(cin.getline(s,100))
    {
        mn=-32768,mx=32767;
        sscanf(s+5,"%d",&tmp);
        if(s[2]=='>')mn=max(mn,tmp);
        else mx=min(mx,tmp);
        for(pos=0;s[pos]!='|'&&s[pos]!='&'&&s[pos];pos++);
        if(s[pos]=='&')
        {
            sscanf(s+pos+8,"%d",&tmp);
            if(s[pos+5]=='>')mn=max(mn,tmp);
            else mx=min(mx,tmp);
        }
        if(mn>mx)continue;
        res.push_back(make_pair(mn,mx));
    }
    sort(
        res.begin(),res.end(),
        [](const pii& a,const pii& b){return a.fi==b.fi?a.se>b.se:a.fi<b.fi;}
    );
    res.erase(
        unique(res.begin(),res.end(),[](const pii& a,const pii& b){return a.fi==b.fi;}),
        res.end()
    );
    if(!res.size())return puts("false"),0;
    mn=res[0].fi,mx=res[0].se;
    for(auto i:res)
        if(i.fi>mx+1)output(mn,mx,1),mn=i.fi,mx=i.se;
        else mx=max(mx,i.se);
    output(mn,mx,0);
    return 0;
}
