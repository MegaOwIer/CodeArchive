#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 45;

int n;
LL fib[MX], ans;

int main() {
    ios::sync_with_stdio(false);
    ans = fib[1] = 1;
    cin >> n;
    for(int i = 2; i <= n; i++)
        ans += (fib[i] = fib[i - 1] + fib[i - 2]);
    cout << ans << "\n";
    return 0;
}
