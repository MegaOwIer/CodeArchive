#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000000;

int n, m, cnt, pr[MX + 1], mu[MX + 1], mu2[MX + 1];
bool vis[MX + 1];
vector<int> sum[MX + 1];

LL dfs(int d, int a, int it) {
    if(it > cnt) return 0;
    if(pr[it] > n / (d * a)) {}
    long long ans = dfs(d, a, it + 1);
    return ans;
}

int main() {
    mu[1] = 1;
    for(int i = 2; i <= MX; i++) {
        if(!vis[i]) pr[++cnt] = i, mu[i] = -1;
        for(int j = 1; j <= cnt && i * pr[j] <= MX; j++) {
            vis[i * pr[j]] = true;
            if(i % pr[j] == 0) {
                mu[i * pr[j]] = 0;
                break;
            }
            mu[i * pr[j]] = -mu[i];
        }
    }
    for(int i = 1; i <= MX; i++) if(mu[i])
        for(int j = 1; i * j <= MX; j++)
            mu2[i * j] += mu[i] * mu[j];
    for(int i = 1; i <= MX; i++) {
        sum[i].push_back(0);
        for(int j = i; j <= MX; j += i) sum[i].push_back(sum[i].back() + mu[j]);
    }
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        if(n > m) swap(n, m);
        int ans = 0;
        for(int i = 1; i <= n; i++) if(mu2[i])
            ans += mu2[i] * sum[i][n / i] * sum[i][m / i];
        cout << ans << "\n";
    }
    return 0;
}
