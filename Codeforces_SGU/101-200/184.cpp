#include<bits/stdc++.h>
using namespace std;

int a[5], b[5];

int main() {
    ios::sync_with_stdio(false);
    for(int i = 1; i <= 3; i++) cin >> a[i];
    for(int i = 1; i <= 3; i++) cin >> b[i];
    int ans = INT_MAX;
    for(int i = 1; i <= 3; i++) ans = min(ans, a[i] / b[i]);
    cout << ans << "\n";
    return 0;
}
