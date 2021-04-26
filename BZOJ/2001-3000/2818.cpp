#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 10000005;

int phi[MX], pr[664600], cnt;
LL sum[MX];
bool vis[MX];

int main() {
    int n;
    scanf("%d", &n);
    phi[1] = 1;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) pr[++cnt] = i, phi[i] = i - 1;
        for(int j = 1, tmp; j <= cnt && (tmp = i * pr[j]) <= n; j++) {
            vis[tmp] = true;
            if(i % pr[j] == 0) {
                phi[tmp] = phi[i] * pr[j];
                break;
            }
            phi[tmp] = phi[i] * (pr[j] - 1);
        }
    }
    for(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + phi[i];
    long long ans = 0;
    for(int i = 1; i <= cnt; i++) ans += sum[n / pr[i]];
    printf("%lld", ans * 2 - cnt);
    return 0;
}
