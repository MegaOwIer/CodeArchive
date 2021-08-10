#include <cstdio>
#include <bitset>
using namespace std;

const int MX = 100;

bitset<MX> G[MX];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u - 1].set(v - 1);
    }

    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) if(G[i][k]) {
            G[i] |= G[k];
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int cnt = G[i].count();
        for(int j = 0; j < n; j++) {
            cnt += G[j][i];
        }
        ans += cnt == n - 1;
    }
    printf("%d\n", ans);
    return 0;
}
