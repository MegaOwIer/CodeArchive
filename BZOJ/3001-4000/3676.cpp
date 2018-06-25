#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=300005;

char s[MX];

struct PalindromeAutomaton
{
    struct Node
    {
        Node *fail,*son[26];
        int len,siz;
    }*root[2],Pool[MX],*last,*ptr;
    int siz;

    PalindromeAutomaton()
    {
        siz=0,ptr=Pool;
        last=root[0]=newNode(0);
        root[1]=newNode(-1);
        root[0]->fail=root[1];
    }
    Node* newNode(int len)
    {
        ptr->len=len,ptr->siz=0;
        ptr->fail=NULL;
        memset(ptr->son,0,sizeof(ptr->son));
        return ptr++;
    }
    void extend(int val,int id)
    {
        Node *p=last;
        while(s[id-p->len-1]!=s[id])p=p->fail;
        if(p->son[val]!=root[0])
        {
            Node *now=newNode(p->len+2),*k=p->fail;
            while(k&&s[id]!=s[id-k->len-1])k=k->fail;
            now->fail=k?k->son[val]:root[0];
            p->son[val]=now;
        }
        last=p->son[val],last->siz++;
    }
    void build(char *s)
    {
        int N=strlen(s+1);
        for(int i=1;i<=N;i++)extend(s[i]-'a',i);
    }
    LL solve()
    {
        LL ans=0;
        for(Node *i=ptr-1;i>root[1];i--)
            i->fail->siz+=i->siz,ans=max(ans,(LL)i->siz*i->len);
        return ans;
    }
}PT;

int main()
{
    scanf("%s",s+1),s[0]=-1;
    PT.build(s);
    printf("%lld\n",PT.solve());
    return 0;
}
/*
abacaba

*/