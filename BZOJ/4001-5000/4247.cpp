#include<bits/stdc++.h>
using namespace std;

const int MX = 2005;

int n, dp[MX], tmp, val0[MX], cnt;

inline void update(int &a, int b) {a = max(a, b);}

int main() {
    scanf("%d", &n);
    fill(dp, dp + n + 1, INT_MIN);
    dp[1] = 0;
    for(int i = 1, cap, val; i <= n; i++) {
        scanf("%d%d", &cap, &val);
        if(cap == 0) val0[++cnt] = max(val, 0);
        else if(cap == 1) tmp += max(val, 0);
        else {
            for(int j = n; j >= 0; j--) if(dp[j] != INT_MIN)
                update(dp[min(j + cap - 1, n)], dp[j] + val);
        }
    }
    sort(val0 + 1, val0 + n + 1, greater<int>());
    for(int i = 1; i <= n; i++) val0[i] += val0[i - 1];
    for(int i = 0; i <= n; i++) dp[i] += val0[i];
    printf("%d\n", tmp + *max_element(dp, dp + n + 1));
    return 0;
}
