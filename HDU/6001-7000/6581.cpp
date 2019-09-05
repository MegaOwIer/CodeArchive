#include<bits/stdc++.h>
using namespace std;

using LD = long double;
const int MX = 100005;
const long double eps = 1e-9l;

int n, l[MX], s[MX], v[MX];
LD pos[MX];

bool check(long double t) {
    pos[n] = s[n] - t * v[n];
    for(int i = n - 1; i >= 0; i--)
        pos[i] = max(pos[i + 1] + l[i + 1], s[i] - t * v[i]);
    return pos[0] < eps;
}

int main() {
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(8);
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i <= n; i++) scanf("%d", l + i);
        for(int i = 0; i <= n; i++) scanf("%d", s + i);
        for(int i = 0; i <= n; i++) scanf("%d", v + i);
        LD l = 0, r = 1e9l;
        while(r - l > eps) {
            long double mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        cout << (l + r) / 2 << "\n";
    }
    return 0;
}
