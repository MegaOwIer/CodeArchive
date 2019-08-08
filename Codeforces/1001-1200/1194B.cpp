#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 400005;

int col[MX], row[MX];
string s[MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) cin >> s[i];
        for(int i = 1; i <= n; i++) {
            int cur = 0;
            for(int j = 0; j < m; j++)
                cur += (s[i][j] == '.') ? 1 : 0;
            row[i] = cur;
        }
        for(int j = 0; j < m; j++) {
            int cur = 0;
            for(int i = 1; i <= n; i++)
                cur += (s[i][j] == '.') ? 1 : 0;
            col[j + 1] = cur;
        }
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                ans = min(ans, row[i] + col[j] - (s[i][j - 1] == '.'));
        cout << ans << "\n";
    }
    return 0;
}
