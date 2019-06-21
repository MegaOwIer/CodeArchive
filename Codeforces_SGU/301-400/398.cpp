#include<bits/stdc++.h>
using namespace std;

bitset<50> G[50], S;

int main() {
    ios::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    --x;
    for(int i = 0; i < n; i++) {
        int d;
        cin >> d;
        G[i].set(i);
        while(d--) {
            int x;
            cin >> x;
            G[i].set(x - 1);
        }
    }
    for(size_t i = G[x]._Find_first(); i < G[x].size(); i = G[x]._Find_next(i))
        S |= G[i];
    S ^= G[x];
    cout << S.count() << "\n";
    for(size_t i = S._Find_first(); i < S.size(); i = S._Find_next(i))
        cout << i + 1 << " ";
    return 0;
}