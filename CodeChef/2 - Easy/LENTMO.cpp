#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 10005;

int a[MX];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, K, X;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        cin >> K >> X;
        long long ans = 0;
        if(X == 0) {
            for(int i = 1; i <= n; i++) ans += a[i];
        } else if(K == n) {
            long long sum1 = 0, sum2 = 0;
            for(int i = 1; i <= n; i++)
                sum1 += a[i], sum2 += a[i] ^ X;
            ans = max(sum1, sum2);
        } else if(K % 2 == 1) {
            for(int i = 1; i <= n; i++)
                ans += max(a[i], a[i] ^ X);
        } else {
            for(int i = 1; i <= n; i++) {
                ans += a[i];
                a[i] = (a[i] ^ X) - a[i];
            }
            sort(a + 1, a + n + 1, greater<int>());
            for(int i = 1; i < n; i += 2) {
                long long tmp = (LL)a[i] + a[i + 1];
                if(tmp <= 0) break;
                ans += tmp;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
2
5
1 2 3 4 5
2
4
7
10 15 20 13 2 1 44
4
14

*/