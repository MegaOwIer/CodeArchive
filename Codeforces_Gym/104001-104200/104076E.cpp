#include <bits/stdc++.h>
using namespace std;

bool solve(int n, int k) {
    int A = n / 2, B = -A;
    int tmp = n / k;

    int r;
    r = (A + tmp) / (tmp + 1);
    B += r * (tmp + 1);
    A -= r * tmp;

    assert(B >= 0);
    if(B > k - n % k || A < 0) {
        return false;
    }
    if(A <= n % k) {
        return true;
    }

    r = (A - n % k + tmp - 1) / tmp;
    A -= r * tmp;
    B += r * (tmp + 1);
    if(B > k - n % k || A < 0) {
        return false;
    }
    assert(A <= n % k);
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(solve(n, k)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }

    return 0;
}
