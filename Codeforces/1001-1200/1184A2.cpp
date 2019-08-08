#include<bits/stdc++.h>
using namespace std;

const int MX = 200005;

int n;
bool valid[MX];
string s;

void check(int x) {
    for(int i = 0; i < x; i++) {
        int cnt = 0;
        for(int j = i; j < n; j += x) cnt ^= s[j] - '0';
        if(cnt) return;
    }
    valid[x] = true;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for(int i = 1; i * i <= n; i++)
        if(n % i == 0) check(i), check(n / i);
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += valid[__gcd(i, n)];
    cout << ans << endl;
    return 0;
}
