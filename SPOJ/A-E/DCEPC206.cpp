#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
const int MX = 1000000;

long long tr[MX + 5];

long long query(int u) {
    long long ans = 0;
    for(; u; u -= u & -u) ans += tr[u];
    return ans;
}
void insert(int u) {
    for(int i = u; i <= MX; i += i & -i) tr[i] += u;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int N;
        cin >> N;
        memset(tr + 1, 0, sizeof(long long[MX]));
        long long ans = 0;
        for(int i = 1, val; i <= N; i++) {
            cin >> val;
            if(val == 0) continue;
            ans += query(val - 1);
            insert(val);
        }
        cout << ans << ENDL;
    }
    return 0;
}
