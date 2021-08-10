#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;

int to[MX];
bool vis[MX];

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        int n, m, ans = 0;
        scanf("%d%d", &n, &m);
        memset(to + 1, 0, sizeof(int[n]));
        memset(vis + 1, false, sizeof(bool[n]));
        vis[0] = true;
        for(int i = 1; i <= m; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            if(u == v) continue;
            to[u] = v;
            ans++;
        }
        for(int i = 1; i <= n; i++) if(!vis[i] && to[i]) {
            int j = to[i];
            while(!vis[j] && j != i) {
                vis[j] = true;
                j = to[j];
            }
            ans += (j == i);
        }
        printf("%d\n", ans);
    }
    return 0;
}
