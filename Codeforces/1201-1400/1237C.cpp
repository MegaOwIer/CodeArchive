#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 50005;

int n;
map<array<int, 2>, vector<array<int, 2>>> G;
map<int, vector<array<int, 2>>> G2;
vector<int> res;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        G[{x, y}].push_back({z, i});
    }
    for(auto &cur : G) if(cur.second.size() > 1) {
        sort(cur.second.begin(), cur.second.end());
        for(size_t i = cur.second.size() & 1; i < cur.second.size(); i += 2)
            cout << cur.second[i][1] << ' ' << cur.second[i + 1][1] << "\n";
        cur.second.resize(cur.second.size() & 1);
    }
    for(auto &cur : G) if(!cur.second.empty())
        assert(cur.second.size() == 1), G2[cur.first[0]].push_back({cur.first[1], cur.second.front()[1]});
    for(auto &cur : G2) if(cur.second.size() > 1) {
        sort(cur.second.begin(), cur.second.end());
        for(size_t i = cur.second.size() & 1; i < cur.second.size(); i += 2)
            cout << cur.second[i][1] << ' ' << cur.second[i + 1][1] << "\n";
        cur.second.resize(cur.second.size() & 1);
    }
    for(auto &cur : G2) if(!cur.second.empty())
        assert(cur.second.size() == 1), res.push_back(cur.second.front()[1]);
    for(size_t i = 0; i < res.size(); i += 2)
        cout << res[i] << ' ' << res[i + 1] << "\n";
    return 0;
}