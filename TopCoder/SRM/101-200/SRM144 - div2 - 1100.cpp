#include<bits/stdc++.h>
using namespace std;

class PowerOutage {
    private:
        static const int MX = 55;
        vector<pair<int, int>> G[MX];
        int mx;

        void dfs(int u, int f, int dep) {
            mx = max(mx, dep);
            for(auto tmp : G[u]) if(tmp.first != f)
                dfs(tmp.first, u, dep + tmp.second);
        }
    public:
        int estimateTimeOut(vector<int> U, vector<int> V, vector<int> L) {
            for(size_t i = 0; i < U.size(); i++) {
                G[U[i]].push_back({V[i], L[i]});
                G[V[i]].push_back({U[i], L[i]});
            }
            dfs(0, -1, 0);
            int ans = 0;
            for(int val : L) ans += val * 2;
            return ans - mx;
        }
};
