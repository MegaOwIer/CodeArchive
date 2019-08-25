#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n % 2 == 1) cout << n - 1 << "\n";
        else cout << n + 1 << "\n";
    }
    return 0;
}
