#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int a[MX], id[MX], chain[MX << 1];
vector<int> sons[MX << 1];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) id[i] = i;
    sort(id + 1, id + n + 1, [&](int u, int v){return a[u] > a[v];});
    for(int i = 1; i <= n; i++) chain[i] = id[i] * 2;
    int siz = n;
    for(int i = 1; i <= n; i++) {
        int dis = a[id[i]], u = 2 * id[i] - 1;
        if(i + dis > siz) {
            assert(i + dis == siz + 1);
            chain[++siz] = u;
        } else {
            sons[i + dis - 1].push_back(u);
        }
    }
    for(int i = 1; i <= siz; i++)
        for(int u : sons[i]) printf("%d %d\n", u, chain[i]);
    for(int i = 2; i <= siz; i++)
        printf("%d %d\n", chain[i], chain[i - 1]);
    return 0;
}
