#include <bits/stdc++.h>
using namespace std;

using LL = long long;

LL pw10[19];

LL getAns(long long u)  {
    if(u < 10) return u;
    string n = to_string(u);
    long long ans = 9;
    for(int i = 2; i < n.length(); i++) {
        ans += pw10[i - 2] * 9;
    }
    for(int i = 0; i < n.length() - 1; i++) {
        ans += pw10[n.length() - i - 2] * LL(n[i] - '0' - (i == 0));
    }
    return ans + (n.back() >= n.front());
}

int main() {
    pw10[0] = 1;
    for(int i = 1; i <= 18; i++) pw10[i] = pw10[i - 1] * 10;
    ios::sync_with_stdio(false);
    long long l, r;
    cin >> l >> r;
    cout << getAns(r) - getAns(l - 1) << "\n";
    return 0;
}
