#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 105;

int cnt[MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n, M;
    cin >> n >> M;
    for(int i = 1; i <= n; i++) {
        int t;
        cin >> t;
        int ans = i - 1, cur = M - t;
        for(int j = 1; j <= 100; j++) {
            int k = min(cnt[j], cur / j);
            ans -= k, cur -= k * j;
        }
        cnt[t]++;
        printf("%d ", ans);
    }
    return 0;
}
