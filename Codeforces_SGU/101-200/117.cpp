#include<bits/stdc++.h>
using namespace std;

int Pow(int a, int b, int mod) {
    int ans = 1;
    for(; b; a = a * a % mod, b >>= 1)
        if(b & 1)ans = ans * a % mod;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, k, ans = 0;
    cin >> n >> m >> k;
    while(n--) {
        int x;
        cin >> x;
        ans += Pow(x, m, k) == 0;
    }
    cout << ans << "\n";
    return 0;
}
