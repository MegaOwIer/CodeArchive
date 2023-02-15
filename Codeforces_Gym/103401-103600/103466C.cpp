#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;
const int mod = 1000000007;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

int val[MX][MX], dp[MX][MX][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    map<int, vector<pair<int, int>>> pos;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> val[i][j];
            pos[val[i][j]].emplace_back(i, j);
        }
    }

    int ans = 0;

    auto update = [&] (int &x, int y) {
        (x += y) %= mod;
    };

    auto work = [&] (int cur, int x, int y) {
        bool is_start = true;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m) {
                continue;
            }
            if(val[xx][yy] == cur - 1) {
                is_start = false;
            }
        }

        if(is_start) {
            dp[x][y][0] = 1;
        }

        bool is_end = true;
        for(int i = 0; i < 4; i++) {
            int xx = x + dx[i], yy = y + dy[i];
            if(xx < 1 || xx > n || yy < 1 || yy > m) {
                continue;
            }
            if(val[xx][yy] == cur + 1) {
                for(int j = 0; j < 3; j++) {
                    update(dp[xx][yy][j + 1], dp[x][y][j]);
                }
                update(dp[xx][yy][3], dp[x][y][3]);
                is_end = false;
            }
        }

        if(is_end) {
            update(ans, dp[x][y][3]);
        }
    };

    for(const auto &[val, post] : pos) {
        for(auto cur : post) {
            work(val, cur.first, cur.second);
        }
    }

    cout << ans << "\n";
    return 0;
}
