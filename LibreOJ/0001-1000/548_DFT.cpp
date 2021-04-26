/* 2021-02-22
 * 
 * Construct DFT on R^G where
 * - The index G is a finite abelean semigroup and for each i in G, <i> is cyclic
 * - The range R is an integral domain
 */

#include <bits/stdc++.h>
using namespace std;

namespace UFS {

const int MX = 25;
int fa[MX];

void init(int n) {
    for(int i = 0; i < n; i++) fa[i] = i;
}

int find(int x) {return fa[x] == x ? fa[x] : fa[x] = find(fa[x]);}

bool isEquivalent(int x, int y) {return find(x) == find(y);}

void merge(int x, int y) {fa[find(x)] = find(y);}

} // namespace UFS

using LL = long long;

const int mod = 232792561, g = 71;
const int MXM = 22, MXL = 500005;

int G[MXM][MXM], T[MXM][MXM], IT[MXM][MXM];
int w[MXM + 5][MXM + 5];
int ide[MXM], ord[MXM];

LL Pow(LL a, LL b) {
    LL ans = 1;
    for(; b; a = a * a % mod, b >>= 1) if(b & 1) {
        ans = ans * a % mod;
    }
    return ans;
}

void calc_transform_matrix(int m) {
    // calc all the prime powers below m
    static bool vis[MXM + 5], ispp[MXM + 5];
    for(int i = 2; i <= m; i++) {
        if(!vis[i]) {
            for(int j = i; j <= m; j += i) vis[j] = true;
        }
        for(int j = i; j <= m; j *= i) ispp[j] = true;
    }

    // calc the idempotent element in subalgebra <i>
    for(int i = 0; i < m; i++) {
        int j = i;
        while(G[j][j] != j) j = G[j][i];
        ide[i] = j;
    }


    static int no[MXM], tno[MXM];
    int it = 0;

    UFS::init(m);
    memset(no, -1, sizeof(int[m]));
    memset(tno, -1, sizeof(int[m]));

    for(int i = 0; i < m; i++) if(G[i][i] == i) {
        // decompose the equivalent classes, which is also an abelean group
        vector<pair<int, int>> base;
        while(true) {
            for(int k = 0; k < m; k++) if(ide[k] == i) {
                int l, t;
                for(l = 1, t = G[k][k]; !UFS::isEquivalent(t, k); t = G[t][k], l++);
                ord[k] = (t == k ? l : -1);
            }

            int ford = 0, bas = -1;
            for(int k = 0; k < m; k++) {
                if(ide[k] == i && ispp[ord[k]] && ord[k] > ford) {
                    ford = ord[k], bas = k;
                }
            }
            if(bas == -1) break;
            base.emplace_back(bas, ford);
            for(int k = 0; k < m; k++) {
                if(ide[k] == i) UFS::merge(k, G[k][bas]);
            }
        }

        // represent all the elements of the group with the base
        no[i] = 0;
        for(size_t j = 0, b = 1; j < base.size(); j++) {
            auto [e, o] = base[j];
            for(int k = 0; k < m; k++) if(ide[k] == i && ~no[k]) {
                for(int l = 1, t = G[k][e]; l < o; l++, t = G[t][e]) {
                    tno[t] = no[k] + b * l;
                }
            }
            for(int k = 0; k < m; k++) if(~tno[k]) {
                no[k] = tno[k], tno[k] = -1;
            }
            b *= o;
        }

        // construct solutions
        for(int j = 0, k = 0; j < m; j++) if(ide[j] == i) {
            for(int l = 0; l < m; l++) if(ide[l] == i) {
                int x = 1;
                for(size_t p = 0, q = k, t = no[l]; p < base.size(); p++) {
                    int o = base[p].second;
                    x = (LL)x * w[o][q * t % o] % mod;
                    q /= o, t /= o;
                }
                T[it][l] = x;
            }
            for(int l = 0; l < m; l++) T[it][l] = T[it][G[l][i]];
            it++, k++;
        }
    }
}

void calc_inverse(int m) {
    static int P[MXM][MXM * 2];

    auto row_reduction = [&](int u, int v) -> void {
        int cur = P[v][u];
        if(!cur) return;
        for(int i = u; i < m * 2; i++) {
            P[v][i] = (P[v][i] - (LL)P[u][i] * cur % mod + mod) % mod;
        }
    };

    for(int i = 0; i < m; i++) memcpy(P[i], T[i], sizeof(int[m]));
    for(int i = 0; i < m; i++) P[i][i + m] = 1;
    for(int i = 0, it; i < m; i++) {
        for(it = i; !P[it][i] && it < m; it++);
        if(it != i) swap(P[i], P[it]);
        if(P[i][i] != 1) {
            LL inv = Pow(P[i][i], mod - 2);
            for(int j = i; j < m * 2; j++) {
                P[i][j] = P[i][j] * inv % mod;
            }
        }
        for(int j = i + 1; j < m; j++) row_reduction(i, j);
    }
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            row_reduction(j, i);
        }
    }
    for(int i = 0; i < m; i++) memcpy(IT[i], P[i] + m, sizeof(int[m]));
}

void DFT(int *begin, int *end, int T[][MXM], int m) {
    size_t l = (end - begin) / m;
    if(l != 1) {
        for(int *i = begin; i != end; i += l) {
            DFT(i, i + l, T, m);
        }
    }

    static int tmp[MXM];
    for(int i = 0; i < l; i++) {
        for(int j = 0; j < m; j++) tmp[j] = begin[j * l + i];
        for(int j = 0; j < m; j++) {
            int cur = 0;
            for(int k = 0; k < m; k++) {
                cur = (cur + (LL)T[j][k] * tmp[k]) % mod;
            }
            begin[j * l + i] = cur;
        }
    }
}

int main() {
    int n, m, N = 1;
    long long k;
    scanf("%d%d%lld", &n, &m, &k);
    for(int i = 0; i < n; i++) N *= m;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < m; j++) {
            scanf("%d", &G[i][j]);
        }
    }

    // calc roots of unity
    for(int i = 1; i <= m; i++) {
        w[i][0] = 1;
        for(LL j = 1, t = Pow(g, (mod - 1) / i); j < i; j++) {
            w[i][j] = w[i][j - 1] * t % mod;
        }
    }

    calc_transform_matrix(m);
    calc_inverse(m);

    static int P[MXL];
    for(int i = 0; i < N; i++) scanf("%d", &P[i]);
    
    DFT(P, P + N, T, m);
    k = (k + 1) % (mod - 1);
    for(int i = 0; i < N; i++) P[i] = Pow(P[i], k);
    DFT(P, P + N, IT, m);

    for(int i = 0; i < N; i++) printf("%d\n", P[i]);

    return 0;
}
