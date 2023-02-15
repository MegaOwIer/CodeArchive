#include <bits/stdc++.h>
using namespace std;

const int MX = 200005;

vector<int> G[MX];

int dfs(int u) {
    vector<int> val;
    for(int v : G[u]) {
        val.push_back(dfs(v));
    }
    if(val.empty()) {
        return 1;
    } else {
        sort(val.begin(), val.end(), greater<int>());
        return (val.size() == 1 || val[0] > val[1]) ? val[0] : val[1] + 1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i <= n; i++) {
            G[i].clear();
        }

        for(int i = 1; i <= n; i++) {
            int fa;
            cin >> fa;
            G[fa].push_back(i);
        }

        cout << dfs(1) << "\n";
    }
    return 0;
}
