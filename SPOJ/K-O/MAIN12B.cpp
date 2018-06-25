#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MX=1000005;

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
    template<typename T>void write(T x,int f=1)
    {
        tp=0;
        do bf[++tp]=x%10,x/=10;while(x);
        while(tp)putchar(48+bf[tp--]);
        if(f)putchar('\n');
    }
    void puts(const char* s)
    {
        int lth=strlen(s);
        for(int i=0;i<lth;i++)putchar(s[i]);
    }
}IO(stdin,stdout);
#define read(x) IO.read(x)
#define write(...) IO.write(__VA_ARGS__)
#define puts(x) IO.puts(x)

int T,cnt,pr[78500],tot,n;
LL v,ans[1105];
bool vis[MX];

int main()
{
    for(int i=2,tmp;i<=1e6;i++)
    {
        if(!vis[i])pr[++cnt]=i;
        for(int j=1;j<=cnt&&(tmp=i*pr[j])<=1e6;j++)vis[tmp]=1;
    }
    read(T);
    for(int i=1;i<=T;i++)
    {
        puts("Case #"),write(i,0),puts(": ");
        read(n),tot=0;
        for(int i=1;i<=n;i++)
        {
            read(v);
            if(v==1)continue;
            for(int j=1;(LL)pr[j]*pr[j]<=v;j++)if(v%pr[j]==0)
            {
                ans[++tot]=pr[j];
                while(v%pr[j]==0)v/=pr[j];
            }
            if(v>1)ans[++tot]=v;
        }
        sort(ans+1,ans+tot+1),tot=unique(ans+1,ans+tot+1)-ans-1;
        write(tot);
        for(int i=1;i<=tot;i++)write(ans[i]);
        puts("\n");
    }
    return 0;
}