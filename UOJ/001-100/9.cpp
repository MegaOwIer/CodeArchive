#include<bits/stdc++.h>
using namespace std;

int n;
string s[10005];

inline bool cmp(string a,string b)
{
	int l1=a.length(),l2=b.length();
	if(l1==l2)return a<b;
	else return l1<l2;
}

int main()
{
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=n;i++)cout<<s[i]<<'\n';
	return 0;
}
