#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 200005;

int a[MX];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        bool res = false;
        for(int i = 1; i < n; i++)
            if(abs(a[i] - a[i + 1]) >= 2) {
                printf("YES\n%d %d\n", i, i + 1);
                res = true;
                break;
            }
        if(!res) puts("NO");
    }
    return 0;
}
