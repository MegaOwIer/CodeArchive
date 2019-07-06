#include<bits/stdc++.h>
using namespace std;
const int MX=100005;

int N,Q;
char s[MX][13],t[13];

struct Trie
{
    map<char,Trie*> son;
    int id;

    Trie():id(0){son.clear();}
}*TR[MX];

#define str s[id]
void insert(Trie* &o,Trie *p,int id,int it)
{
    o=new Trie;
    if(p)o->son=p->son,o->id=p->id;
    if(!str[it]){o->id=id;return;}
    insert(o->son[str[it]],p&&p->son.count(str[it])?p->son[str[it]]:NULL,id,it+1);
}
#undef str
int getans(Trie *o)
{
    int lth=strlen(t+1);
    for(int i=1;i<=lth;i++)
    {
        if(!o->son.count(t[i]))break;
        o=o->son[t[i]];
    }
    while(!o->id)o=o->son.begin()->second;
    printf("%s\n",s[o->id]+1);
}

int main()
{
    scanf("%d",&N);
    for(int i=1;i<=N;i++)
        scanf("%s",s[i]+1),insert(TR[i],TR[i-1],i,1);
    scanf("%d",&Q);
    for(int i=1,R;i<=Q;i++)
        scanf("%d%s",&R,t+1),getans(TR[R]);
    return 0;
}
