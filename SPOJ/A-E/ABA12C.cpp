#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
const int MX = 105;

int dp[MX], price[MX];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        for(int i = 1; i <= k; i++) cin >> price[i];
        memset(dp + 1, -1, sizeof(int[k]));
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = k; j >= 0; j--) {
                if(dp[j] == -1) continue;
                for(int w = 1; j + w <= k; w++) {
                    if(price[w] == -1) continue;
                    int val = dp[j] + price[w];
                    if(dp[j + w] == -1 || dp[j + w] > val) dp[j + w] = val;
                }
            }
        }
        cout << dp[k] << ENDL;
    }
    return 0;
}
