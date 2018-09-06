#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

int N,goal;
vector<int> res;

int main()
{
    ios::sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(i==1)goal=a+b+c+d;
        res.push_back(a+b+c+d);
    }
    sort(res.begin(),res.end(),greater<int>());
    cout<<lower_bound(res.begin(),res.end(),goal,greater<int>())-res.begin()+1<<endl;
    return 0;
}
