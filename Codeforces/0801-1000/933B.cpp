#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int k;
LL p;
vector<int> ans;

int main()
{
    cin>>p>>k;
    k=-k;
    while(p!=0)
    {
        if(p>0)
        {
            ans.push_back(p-p/k*k);
            p/=k;
        }
        else
        {
            if(p%k==0)
            {
                ans.push_back(0);
                p/=k;
            }
            else
            {
                ans.push_back(p-p/k*k-k);
                p=p/k+1;
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
    return 0;
}