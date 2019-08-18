#include<bits/stdc++.h>
using namespace std;

const int MX = 100005, MXT = 1005;

struct edge_t {
    int to, p, q;
    bool operator < (const edge_t& u) const {return p > u.p;}
};
typedef vector<edge_t>::iterator Vet;

int A, B, C;
vector<edge_t> G[MX];
map<int, long long> dis[MXT];

int read() {
    int x = 0, c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
    return x;
}

inline long long getVal(int x) {
    return A * x * x + B * x + C;
}
void update(long long &cur, long long val) {
    if(cur > val) cur = val;
}

int main() {
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
    int n = read(), m = read();
    A = read(), B = read(), C = read();
    for(int i = 1; i <= m; i++) {
        int u = read(), v = read(), p = read(), q = read();
        G[u].push_back((edge_t){v, p, q});
    }
    for(int i = 1; i <= n; i++)
        sort(G[i].begin(), G[i].end());
    dis[0][1] = 0;
    long long ans = LLONG_MAX;
    for(int i = 0; i <= 1000; i++) {
        for(map<int, long long>::iterator cur = dis[i].begin(); cur != dis[i].end(); ++cur) {
            int u = cur -> first;
            long long d = cur -> second;
            for(vector<edge_t>::iterator it = G[u].begin(); it != G[u].end(); ++it) {
                int v = it -> to, p = it -> p, q = it -> q;
                if(p < i) break;
                if(dis[q].count(v))
                    update(dis[q][v], d + getVal(p - i));
                else
                    dis[q][v] = d + getVal(p - i);
            }
        }
        if(dis[i].count(n)) ans = min(ans, dis[i][n] + i);
    }
    printf("%lld\n", ans);
    return 0;
}
