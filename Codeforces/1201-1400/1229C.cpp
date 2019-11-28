#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int deg[MX];
vector<int> in[MX];

long long getAns(int u) {return LL(deg[u] - in[u].size()) * in[u].size();}

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if(u > v) swap(u, v);
        in[u].push_back(v);
        ++deg[u], ++deg[v];
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += getAns(i);
    cout << ans << "\n";
    int Q;
    cin >> Q;
    while(Q--) {
        int u;
        cin >> u;
        ans -= getAns(u);
        for(int v : in[u]) {
            ans -= getAns(v);
            in[v].push_back(u);
            ans += getAns(v);
        }
        cout << ans << "\n";
        in[u].clear();
    }
    return 0;
}
