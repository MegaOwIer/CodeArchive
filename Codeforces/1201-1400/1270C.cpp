#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        long long ans1 = 0, ans2 = 0;
        for(int i = 1; i <= n; i++) {
            int val;
            cin >> val;
            ans1 ^= val, ans2 += val;
        }
        printf("2\n%lld %lld\n", ans1 + ans2, ans1);
    }
    return 0;
}
