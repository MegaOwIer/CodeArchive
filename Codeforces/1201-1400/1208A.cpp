#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int a, b, n;
        cin >> a >> b >> n;
        switch(n % 3) {
            case 0:
                cout << a << "\n";
                break;
            case 1:
                cout << b << "\n";
                break;
            default:
                cout << (a ^ b) << "\n";
                break;
        }
    }
    return 0;
}
