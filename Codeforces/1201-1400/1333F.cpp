#include <bits/stdc++.h>
using namespace std;

const int MX = 500005;

int pr[MX], cnt, d[MX];
bool vis[MX];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    d[1] = 1, vis[1] = true;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) pr[++cnt] = i, d[i] = i;
        for(int j = 1, tmp; j <= cnt && (tmp = i * pr[j]) <= n; j++) {
            vis[tmp] = true;
            d[tmp] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }
    for(int i = 2; i <= n; i++) d[i] = i / d[i];
    sort(d + 2, d + n + 1);
    for(int i = 2; i <= n; i++) cout << d[i] << ' ';
    return 0;
}
