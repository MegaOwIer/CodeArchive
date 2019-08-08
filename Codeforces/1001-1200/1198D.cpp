#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 55;

int n, dp[MX][MX][MX][MX];
char s[MX][MX];

void update(int &u, int v) {if(u > v) u = v;}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> (s[i] + 1);
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(s[i][j] == '#') dp[i][j][i][j] = 1;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) if(i > 1 || j > 1)
            for(int x1 = 1, x2 = i; x2 <= n; x1++, x2++)
                for(int y1 = 1, y2 = j; y2 <= n; y1++, y2++) {
                    int &res = dp[x1][y1][x2][y2];
                    res = max(i, j);
                    for(int x = x1; x <= x2; x++)
                        update(res, dp[x1][y1][x][y2] + dp[x + 1][y1][x2][y2]);
                    for(int y = y1; y <= y2; y++)
                        update(res, dp[x1][y1][x2][y] + dp[x1][y + 1][x2][y2]);
                }
    cout << dp[1][1][n][n] << "\n";
    return 0;
}
