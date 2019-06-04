#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;

int n, prime[MX], cnt, d[MX];
bool vis[MX];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 2; i <= n; i++) {
        if(!vis[i]) prime[++cnt] = i, d[i] = cnt;
        for(int j = 1; j <= cnt && i * prime[j] <= n; j++) {
            vis[i * prime[j]] = true;
            d[i * prime[j]] = j;
            if(i % prime[j] == 0) break;
        }
    }
    for(int i = 2; i <= n; i++) cout << d[i] << ' ';
    return 0;
}
