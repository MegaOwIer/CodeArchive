/*题目描述:笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，用这种方法去选择选项的时候选对的几率非常大！
           这种方法的具体描述如下：假设maxn是单词中出现次数最多的字母的出现次数，minn是单词中出现次数最少的字母的出现次数，
		   如果maxn-minn是一个质数，那么笨小猴就认为这是个Lucky Word，这样的单词很可能就是正确的答案。
  输入描述:只有一行，是一个单词，其中只可能出现小写字母，并且长度小于100。
  输出描述:共两行，第一行是一个字符串，假设输入的的单词是Lucky Word，那么输出“Lucky Word”，否则输出"No Answer";
           第二行是一个整数，如果输入单词是Lucky Word，输出maxn-minn的值，否则输出0。
  样例输入:样例一:error
           样例二:olympic
  样例输出:样例一:Lucky Word
                  2
		   样例二:No Answer
		          0*/

#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;

int a[30],mi=999,mx=-999,n;
string st;
int prime(int);

int main()
{
	cin>>st;
	for(int i=0;i<st.length();i++)  a[st[i]-'a'+1]++;
    for(int i=1;i<=26;i++)
    {
    	if(a[i]==0)  continue;
    	if(a[i]>mx)  mx=a[i];
    	if(a[i]<mi)  mi=a[i];
    }
    n=mx-mi;
	if(prime(n))  cout<<"Lucky Word"<<endl<<n;
	else  cout<<"No Answer\n0";
	return 0;
}
int prime(int v)
{
	if(v<2)  return 0;
	int u=sqrt(v);
	for(int i=2;i<=u;i++)  if(v%i==0)  return 0;
	return 1;
}
