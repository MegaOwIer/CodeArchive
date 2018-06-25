#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int val[]={0,2,5,63,20,30};
 
int N,a[20005];
LL sum;
 
int main()
{
    scanf("%d",&N);
    if(N<=5)
    {
        for(int i=1;i<=N;i++)printf("%d ",val[i]);
        return 0;
    }
    for(int i=0;i<5000;i++)
        a[i*4+1]=i*6+2,a[i*4+2]=i*6+3,a[i*4+3]=i*6+4,a[i*4+4]=i*6+6;
    for(int i=1;i<=N;i++)sum+=a[i];
    switch(sum%6)
    {
        case 2:
            a[5]=30000;
            break;
        case 3:
            a[6]=30000;
            break;
        case 5:
            a[6]=29998;
            break;
    }
    for(int i=1;i<=N;i++)printf("%d ",a[i]);
    return 0;
}