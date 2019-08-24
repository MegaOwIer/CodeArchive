#include<bits/stdc++.h>
using namespace std;

const int MX = 50;

int ans[MX], lft[MX];
bitset<MX> A[26], G[MX], vis;

bool dfs(int u, const int m) {
    for(int i = 0; i < m; i++) if(!vis[i] && G[u][i]) {
        vis.set(i);
        if(lft[i] == -1 || dfs(lft[i], m)) {
            lft[i] = u, ans[u] = i;
            return true;
        }
    }
    return false;
}

bool check(int m) {
    memset(lft, -1, sizeof(int[m]));
    for(int i = m - 1; i >= 0; i--) {
        vis.reset();
        if(!dfs(i, m)) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++)
            G[i].reset(), G[i] = ~G[i];
        for(int i = 0; i < n; i++) {
            string a, b;
            cin >> a >> b;
            for(int j = 0; j < 26; j++) A[j].reset();
            for(int j = 0; j < m; j++) A[b[j] - 'a'].set(j);
            for(int j = 0; j < m; j++)
                G[j] &= A[a[j] - 'a'];
        }
        if(!check(m)) cout << -1 << "\n";
        else {
            for(int i = 0; i < m; i++)
                cout << ans[i] + 1 << " \n"[i == m - 1];
        }
    }
    return 0;
}
