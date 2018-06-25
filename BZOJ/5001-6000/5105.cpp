#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int a,b,c;

inline LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
inline LL lcm(LL a,LL b){return a*b/gcd(a,b);}

int main()
{
	cin>>a>>b>>c;
	cout<<lcm(a,lcm(b,c))<<endl;
	return 0;
}
