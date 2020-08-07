#include <cstdio>
#include <bitset>
using namespace std;

const int MX = 1000;

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
        for(int j = i + 1; j < n; j++) {
            ans += !G[i][j] && !G[j][i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
