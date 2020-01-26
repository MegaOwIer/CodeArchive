#include <bits/stdc++.h>
using namespace std;

constexpr int P = 7;

int getLen(int n) {
    int ans = 0;
    do ans++; while(n /= P);
    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    n--, m--;
    int lth_n = getLen(n), lth_m = getLen(m);
    if(lth_n + lth_m >= 10) return puts("0"), 0;

    int ans = 0;

    function<void(int, int, int, int, int)> dfs = [&](int it_n, int cur_n, int it_m, int cur_m, int S) {
        if(it_n < lth_n) {
            for(int i = 0; i < P; i++) if((~S >> i) & 1) {
                dfs(it_n + 1, cur_n * P + i, it_m, cur_m, S | (1 << i));
            }
        } else if(it_m < lth_m) {
            for(int i = 0; i < P; i++) if((~S >> i) & 1) {
                dfs(it_n, cur_n, it_m + 1, cur_m * P + i, S | (1 << i));
            }
        } else {
            ans += (cur_n <= n) && (cur_m <= m);
        }
    };

    dfs(0, 0, 0, 0, 0);
    cout << ans << "\n";
    return 0;
}
