#include <bits/stdc++.h>
using namespace std;

const int MX = 2005;

int a[MX][MX], val[MX];

int calc(int n) {
    static int l[MX], r[MX];
    static int buff[MX], *top = buff;

    *(top = buff) = 0;
    for(int i = 1; i <= n; i++) {
        while(top != buff && val[*top] >= val[i]) top--;
        l[i] = *top;
        *++top = i;
    }

    *(top = buff) = n + 1;
    for(int i = n; i >= 1; i--) {
        while(top != buff && val[*top] >= val[i]) top--;
        r[i] = *top;
        *++top = i;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, (r[i] - l[i] - 1) * val[i]);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }

        fill(val + 1, val + m + 1, 1);
        int ans = m;
        for(int i = 2; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(a[i][j] >= a[i - 1][j]) {
                    val[j]++;
                } else {
                    val[j] = 1;
                }
            }
            ans = max(ans, calc(m));
        }

        cout << ans << "\n";
    }
    return 0;
}
