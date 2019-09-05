#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005;
const int a[4][4] = {{8, 9, 1, 13}, {3, 12, 7, 5}, {0, 2, 4, 11}, {6, 10, 15, 14}};

int ans[MX][MX];

void work(int x, int y, int num) {
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            ans[x + i][y + j] = a[i][j] + num;
}

int main() {
    ios::sync_with_stdio(false);
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i += 4)
        for(int j = 0; j < n; j += 4, cnt += 16)
            work(i, j, cnt);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << ans[i][j] << ' ';
        cout << "\n";
    }
    return 0;
}
