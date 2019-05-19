#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
const int X = 2000000, MX = 2000003;

int ans[MX >> 1], prime[148937], cnt;
bool vis[MX];

void check(int p) {
    for(int sum = 1 + p, cur = p; cur <= 1000000; cur *= p, sum += cur)
        if(!vis[sum]) ans[cur] = 1;
}

int main() {
    vis[1] = true;
    for(int i = 2; i <= X; i++) {
        if(!vis[i]) prime[++cnt] = i;
        for(int j = 1, tmp; (tmp = i * prime[j]) <= X; j++) {
            vis[tmp] = true;
            if(i % prime[j] == 0) break;
        }
    }
    for(int i = 1; prime[i] < 1000; i++) check(prime[i]);
    for(int i = 1; i <= 1000000; i++) ans[i] += ans[i - 1];
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int L, R;
        cin >> L >> R;
        cout << ans[R] - ans[L - 1] << ENDL;
    }
    return 0;
}
