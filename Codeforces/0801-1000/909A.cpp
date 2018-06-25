#include<bits/stdc++.h>
using namespace std;

int la,lb;
string a,b,tmp,ans="zzzzzzzzzzzzzzzzzzzzzz";

int main()
{
	cin>>a>>b;
	la=a.length(),lb=b.length();
	for(int i=1;i<=la;i++)
		for(int j=1;j<=lb;j++)
			tmp=a.substr(0,i)+b.substr(0,j),ans=min(ans,tmp);
	cout<<ans;
	return 0;
}
