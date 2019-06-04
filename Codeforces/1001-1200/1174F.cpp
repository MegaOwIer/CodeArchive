#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

int n, siz[MX], mxs[MX], chain[MX];
vector<int> G[MX];

void dfs1(int u, int f) {
    siz[u] = 1;
    for(int v : G[u]) {
        if(v == f) continue;
        dfs1(v, u);
        siz[u] += siz[v];
        if(siz[v] > siz[mxs[u]]) mxs[u] = v;
    }
}

int work(int r, int dep) {
    if(dep == 0) return r;
    int len = 1;
    chain[1] = r;
    for(int i = r; mxs[i]; i = mxs[i]) chain[++len] = mxs[i];
    if(len == 1) return r;
    int index = (1 + len + 1) >> 1;
    int u = chain[index], disu;
    cout << "d " << u << endl;
    cin >> disu;
    if(disu - dep == index - 1) {
        int root;
        cout << "s " << r << endl;
        cin >> root;
        return work(root, dep - 1);
    } else if(dep - disu == index - 1) {
        return work(u, disu);
    } else {
        int del = dep - disu;
        int d0 = (del + index - 1) / 2;
        return work(chain[d0 + 1], dep - d0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    cout << "d 1" << endl;
    int dep;
    cin >> dep;
    int ans = work(1, dep);
    cout << "! " << ans << endl;
    return 0;
}
