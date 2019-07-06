#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int deg[MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
    }
    for(int i = 1; i <= n; i++)
        if(deg[i] == 2) return puts("NO"), 0;
    return puts("YES"), 0;
}
