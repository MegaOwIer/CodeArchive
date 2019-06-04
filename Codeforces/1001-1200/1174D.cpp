#include<bits/stdc++.h>
using namespace std;

const int MX = (1 << 18) + 5;

int n, k;
vector<int> ans;
bool vis[MX];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(k >= (1 << n)) k = 0;
    for(int i = 1; i < (1 << n); i++) {
        if(vis[i] || i == k) continue;
        ans.push_back(i);
        vis[i] = true, vis[i ^ k] = true;
    }
    cout << ans.size() << "\n";
    if(!ans.empty()) {
        cout << ans[0] << ' ';
        for(size_t i = 1; i < ans.size(); i++)
            cout << (ans[i] ^ ans[i - 1]) << ' ';
    }
    return 0;
}
