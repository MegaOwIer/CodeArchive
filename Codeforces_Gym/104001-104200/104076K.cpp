#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        vector<int> pos(n + 1);
        for(int i = 1; i <= n; i++) {
            int val;
            cin >> val;
            pos[val] = i;
        }

        int ans = 0, cur = n + 1;
        for(int i = n; i >= 1; i--) {
            if(pos[i] < cur) {
                ans++;
            }
            cur = pos[i];
        }
        cout << ans << "\n";
    }
    return 0;
}
