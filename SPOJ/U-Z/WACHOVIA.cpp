#include<bits/stdc++.h>
using namespace std;

int dp[1005];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        memset(dp + 1, 0, sizeof(int[n]));
        while(m--) {
            int a, b;
            cin >> a >> b;
            for(int i = n - a; i >= 0; i--)
                dp[i + a] = max(dp[i + a], dp[i] + b);
        }
        printf("Hey stupid robber, you can get %d.\n", dp[n]);
    }
    return 0;
}
