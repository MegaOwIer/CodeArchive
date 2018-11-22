#include<bits/stdc++.h>
using namespace std;

char inf[200000],*t;

inline bool check(char *s,char *t)
{
	if(t-s<2)return 0;
	if(!isupper(*s))return 0;
	s++;
	while(s!=t)if(!islower(*s++))return 0;
	return 1;
}
inline void output(char *s,char *t)
{
	if(t-s<=0)return;
	int cnt=0;
	for(char *i=s;i!=t;i++)if(*i==' ')cnt++;
	if(!cnt)while(s!=t)putchar(*s++);
	else
	{
		for(char *i=s;i!=t;i++)if(isupper(*i))putchar(*i);
		putchar(' '),putchar('(');
		while(s!=t)putchar(*s++);
		putchar(')');
	}
}

int main()
{
	freopen("abbreviation.out","w",stdout);
	t=inf+fread(inf,1,200000,fopen("abbreviation.in","r"));
	*t=0;
	for(char *i=inf,*j,*k,*l;i!=t;)
		if(!isalpha(*i))putchar(*i++);
		else if(islower(*i))while(isalpha(*i))putchar(*i++);
		else
		{
			l=i;
			while(1)
			{
				k=j=l;
				while(!isalpha(*k))k++,j++;
				while(isalpha(*k))k++;
				if(check(j,k))
				{
					l=k;
					if(*k!=' '||(!isalpha(*(k+1))))
					{
						output(i,l),i=l;
						break;
					}
				}
				else
				{
					output(i,l);
					for(i=l;i!=k;)putchar(*i++);
					break;
				}
			}
		}
	return 0;
}