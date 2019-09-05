#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    int n, d, e;
    cin >> n >> d >> e;
    e *= 5;
    int ans = n;
    for(int i = n; i >= 0; i -= e)
        ans = min(ans, i % d);
    cout << ans << "\n";
    return 0;
}
