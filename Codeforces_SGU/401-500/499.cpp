#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;

int vis[MX];

void work(int x) {
    for(int i = 1; i * i <= x; i++) if(x % i == 0) {
        ++vis[i];
        if(i * i != x) ++vis[x / i];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        work(val);
    }
    int ans = 1000000;
    while(vis[ans--] <= 1);
    cout << ans + 1 << "\n";
    return 0;
}