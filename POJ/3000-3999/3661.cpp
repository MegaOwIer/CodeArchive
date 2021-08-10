#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const int MN = 10005, MM = 505;

int dp[MN][MM];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 0; i <= n; i++) {
        memset(dp[i], -1, sizeof(int[m + 1]));
    }
    dp[0][0] = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 1; j <= m && i + j <= n; j++) if(dp[i][j] != -1) {
            dp[i + j][0] = max(dp[i + j][0], dp[i][j]);
        }
        dp[i + 1][0] = max(dp[i + 1][0], dp[i][0]);

        int val;
        scanf("%d", &val);
        for(int j = 0; j < m; j++) if(dp[i][j] != -1) {
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + val);
        }
    }
    
    printf("%d\n", dp[n][0]);
    return 0;
}