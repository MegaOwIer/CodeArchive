/**
 * @date 2023-01-12
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief Flow network.
 */

#include <bits/stdc++.h>
using namespace std;

template<typename flow_t = int>
struct MaxFlow_ISAP {
    const flow_t MAX_VAL = numeric_limits<flow_t>::max();

    struct edge_t {
        int to, rev;
        flow_t f;
        edge_t() {}
        edge_t(int _t, int _r, flow_t _f) : to(_t), rev(_r), f(_f) {}
    };

    vector<vector<edge_t>> G;
    vector<typename vector<edge_t>::iterator> cur;
    int V;
    vector<int> gap, dep;

    MaxFlow_ISAP(int v) : G(v + 1), cur(v + 1), V(v) {}

    void add_edge(int u, int v, flow_t f) {
        G[u].emplace_back(v, G[v].size(), f);
        G[v].emplace_back(u, G[u].size() - 1, 0);
    }

    void BFS(int T) {
        gap.assign(V + 2, 0);
        dep.assign(V + 1, 0);
        queue<int> Q;
        Q.push(T), ++gap[dep[T] = 1];
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(edge_t &e : G[u]) {
                int v = e.to;
                if(dep[v]) continue;
                Q.push(v), ++gap[dep[v] = dep[u] + 1];
            }
        }
    }

    flow_t dfs(int u, flow_t flow, const int S, const int T) {
        if(u == T || !flow) return flow;
        flow_t w, used = 0;
        for(auto &i = cur[u]; i != G[u].end(); i++) {
            if(i -> f && dep[i -> to] == dep[u] - 1) {
                w = dfs(i -> to, min(flow - used, i -> f), S, T);
                i -> f -= w, G[i -> to][i -> rev].f += w;
                used += w;
            }
            if(used == flow) return flow;
        }
        if(!--gap[dep[u]]) dep[S] = V + 1;
        if(dep[u] <= V) ++dep[u];
        ++gap[dep[u]], cur[u] = G[u].begin();
        return used;
    }

    flow_t operator() (int S, int T) {
        flow_t ans = 0;
        BFS(T);
        while(dep[S] <= V) {
            for(int i = 1; i <= V; i++) cur[i] = G[i].begin();
            ans += dfs(S, MAX_VAL, S, T);
        }
        return ans;
    }
};

using LL = long long;

LL solve() {
    int n, m, c, d;
    cin >> n >> m >> c >> d;

    if(c == 0 || d == 0) {
        return 0;
    }

    vector<pair<int, int>> edges;
    vector<int> cntr(n), cntc(m);
    for(int i = 0; i < n; i++) {
        string qwq;
        cin >> qwq;
        for(int j = 0; j < m; j++) {
            if(qwq[j] == '.') {
                edges.emplace_back(i + 1, j + 1);
                cntr[i]++;
                cntc[j]++;
            }
        }
    }

    int L = 0, R = 0;
    R = max(R, *max_element(cntr.begin(), cntr.end()));
    R = max(R, *max_element(cntc.begin(), cntc.end()));

    vector<LL> cache;
    cache.assign(R + 2, -1);

    auto get_ans = [&] (int x) {
        if(cache[x] != -1) {
            return cache[x];
        }
        
        int S = n + m + 1, T = S + 1;
        MaxFlow_ISAP sol(n + m + 2);
        for(auto [l, r] : edges) {
            sol.add_edge(l, n + r, 1);
        }
        for(int i = 1; i <= n; i++) {
            sol.add_edge(S, i, x);
        }
        for(int i = 1; i <= m; i++) {
            sol.add_edge(n + i, T, x);
        }

        LL ans = sol(S, T);
        return cache[x] = (LL)c * x + d * (edges.size() - ans);
    };

    while(L <= R) {
        int mid = (L + R) / 2;

        LL cur_l = get_ans(mid);
        LL cur_r = get_ans(mid + 1);

        if(cur_l > cur_r) {
            L = mid + 1;
        } else {
            R = mid - 1;
        }
    }

    LL ans = numeric_limits<LL>::max();
    for(LL val : cache) {
        if(val != -1) {
            ans = min(ans, val);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << solve() << "\n";
    return 0;
}
