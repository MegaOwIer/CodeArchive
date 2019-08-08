#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 300005;

int vis[MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        int n, m;
        vector<int> ansM;
        cin >> n >> m;
        for(int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
            if(vis[u] != cas && vis[v] != cas) {
                ansM.push_back(i);
                vis[u] = vis[v] = cas;
            }
        }
        if(ansM.size() >= n) {
            cout << "Matching" << "\n";
            for(int i = 0; i < n; i++) cout << ansM[i] << ' ';
            cout << "\n";
        } else {
            cout << "IndSet" << "\n";
            int cnt = 0;
            for(int i = 1; cnt < n; i++) if(vis[i] != cas) {
                cout << i << ' ';
                ++cnt;
            }
            cout << "\n";
        }
    }
    return 0;
}
