#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;

int a[MX];

int getID(int first, int K, int n) {
    if(first + K <= n) return first + K;
    K -= n - first;
    return 2 * K - 1;
}
int work(int first, int n) {
    int ans = 0;
    if(first % 2 == 0) ans += a[first - 1];
    int res = n - (first - 1) / 2;
    int K = res - 1;
    for(int i = 0; res > 1; res = (res + 1) / 2, i++) {
        if(res & 1) ans += a[getID(first, K, n)];
        K &= ~(1 << i);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int n, F, ans = INT_MAX, pos = -1;
        cin >> n;
        for(int i = 1; i < n; i++) cin >> a[i];
        cin >> F;
        for(int i = 1; i < n; i++) if(a[i] <= F) {
            int tmp = work(i, n - 1);
            if(tmp < ans) ans = tmp, pos = i;
        }
        if(ans == INT_MAX)
            puts("impossible");
        else
            printf("possible\n%d %d\n", pos, ans + F);
    }
    return 0;
}
