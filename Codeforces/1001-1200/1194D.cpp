#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        if(k % 3 == 0) {
            int rem = n % (k + 1);
            puts(rem % 3 == 0 && rem != k ? "Bob" : "Alice");
        } else {
            puts(n % 3 == 0 ? "Bob" : "Alice");
        }
    }
    return 0;
}
