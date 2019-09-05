#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 2005;

int a[MX];
map<int, int> lst;
set<int> val;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        lst[a[i]] = i;
    }
    int l = 1, r = n;
    while(l <= n) {
        if(val.count(a[l])) break;
        val.insert(a[l]);
        l++;
    }
    val.clear();
    while(r >= 1) {
        if(val.count(a[r])) break;
        val.insert(a[r]);
        r--;
    }
    val.clear();
    int ans = r;
    for(int i = 1; i < l; i++) {
        val.insert(a[i]);
        int cur = max(i, r);
        for(int u : val)
            cur = max(cur, lst[u]);
        ans = min(ans, cur - i);
    }
    cout << ans << "\n";
    return 0;
}
