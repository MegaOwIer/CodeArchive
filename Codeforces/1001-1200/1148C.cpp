#include<bits/stdc++.h>
using namespace std;

const int MX = 300005;

int p[MX], n, pos[MX];
vector<pair<int, int>> ans;

inline void change(int a, int b) {
    swap(pos[p[a]], pos[p[b]]);
    swap(p[a], p[b]);
    ans.push_back({a, b});
    assert(abs(a - b) >= n / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for(int i = 1; i <= n; i++) {
        if(p[i] == i) continue;
        if(pos[i] - i >= n / 2) {
            change(pos[i], i);
        } else if(i <= n / 2) {
            int v = pos[i];
            if(v > n / 2)
                change(i, n), change(1, n), change(1, v), change(1, n), change(i, n);
            else
                change(i, n), change(v, n), change(i, n);
        } else {
            int v = pos[i];
            change(i, 1), change(1, v), change(1, i);
        }
    }
    for(int i = 1; i <= n; i++)
        assert(p[i] == i && pos[i] == i);
    cout << ans.size() << "\n";
    for(auto a : ans)
        cout << a.first << ' ' << a.second << "\n";
    return 0;
}
