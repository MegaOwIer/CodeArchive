#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

set<int> id[26];
int fa[MX];

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string val;
        cin >> val;
        for(char c : val) id[c - 'a'].insert(i);
    }
    for(int i = 1; i <= n; i++) fa[i] = i;
    for(int i = 0; i < 26; i++) if(!id[i].empty()) {
        int u = *id[i].begin();
        for(int v : id[i]) {
            int fu = find(u), fv = find(v);
            if(fu != fv) fa[fu] = fv;
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += (i == fa[i]);
    cout << ans << "\n";
    return 0;
}
