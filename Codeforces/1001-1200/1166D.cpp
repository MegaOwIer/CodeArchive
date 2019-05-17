#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
using LL = long long;
const int MX = 55;

LL cur[MX], r[MX];

void print(int len) {
    cout << len << ' ';
    for(int i = 1; i <= len; i++) {
        LL ans = 0;
        for(int j = 1; j <= i; j++)
            ans += r[j] * cur[i - j];
        cout << ans << ' ';
    }
    cout << ENDL;
}

void solve(LL a, LL b, LL m) {
    if(a == b) {
        cout << "1 " << a << ENDL;
        return;
    }
    r[1] = a;
    for(int i = 2; i <= 50; i++) {
        LL rem = b - a * cur[i - 1];
        for(int j = 2; j <= i; j++)
            r[j] = 1, rem -= cur[i - j];
        if(rem < 0) break;
        for(int j = 2; j <= i; j++) {
            LL tmp = min(rem / cur[i - j], m - 1);
            r[j] += tmp;
            rem -= tmp * cur[i - j];
        }
        if(rem == 0)
            return print(i);
    }
    cout << "-1" << ENDL;
}

int main() {
    cur[0] = 1;
    for(int i = 1; i <= 51; i++) cur[i] = 1LL << (i - 1);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        LL a, b, m;
        cin >> a >> b >> m;
        solve(a, b, m);
    }
    return 0;
}
