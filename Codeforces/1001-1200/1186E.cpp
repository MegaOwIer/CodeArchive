#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005;

int n, m, S[MX][MX];

int getSum(int x, int y, int _n, int _m) {
    if((__builtin_popcount(x) + __builtin_popcount(y)) % 2)
        return (_n + 1) * (_m + 1) - S[_n][_m];
    else
        return S[_n][_m];
}
long long f(int x, int y) {
    if(x < 0 || y < 0) return 0;
    long long X = x / n, Y = y / m, ans = 0;
    ans = (X * Y / 2) * n * m;
    if(X * Y % 2 == 1)
        ans += getSum(X - 1, Y - 1, n - 1, m - 1);
    x %= n, y %= m;
    ans += (x + 1) * m * (Y / 2) + n * (y + 1) * (X / 2);
    if(X % 2) ans += getSum(X - 1, Y, n - 1, y);
    if(Y % 2) ans += getSum(X, Y - 1, x, m - 1);
    ans += getSum(X, Y, x, y);
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int Q;
    cin >> n >> m >> Q;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for(int j = 0; j < m; j++) S[i][j] = s[j] - '0';
        for(int j = 1; j < m; j++) S[i][j] += S[i][j - 1];
    }
    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            S[i][j] += S[i - 1][j];
    while(Q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        --x1, --x2, --y1, --y2;
        cout << f(x2, y2) + f(x1 - 1, y1 - 1) - f(x1 - 1, y2) - f(x2, y1 - 1) << "\n";
    }
    return 0;
}
