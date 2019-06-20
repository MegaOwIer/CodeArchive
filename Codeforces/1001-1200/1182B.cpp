#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 505;

int x, y;
char s[MX][MX];

string check(int n, int m) {
    vector<pair<int, int>> res;
    for(int i = 2; i < n; i++)
        for(int j = 2; j < m; j++) {
            if(s[i][j] == '*' && s[i][j + 1] == '*' && s[i][j - 1] == '*' && s[i + 1][j] == '*' && s[i - 1][j] == '*')
                res.push_back({i, j});
        }
    if(res.size() != 1) return "NO";
    int x = res[0].first, y = res[0].second;
    s[x][y] = 0;
    for(int i = x - 1; s[i][y] == '*'; i--) s[i][y] = 0;
    for(int i = x + 1; s[i][y] == '*'; i++) s[i][y] = 0;
    for(int i = y - 1; s[x][i] == '*'; i--) s[x][i] = 0;
    for(int i = y + 1; s[x][i] == '*'; i++) s[x][i] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i][j] == '*') return "NO";
    return "YES";
}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> (s[i] + 1);
    cout << check(n, m) << endl;
    return 0;
}
