/*题目描述：求两个数A和B的最大公约数。 1<=A,B<=2^31-1
  输入描述：两个整数A和B
  输出描述：最大公约数gcd(A,B)
  样例输入：8 12
  样例输出：4*/ 

#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<cstring>

using namespace std;

int main()
{
    int a,b,c,r,i;
    scanf("%d%d",&b,&c);
    if(b>c) {a=b;b=c;}
    else {a=c;b=b;}
    r=a%b;
    while(r!=0) {a=b;b=r;r=a%b;}
    printf("%d",b);
    
    return 0;
} 
