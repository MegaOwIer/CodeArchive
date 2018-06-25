#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<map>
using namespace std;

char mir[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
string str;
map<char,int> n;
void panduan();
void InIt();

int main()
{
	InIt();
	while(cin>>str)
	{
		cout<<str;
		panduan();
		printf("\n\n");
	}
	return 0;
}
void panduan()
{
	bool huiwen=1,jingxiang=1;
	int lth=str.length();
	int r=(lth+1)/2;
	for(int i=0;i<r;i++)
	{
		if(huiwen)  huiwen=(str[i]==str[lth-i-1]);
		if(jingxiang)  jingxiang=(mir[n[str[i]]]==str[lth-1-i]);
	}
	if(huiwen&&jingxiang)  cout<<" -- is a mirrored palindrome.";
	else  if(jingxiang)  cout<<" -- is a mirrored string.";
	      else  if(huiwen)  cout<<" -- is a regular palindrome.";
	            else  cout<<" -- is not a palindrome.";
}
void InIt()
{
	for(int i=0;i<26;i++)  n['A'+i]=i;
	for(int i=1;i<10;i++)  n['0'+i]=25+i;
}
