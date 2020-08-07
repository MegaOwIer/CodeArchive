#include <bits/stdc++.h>
using namespace std;

const int arr[3][3] = {{4, 8, 6}, {3, 2, 5}, {1, 7, 9}};
const int MX = 505;

int ans[MX][MX];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    if(n <= 2) puts("-1");
    else if(n == 3) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << arr[i][j] << ' ';
            }
            cout << '\n';
        }
    } else {
        int tot = 0;
        for(int i = 1; i <= n - 3; i++) {
            for(int j = n; j >= 1; j--) {
                ans[i][j] = ++tot;
            }
        }
        for(int i = n - 2; i <= n; i++) {
            for(int j = 1; j <= n - 3; j++) {
                ans[i][j] = ++tot;
            }
        }
        for(int i = n - 2; i <= n; i++) {
            for(int j = n - 2; j <= n; j++) {
                int val = arr[i - (n - 2)][j - (n - 2)];
                ans[i][j] = tot + val;
            }
        }
        for(int i = n - 4; i >= 1; i -= 2) swap(ans[i][1], ans[i][2]);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) cout << ans[i][j] << ' ';
            cout << '\n';
        }
    }
    return 0;
}