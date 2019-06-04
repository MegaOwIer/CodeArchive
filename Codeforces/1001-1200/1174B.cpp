#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;

int n, a[MX], even, odd;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] & 1) odd++;
        else even++;
    }
    if(!even || !odd) {
        for(int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
    } else {
        sort(a + 1, a + n + 1);
        for(int i = 1; i <= n; i++) {
            cout << a[i] << ' ';
        }
    }
    return 0;
}
