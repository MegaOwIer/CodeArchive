#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    int b, g, n;
    cin >> b >> g >> n;
    int ans = 0;
    for(int i = 0; i <= b && i <= n; i++)
        if(n - i <= g) ans++;
    cout << ans << "\n";
    return 0;
}
