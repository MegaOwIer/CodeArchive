#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1000000;

class FastIO
{
private:
    static const int MXL=200000;
    FILE *I,*O;
    char IBF[MXL],*p1,*p2,OBF[MXL],*p3,c,*const ED;
    int bf[22],tp;
    char getchar(){return p1==p2?(p2=(p1=IBF)+fread(IBF,1,MXL,I)),p1==p2?EOF:*p1++:*p1++;}
    void putchar(char x){if(p3==ED)flush();*p3++=x;}
    void flush(){fwrite(OBF,1,p3-OBF,O),p3=OBF;}
public:
    FastIO(FILE *I,FILE* O):I(I),O(O),p1(IBF),p2(IBF),p3(OBF),ED(OBF+MXL){}
    ~FastIO(){flush();}
    template<typename T>void read(T& x)
    {
        x=0,c=getchar();
        while(!isdigit(c))c=getchar();
        while(isdigit(c))x=x*10+c-'0',c=getchar();
    }
    template<typename T>void write(T x)
    {
        bf[tp=1]='\n'-48;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
    }
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(x) IO.write(x)

int n,type;
LL ans,pre,nxt;
set<LL> s;
set<LL>::iterator it;

int main()
{
    read(n);
    s.insert(-1e18),s.insert(1e18);
    for(int i=1,t,v;i<=n;i++)
    {
        read(t),read(v);
        if(s.size()==2)type=t,s.insert(v);
        else if(type==t)s.insert(v);
        else
        {
            it=s.lower_bound(v);
            nxt=*it,pre=*--it;
            if(nxt-v<v-pre)s.erase(nxt),ans=(ans+nxt-v)%mod;
            else s.erase(pre),ans=(ans+v-pre)%mod;
        }
    }
    write(ans);
    return 0;
}