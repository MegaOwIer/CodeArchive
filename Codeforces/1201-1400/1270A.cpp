#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 105;

int a[MX], b[MX];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, k1, k2;
        cin >> n >> k1 >> k2;
        for(int i = 1; i <= k1; i++) cin >> a[i];
        for(int i = 1; i <= k2; i++) cin >> b[i];
        for(int i = 1; i <= k1; i++) if(a[i] == n) {
            puts("YES");
            break;
        }
        for(int i = 1; i <= k2; i++) if(b[i] == n) {
            puts("NO");
            break;
        }
    }
    return 0;
}
