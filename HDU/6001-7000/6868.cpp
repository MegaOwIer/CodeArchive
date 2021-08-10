#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 10000000, mod = 1000000007, MQ = 10005;

struct query {
    int n, m, id, ans;
};

int pr[664600], cnt, f[MX + 5], F[MX + 5], d[MX + 5], p_d[MX + 5];
bool vis[MX + 5];
query q[MQ];

void dfs_update(int n, int divisor, const int val) {
    if(n == 1) {
        F[divisor] = (F[divisor] + val) % mod;
        return;
    }
    dfs_update(p_d[n], divisor * d[n], val);
    dfs_update(p_d[n], divisor, val);
}

void dfs_calc(int n, int divisor, int mu, int &ans, const int N) {
    if(n == 1) {
        ans = static_cast<int>(
            (ans + (LL)f[N] / f[divisor] * mu * F[divisor]) % mod
        );
        return;
    }
    dfs_calc(p_d[n], divisor * d[n], -mu, ans, N);
    dfs_calc(p_d[n], divisor, mu, ans, N);
}

int main() {
    f[1] = 1, d[1] = 1, p_d[1] = 1;
    for(int i = 2; i <= MX; i++) {
        if(!vis[i]) {
            pr[++cnt] = i, f[i] = 2;
            d[i] = i, p_d[i] = 1;
        }
        for(int j = 1, tmp; j <= cnt && (tmp = i * pr[j]) <= MX; j++) {
            f[tmp] = f[i];
            d[tmp] = pr[j];
            vis[tmp] = true;
            if(i % pr[j] == 0) {
                p_d[tmp] = p_d[i];
                break;
            }
            f[tmp] *= 2;
            p_d[tmp] = i;
        }
    }

    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++) {
        int n, m;
        scanf("%d%d", &n, &m);
        q[i] = (query){n, m, i, 0};
    }
    sort(q + 1, q + T + 1, [](const query &u, const query &v) {return u.m < v.m;});

    for(int i = 1, m = 0; i <= T; i++) {
        while(m + 1 <= q[i].m) {
            m++;
            dfs_update(m, 1, f[m]);
        }
        int n = q[i].n;
        dfs_calc(n, 1, 1, q[i].ans, n);
        q[i].ans = (q[i].ans + mod) % mod;
    }

    sort(q + 1, q + T + 1, [](const query &u, const query &v) {return u.id < v.id;});
    for(int i = 1; i <= T; i++) printf("%d\n", q[i].ans);
    return 0;
}
