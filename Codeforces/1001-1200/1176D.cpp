#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 3000000;

int pr[216999], cnt, d[MX + 5], id[MX];
bool vis[MX + 5];
vector<int> ans;
multiset<int, greater<int>> B;

int main() {
    vis[1] = true;
    for(int i = 2; i <= MX; i++) {
        if(!vis[i])
            pr[++cnt] = i, d[i] = i, id[i] = cnt;
        for(int j = 1, tmp; j <= cnt && (tmp = i * pr[j]) <= MX; j++) {
            vis[tmp] = true;
            d[tmp] = pr[j];
            if(i % pr[j] == 0) break;
        }
    }

    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    n <<= 1;
    while(n--) {
        int val;
        cin >> val;
        B.insert(val);
    }
    while(!B.empty()) {
        auto it = B.begin();
        int val = *it, x;
        B.erase(it);
        if(vis[val]) {
            ans.push_back(val);
            x = val / d[val];
        } else {
            x = id[val];
            ans.push_back(x);
        }
        B.erase(B.lower_bound(x));
    }
    for(int u : ans)
        cout << u << ' ';
    return 0;
}
