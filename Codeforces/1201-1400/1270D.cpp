#include<bits/stdc++.h>
using namespace std;

using LL = long long;

vector<pair<int, int>> val;

void query(int except, int k) {
    cout << "? ";
    for(int i = 1; i <= k + 1; i++)
        if(i != except) cout << i << ' ';
    cout << endl;
    int pos, V;
    cin >> pos >> V;
    val.push_back({pos, V});
}

int main() {
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= k + 1; i++) query(i, k);
    int mx = 0;
    for(auto &cur : val) {
        mx = max(mx, cur.second);
    }
    int cnt = 0;
    for(auto &cur : val) {
        cnt += (cur.second == mx);
    }
    cout << "! " << cnt << endl;
    return 0;
}
