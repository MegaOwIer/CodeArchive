#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

int n, a[MX], b[MX], pos[MX];

bool check() {
    if(pos[1] == 0) return false;
    for(int i = pos[1], j = 1; i <= n; i++, j++)
        if(b[i] != j) return false;
    int num = n - pos[1] + 1;
    for(int i = num + 1, j = 0; i <= n; i++, j++)
        if(pos[i] > j) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        if(b[i]) pos[b[i]] = i;
    }
    if(check()) cout << pos[1] - 1 << "\n";
    else {
        int ans = 0;
        for(int i = 1; i <= n; i++)
            ans = max(ans, pos[i] - i + 1);
        cout << ans + n << "\n";
    }
    return 0;
}
