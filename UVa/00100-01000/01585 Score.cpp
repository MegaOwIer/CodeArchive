#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string st;
		cin>>st;
		int m=st.length(),cnt=0,sc=0;
		for(int i=0;i<m;i++)
		{
			if(st[i]=='O')  cnt++;
			else  cnt=0;
			sc+=cnt;
		}
		cout<<sc<<endl;
	}
	return 0;
}
