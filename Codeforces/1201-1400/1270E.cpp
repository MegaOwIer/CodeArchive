#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005;

int x[MX], y[MX];

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    vector<int> V[2];
    while(true) {
        for(int i = 1; i <= n; i++)
            V[(x[i] + y[i]) & 1].push_back(i);
        if(V[0].size() == 0 || V[0].size() == n) {
            for(int i = 1; i <= n; i++) {
                int _x = x[i], _y = y[i];
                x[i] = (_x + _y) >> 1;
                y[i] = (_x - _y) >> 1;
            }
            V[0].clear(), V[1].clear();
        } else {
            break;
        }
    }
    cout << V[0].size() << "\n";
    for(int u : V[0]) cout << u << ' ';
    return 0;
}
