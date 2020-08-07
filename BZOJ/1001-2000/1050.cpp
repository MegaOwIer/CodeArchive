#include <bits/stdc++.h>
using namespace std;

struct fraction {
    int a, b;

    fraction(int _a, int _b = 1) {
        int _d = __gcd(_a, _b);
        a = _a / _d, b = _b / _d;
    }
    bool operator< (const fraction &f) const {return a * f.b < b * f.a;}
    void println() {
        if(b != 1) printf("%d/%d\n", a, b);
        else printf("%d\n", a);
    }
};

struct edge {
    int u, v, w;

    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator< (const edge &e) const {return w < e.w;}
};

const int MX = 505;

vector<edge> E;
int fa[MX];

int find(int u) {return u == fa[u] ? u : fa[u] = find(fa[u]);}

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if(u == v) continue;
        E.emplace_back(u, v, w);
    }
    sort(E.begin(), E.end());
    int S, T;
    scanf("%d%d", &S, &T);
    fraction ans {40000, 1};
    for(size_t l = 0; l < E.size(); l++) {
        for(int i = 1; i <= n; i++) fa[i] = i;
        size_t r = l;
        while(r < E.size() && find(S) != find(T)) {
            int fu = find(E[r].u), fv = find(E[r].v);
            if(fu != fv) fa[fu] = fv;
            r++;
        }
        if(find(S) == find(T)) {
            ans = min(ans, fraction(E[r - 1].w, E[l].w));
        }
    }
    if(ans.a != 40000) ans.println();
    else puts("IMPOSSIBLE");
    return 0;
}
