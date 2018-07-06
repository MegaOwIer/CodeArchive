#include<bits/stdc++.h>
using namespace std;
 
using LL=long long;
using Poly=vector<int>;
using LD=long double;
const int MX=262145,mod=1000000007;
const LD pi=acosl(-1.0);
 
int T,P,rev[MX],K,X;
string N;

struct Complex
{
	LD x,y;
	Complex(){}
	Complex(LD x,LD y=0):x(x),y(y){}
	Complex operator + (Complex a){return Complex(x+a.x,y+a.y);}
	Complex operator - (Complex a){return Complex(x-a.x,y-a.y);}
	Complex operator * (Complex a){return Complex(x*a.x-y*a.y,x*a.y+y*a.x);}
	void operator /= (LD X){x/=X,y/=X;}
}w[MX],A[MX],B[MX];

inline int getmod(string s,int mod)
{
    int res=0;
    for(char i:s)res=(res*10+i-'0')%mod;
    return res;
}
inline void inc(string &s)
{
    reverse(s.begin(),s.end());
    s[0]++,s.push_back('0');
    for(int i=0;s[i]>'9';i++)s[i]-=10,s[i+1]++;
    if(s.back()=='0')s.pop_back();
    reverse(s.begin(),s.end());
}
inline string divide(string s,int mod)
{
    string ans;
    int res=0;
    for(char i:s)
    {
        res=res*10+i-'0';
        ans.push_back(res/mod+'0'),res%=mod;
    }
    reverse(ans.begin(),ans.end());
    while(ans.length()&&ans.back()=='0')ans.pop_back();
	reverse(ans.begin(),ans.end());
    if(ans=="")ans="0";
    return ans;
}

void DFT(Complex *A,int r)
{
	for(int i=0;i<X;i++)if(i>rev[i])swap(A[i],A[rev[i]]);
	for(int i=1;i<X;i<<=1)
	{
		Complex w=Complex(cosl(pi/i),sinl(pi/i)*r);
		for(int j=0;j<X;j+=2*i)
		{
			Complex cur=1;
			for(int k=0;k<i;k++)
			{
				Complex tmp=A[i+j+k]*cur;
				A[i+j+k]=A[j+k]-tmp,A[j+k]=A[j+k]+tmp;
				cur=cur*w;
			}
		}
	}
	if(r==-1)for(int i=0;i<X;i++)A[i]/=X;
}
Poly operator * (Poly x,const Poly y)
{
	int N=x.size(),M=y.size();
	for(K=0,X=1;X<=N+M-1;X<<=1,K++);
	for(int i=1;i<X;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<K-1);
	memset(A,0,sizeof(Complex)*X);
	memset(B,0,sizeof(Complex)*X);
	for(int i=0;i<N;i++)A[i]=Complex(x[i]);
	for(int i=0;i<M;i++)B[i]=Complex(y[i]);
	DFT(A,1),DFT(B,1);
	for(int i=0;i<X;i++)A[i]=A[i]*B[i];
	DFT(A,-1);
	x.resize(N+M-1);
	for(int i=0;i<N+M;i++)x[i]=LL(A[i].x+0.5)%P;
	return x;
}
Poly solve(int L,int R)
{
	if(L==R)return {1,L};
	int mid=L+R>>1;
	return solve(L,mid)*solve(mid+1,R);
}

int main()
{
    ios::sync_with_stdio(0);
	cin>>T;
    while(T--)
    {
        int ans=0;
        cin>>N>>P;
        int n=getmod(N,P);
        N=divide(N,P);
        if(n==P-1)inc(N),n=0;
        if(n)
        {
            auto result=solve(1,n);
            for(int i:result)if(i)ans++;
        }
        else ans=1;
        while(N!="0")
            ans=(ans*LL(getmod(N,P)+1))%mod,N=divide(N,P);
        cout<<ans<<endl;
    }
	return 0;
}