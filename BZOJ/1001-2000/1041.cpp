#include<cstdio>
#include<cmath>
using namespace std;

int cnt,tmp,ans1=1,r;

int main()
{
    scanf("%d",&r);
    int mx=(int)sqrt(r);while(!(r&1))r>>=1;
    for(int i=3;i<=mx;i+=2)  if(r%i==0)
    {
        if((i>>1)&1)  while(!(r%i))r/=i;
        else
        {
            while(!(r%i))r/=i,tmp+=2;
            ans1*=1+tmp;  tmp=0;
        }
    }
    if(r>1&&(r%4==1))ans1*=3;
	printf("%d",ans1<<2);
    return 0;
}
