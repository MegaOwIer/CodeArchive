#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 100005;

int n, a[MX], b[MX];
bool vis[MX];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    int ans = 0;
    for(int i = 1, j = 1; i <= n; i++) if(!vis[a[i]]) {
        while(j < n && b[j] != a[i])
            vis[b[j]] = true, ans++, j++;
        if(b[j] == a[i]) j++;
    }
    cout << ans << "\n";
    return 0;
}