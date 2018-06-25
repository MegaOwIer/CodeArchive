#include<iostream>
using namespace std;

int a; 

void dir(int x)
{
	if(x<0&&x%(-2)!=0)  {dir(x/(-2)+1);  cout<<x+2*(x/(-2)+1);}
	if(x==1||x==0)  cout<<x;
	if((x>0&&x!=1)||(x<0&&x%(-2)==0))  {dir(x/(-2));  cout<<x%(-2);}
}

int main()
{
    cin>>a;
    dir(a);
    return 0;
}
