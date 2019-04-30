#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int N;
vector<LL> ans;

LL work(int N, int d)
{
    int xx = N / d;
    return LL(1 + N + 1 - d) * xx / 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for(LL i = 1; i * i <= N; i++)
        if(N % i == 0)
        {
            ans.push_back(work(N, i));
            if(i * i != N)
                ans.push_back(work(N, N/i));
        }
    sort(ans.begin(), ans.end());
    for(LL i : ans) cout << i << " ";
    return 0;
}
