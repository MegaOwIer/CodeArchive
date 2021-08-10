#include <bits/stdc++.h>
using namespace std;

const int MX = 50005;

vector<int> G[MX];
int dfn[MX], low[MX], fa[MX], dep[MX];
int dp[MX];

void solve(int u, int v, int &ans) {
    static int que[MX << 1], *hd, *tl, data[MX << 1];
    int len = dep[v] - dep[u] + 1;
    for(int i = len; i; i--, v = fa[v]) data[i] = dp[v];
    memcpy(data + len + 1, data + 1, sizeof(int[len]));
    hd = que, tl = que - 1;
    *++tl = 1;
    for(int i = 2; i <= len * 2; i++) {
        while(hd <= tl && 2 * (i - *hd) > len) hd++;
        ans = max(ans, data[i] + i + data[*hd] - *hd);
        while(hd < tl && data[i] - i > data[*tl] - *tl) tl--;
        *++tl = i;
    }
    for(int i = 2; i <= len; i++) {
        dp[u] = max(dp[u], data[i] + min(i - 1, len - i + 1));
    }
}

void tarjan(int u, int pre, int &ans) {
    static int cnt = 0;
    dfn[u] = low[u] = ++cnt;
    for(int v : G[u]) if(v != pre) {
        if(!dfn[v]) {
            fa[v] = u;
            dep[v] = dep[u] + 1;
            tarjan(v, u, ans);
            low[u] = min(low[u], low[v]);
        } else {
            low[u] = min(low[u], dfn[v]);
        }
        if(low[v] > dfn[u]) {
            ans = max(ans, dp[u] + dp[v] + 1);
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }
    for(int v : G[u]) if(fa[v] != u && dfn[v] > dfn[u]) {
        solve(u, v, ans);
    }
}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    while(m--) {
        int k, lst, cur;
        scanf("%d%d", &k, &lst);
        while(--k) {
            scanf("%d", &cur);
            G[lst].push_back(cur);
            G[cur].push_back(lst);
            lst = cur;
        }
    }
    int ans = 0;
    tarjan(1, -1, ans);
    printf("%d\n", ans);
    return 0;
}
