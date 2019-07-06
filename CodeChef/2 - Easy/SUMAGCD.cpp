#include<bits/stdc++.h>
using namespace std;

const int MX = 100000;

int a[MX];
vector<int> d;

void divide(int N) {
    d.clear();
    for(int i = 1; i * i <= N; i++) if(N % i == 0) {
        d.push_back(i);
        if(i * i != N)
            d.push_back(N / i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, ans = 0;
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        divide(a[0]);
        for(size_t i = 0; i < d.size(); i++) {
            int cur = d[i], tmp = 0;
            for(int j = 0; j < n; j++)
                if(a[j] % cur != 0) tmp = __gcd(tmp, a[j]);
            if(tmp == 0) tmp = a[n - 1];
            ans = max(ans, tmp + cur);
        }
        cout << ans << "\n";
    }
    return 0;
}
