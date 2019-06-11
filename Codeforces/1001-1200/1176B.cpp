#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int num[3];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        memset(num, 0, sizeof(int[3]));
        while(n--) {
            int val;
            cin >> val;
            num[val % 3] += 1;
        }
        cout << num[0] + min(num[1], num[2]) + (int)abs(num[1] - num[2]) / 3 << "\n";
    }
    return 0;
}
