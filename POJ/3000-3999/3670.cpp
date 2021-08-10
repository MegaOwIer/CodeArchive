#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const int MX = 30005;

int a[MX], dp[MX][3];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i]--;
    }

    for(int i = 0; i < a[1]; i++) dp[1][i] = 1;
    for(int i = a[1]; i < 3; i++) dp[1][i] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + (a[i] != 0);
        dp[i][1] = min(dp[i][0], dp[i - 1][1] + (a[i] != 1));
        dp[i][2] = min(dp[i][1], dp[i - 1][2] + (a[i] != 2));
    }
    int ans = dp[n][2];

    reverse(a + 1, a + n + 1);
    for(int i = 0; i < a[1]; i++) dp[1][i] = 1;
    for(int i = a[1]; i < 3; i++) dp[1][i] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][0] + (a[i] != 0);
        dp[i][1] = min(dp[i][0], dp[i - 1][1] + (a[i] != 1));
        dp[i][2] = min(dp[i][1], dp[i - 1][2] + (a[i] != 2));
    }

    printf("%d\n", min(ans, dp[n][2]));
    return 0;
}
