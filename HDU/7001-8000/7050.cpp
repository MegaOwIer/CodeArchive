#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using LD = long double;
const int MX = 100005;

int a[MX], ind[MX];
bool vis[MX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;

        memset(vis + 1, false, sizeof(bool[n]));
        memset(ind + 1, 0, sizeof(int[n]));
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            ind[a[i]]++;
        }

        vector<int> que;
        for(int i = 1; i <= n; i++) if(!ind[i]) {
            que.push_back(i);
            vis[i] = true;
        }
        for(size_t i = 0; i < que.size(); i++) {
            int to = a[que[i]];
            if(!--ind[to]) {
                que.push_back(to);
                vis[to] = true;
            }
        }

        vector<LD> res;
        for(int i = 1; i <= n; i++) if(!vis[i]) {
            vector<int> stk;
            for(int j = i; !vis[j]; j = a[j]) {
                stk.push_back(j);
                vis[j] = true;
            }
            LL sum = 0;
            for(int v : stk) {
                sum += v;
            }
            res.push_back((LD)sum / stk.size());
        }

        sort(res.begin(), res.end());
        puts(res.back() - res.front() <= 1e-5l ? "YES" : "NO");
    }
    return 0;
}
