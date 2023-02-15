#include <bits/stdc++.h>
using namespace std;

template<typename cost_t>
class HungarianKM {
    int n, nx, ny;
    vector<vector<cost_t>> G;
    vector<bool> visx, visy;
    vector<cost_t> lx, ly;
    vector<int> pre;
    vector<cost_t> slack;

    void bfs(int i) {
        queue<int> q;
        q.push(i);
        visx[i] = true;

        function<bool(int)> check = [&] (int v) {
            visy[v] = true;
            if(matchy[v] != -1) {
                q.push(matchy[v]);
                visx[matchy[v]] = true;
                return false;
            }
            while(v != -1) {
                matchy[v] = pre[v];
                swap(v, matchx[pre[v]]);
            }
            return true;
        };

        while(true) {
            while(!q.empty()) {
                int u = q.front();
                q.pop();
                for(int v = 0; v < n; v++) {
                    if(!visy[v]) {
                        cost_t delta = lx[u] + ly[v] - G[u][v];
                        if(slack[v] >= delta) {
                            pre[v] = u;
                            if(delta) {
                                slack[v] = delta;
                            } else if(check(v)) {
                                return;
                            }
                        }
                    }
                }
            }
            
            cost_t a = numeric_limits<cost_t>::max();
            for(int j = 0; j < n; j++) {
                if(!visy[j]) {
                    a = min(a, slack[j]);
                }
            }
            for(int j = 0; j < n; j++) {
                if(visx[j]) lx[j] -= a;
                if(visy[j]) {
                    ly[j] += a;
                } else {
                    slack[j] -= a;
                }
            }
            for(int j = 0; j < n; j++) {
                if(!visy[j] && slack[j] == 0 && check(j)) {
                    return;
                }
            }
        }
    }

public:
    vector<int> matchx, matchy;

    HungarianKM(int _n, int _m) : n(max(_n, _m)), nx(_n), ny(_m) {
        G.assign(n, vector<cost_t>(n, 0));
        matchx.assign(n, -1);
        matchy.assign(n, -1);
        lx.resize(n);
        ly.assign(n, 0);
        pre.resize(n);
    }
    
    void add_edge(int u, int v, cost_t w) {
        G[u][v] = max(w, G[u][v]);
    }

    cost_t solve() {
        for(int i = 0; i < n; i++) {
            lx[i] = *max_element(G[i].begin(), G[i].end());
        }

        for(int i = 0; i < n; i++) {
            slack.assign(n, numeric_limits<cost_t>::max());
            visx.assign(n, false);
            visy.assign(n, false);
            bfs(i);
        }

        cost_t res = 0;
        for(int i = 0; i < n; i++) {
            if(G[i][matchx[i]] > 0) {
                res += G[i][matchx[i]];
            } else {
                matchx[i] = -1;
            }
        }
        return res;
    }
};

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<pair<LL, int>> teams(n);
    for(int i = 0; i < n; i++) {
        cin >> teams[i].first;
    }
    for(int i = 0; i < n; i++) {
        cin >> teams[i].second;
    }
    sort(teams.begin(), teams.end());
    partial_sum(teams.begin(), teams.end(), teams.begin(), [] (auto x, auto y) {
        return make_pair(y.first, x.second + y.second);
    });

    HungarianKM<int> solver(n, n);

    vector<LL> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            auto it = lower_bound(teams.begin(), teams.end(), make_pair(a[i] + b[j], -1));
            if(it == teams.begin()) {
                continue;
            }
            solver.add_edge(i, j, prev(it)->second);
        }
    }

    cout << solver.solve() << "\n";
    return 0;
}
