#include<cstdio>

char c;
bool fl;

int main()
{
	while((c=getchar())!=EOF)
	{
		if(c=='\"')  {printf(fl?"''":"``");  fl=!fl;}
		else  putchar(c);
	}
	return 0;
}
