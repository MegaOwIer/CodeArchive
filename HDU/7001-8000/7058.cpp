#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 5005;

int x[MX], y[MX];
LL tmp[MX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> x[i] >> y[i];
        }

        auto get_sqr = [] (int x) {return (LL)x * x;};
        auto get_dis = [&] (int u, int v) {
            return get_sqr(x[u] - x[v]) + get_sqr(y[u] - y[v]);
        };

        LL ans = 0;
        memset(tmp + 1, 0x3f, sizeof(LL[n]));
        for(int u = 1; u != -1; ) {
            tmp[u] = 0;
            for(int i = 1; i <= n; i++) if(tmp[i] != 0) {
                tmp[i] = min(tmp[i], get_dis(u, i));
            }

            u = -1;
            for(int i = 1; i <= n; i++) if(tmp[i] != 0) {
                if(u == -1 || tmp[i] < tmp[u]) {
                    u = i;
                }
            }
            ans = max(ans, tmp[u]);
        }

        cout << ans << "\n";
    }
    return 0;
}
