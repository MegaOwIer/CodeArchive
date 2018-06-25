/*题目描述:给出一个英语句子，希望你把句子里的单词顺序都翻转过来
  输入描述:输入包括一个英语句子。
  输出描述:按单词的顺序把单词倒序输出
  样例输入:I love you
  样例输出:you love I*/

#include<cstring>
#include<iostream>
using namespace std;

int main()
{
	int m,n=0,cnt1=0,cnt2=0,cnt3=0;
	string st,str[100];
	getline(cin,st);
	m=st.length();
	for(int i=0;i<m;i++)
	{
	    cnt3++;
		if(st[i]==' ')
		{
		    cnt1++;
			str[cnt1]=st.substr(cnt2,cnt3-1);
			cnt2=i+1;
			cnt3=0;
        }
    }
    cnt1++;
	str[cnt1]=st.substr(cnt2,m-1);
    for(int i=cnt1;i>0;i--)  cout<<str[i]<<' ';
	return 0;
}
