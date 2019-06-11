#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 200005;

vector<int> G[MX];
int col[MX];

void dfs(int u, int c) {
    if(col[u] != -1) return;
    col[u] = c;
    for(int v : G[u]) dfs(v, c ^ 1);
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++) G[i].clear();
        while(m--) {
            int u, v;
            cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        memset(col + 1, -1, sizeof(int[n]));
        dfs(1, 0);
        int cnt = 0;
        for(int i = 1; i <= n; i++) cnt += col[i];
        if(cnt * 2 > n) {
            cout << n - cnt << '\n';
            for(int i = 1; i <= n; i++)
                if(!col[i]) cout << i << ' ';
        } else {
            cout << cnt << '\n';
            for(int i = 1; i <= n; i++)
                if(col[i]) cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
