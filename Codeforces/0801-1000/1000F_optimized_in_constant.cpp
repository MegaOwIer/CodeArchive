#include<bits/stdc++.h>
using namespace std;

using LL=long long;
using pii=pair<int,int>;
const int MX=500005;
#define cin SELF_DEFINED_ISTREAM
#define cout SELF_DEFINED_OSTREAM
#define endl '\n'

int N,a[MX],B,pos[MX],Q,ans[MX],cnt[MX],P[MX],*S=P;
bool vis[MX];

struct Ques{int l,r,id,posl;}q[MX];

struct Istream
{
    static const int MXL=2000000;
    char bf[MXL],*p1,*p2;
    FILE *F;

    Istream(FILE *F=stdin):p1(bf),p2(bf),F(F){}
    char getchar(){return p1==p2&&(p2=(p1=bf)+fread(bf,1,MXL,F))==bf?EOF:*p1++;}
    Istream& operator >> (int& x)
    {
        x=0;int c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
        return *this;
    }
}cin;

struct Ostream
{
    static const int MXL=200000;
    char bf[MXL],*p1,*const p2;
    int dig[12],top;
    FILE *F;

    Ostream(FILE *F=stdout):p1(bf),p2(bf+MXL),F(F){}
    ~Ostream(){flush();}
    void flush(){fwrite(bf,1,p1-bf,F),p1=bf;}
    void putchar(char c){if(p1==p2)flush();*p1++=c;}
    template<typename T>Ostream& operator << (T x)
    {
        if(typeid(T)==typeid(int))
        {
            top=0;
            do dig[++top]=x%10,x/=10;while(x);
            while(top)putchar(dig[top--]+48);
        }
        else if(typeid(T)==typeid(char))putchar(x);
        return *this;
    }
}cout;

inline void update(int pos,int flag)
{
    int val=a[pos];
    if(cnt[val]==1)vis[val]=true;
    cnt[val]+=flag;
    if(cnt[val]==1)
        if(!vis[val])*++S=val;
        else vis[val]=false;
}

int main()
{
    cin>>N,B=sqrt(N)*1.816;
    for(int i=1;i<=N;i++)pos[i]=i/B;
    for(int i=1;i<=N;i++)cin>>a[i];
    cin>>Q;
    for(int i=1,l,r;i<=Q;i++)
    {
        cin>>l>>r;
        q[i]=(Ques){l,r,i,pos[l]};
    }
    sort(q+1,q+Q+1,[](const Ques& a,const Ques& b){return a.posl<b.posl;});
    for(int i=1,j=1,nw=0;i<=Q;i=j,nw^=1)
    {
        while(q[i].posl==q[j].posl&&j<=Q)j++;
        sort(q+i,q+j,[nw](const Ques& a,const Ques& b){return nw?a.r>b.r:a.r<b.r;});
    }
    for(int i=1,l=1,r=0,tmp;i<=Q;i++)
    {
        while(r<q[i].r)update(++r,1);
        while(r>q[i].r)update(r--,-1);
        while(l<q[i].l)update(l++,-1);
        while(l>q[i].l)update(--l,1);
        while(S!=P&&vis[tmp=*S])vis[tmp]=false,--S;
        ans[q[i].id]=S==P?0:*S;
    }
    for(int i=1;i<=Q;i++)cout<<ans[i]<<endl;
    return 0;
}
