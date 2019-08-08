#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1005, MVAL = 1000005;
const int INF = 0x3f3f3f3f;

int a[MX], S[MX], dp[MX], cur[MX], stk[MX];

inline double getSlope(int x, int y) {return double(cur[x] - cur[y]) / (x - y);}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int N, Z;
        cin >> N >> Z;
        for(int i = 1; i <= N; i++) cin >> a[i];
        sort(a + 1, a + N + 1, greater<int>());
        for(int i = 1; i <= N; i++) dp[i] = i * a[i];
        for(int i = 2; i <= Z; i++) {
            memcpy(cur + 1, dp + 1, sizeof(int[N]));
            int *top = stk;
            *top = i - 1;
            for(int j = i; j <= N; j++) {
                while(top > stk && getSlope(*top, *(top - 1)) >= a[j]) top--;
                dp[j] = cur[*top] + a[j] * (j - *top);
                while(top > stk && getSlope(j, *top) <= getSlope(*(top - 1), *top)) top--;
                *++top = j;
            }
        }
        cout << *min_element(dp + Z, dp + N + 1) << "\n";
    }
    return 0;
}
