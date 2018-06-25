#include<bits/stdc++.h>
using namespace std;

int n,k,cnt[30];
char c;

template<typename T>
inline void read(T& x)
{
	x=0;  char ch=getchar();
	while(ch<'0'||ch>'9')  ch=getchar();
	while(ch>='0'&&ch<='9')  x=x*10+ch-'0',ch=getchar();
}
inline void getalpha(char& ch) {do ch=getchar();while(ch<'a'||ch>'z');}

int main()
{
	read(n),read(k);
	for(int i=1;i<=n;i++)  getalpha(c),cnt[c-'a']++;
	for(int i=0;i<26;i++)  if(cnt[i]>k)  return puts("NO"),0;
	return puts("YES"),0;
}
