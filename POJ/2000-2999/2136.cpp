#include<iostream>
using namespace std;

char c;
int num[30],cnt=4,mx;
bool empty();
void print();

int main()
{
	while(cnt)  {c=getchar();  if(isalpha(c))  num[c-'A'+1]++;  if(c=='\n')  cnt--;}
	for(int i=1;i<27;i++)  mx=max(mx,num[i]);
	for(;mx;mx--)
	{
		for(int i=1;i<26;i++)  {if(num[i]>=mx)  cout<<"* ";  else  cout<<"  ";}
		if(num[26]>=mx)  cout<<"*";  else  cout<<' ';
		cout<<endl;
	}
	print();
	return 0;
}
bool empty()
{
	long long ans=0;
	for(int i=1;i<27;i++)  ans+=num[i];
	return ans;
}
void print()
{
	char ch='A';
	for(int i=1;i<26;i++)  cout<<ch++<<' ';
	cout<<ch;
}
