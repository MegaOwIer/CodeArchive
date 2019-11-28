#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 20000;

int n, rt[MX], ans[MX];
vector<int> pos;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> rt[i];
        if(rt[i] & 1) {
            pos.push_back(i);
        }
        if(rt[i] >= 0 || rt[i] % 2 == 0)
            ans[i] = rt[i] / 2;
        else
            ans[i] = rt[i] / 2 - 1;
    }
    for(size_t i = 0; i < pos.size(); i += 2)
        ans[pos[i]] += 1;
    for(int i = 1; i <= n; i++) cout << ans[i] << "\n";
    return 0;
}
