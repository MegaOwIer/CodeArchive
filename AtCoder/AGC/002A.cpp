#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int a,b,res=1;
    cin>>a>>b;
    if(a<=0&&b>=0)puts("Zero");
    else if(a<0&&(b-a)%2==0)puts("Negative");
    else puts("Positive");
    return 0;
}
