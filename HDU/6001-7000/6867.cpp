#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 500005;

vector<int> G[MX];
int siz[MX];
LL dp[MX];

void dfs1(int u) {
    siz[u] = 1;
    for(int v : G[u]) {
        dfs1(v);
        siz[u] += siz[v];
    }
}

void dfs2(int u) {
    for(int v : G[u]) {
        dp[v] += dp[u];
        dfs2(v);
    }
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) G[i].clear();
        for(int i = 2; i <= n; i++) {
            int fa;
            scanf("%d", &fa);
            G[fa].push_back(i);
        }
        dfs1(1);
        for(int i = 1; i <= n; i++) dp[i] = n - siz[i];
        dfs2(1);
        long long ans = 0;
        for(int i = 1; i <= n; i++) ans += siz[i];
        printf("%lld\n", ans + *max_element(dp + 1, dp + n + 1));
    }
    return 0;
}
