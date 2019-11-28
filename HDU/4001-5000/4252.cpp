#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 100005;

int stk[MX];

int main() {
    int n, cas = 0;
    while(~scanf("%d", &n)) {
        int *top = stk, ans = 0;
        for(int i = 1; i <= n; i++) {
            int val;
            scanf("%d", &val);
            while(top != stk && *top > val) top--, ++ans;
            if(*top != val) *++top = val;
        }
        ans += top - stk;
        printf("Case %d: %d\n", ++cas, ans);
    }
    return 0;
}
