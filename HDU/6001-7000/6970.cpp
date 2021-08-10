#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using LLL = __int128_t;

LL Pow(LL a, LL b, LL mod) {
    LL ans = 1;
    for(; b; b >>= 1) {
        if(b & 1) ans = (LLL)ans * a % mod;
        a = (LLL)a * a % mod;
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        LL a, P;
        scanf("%lld%lld", &a, &P);

        if(Pow(a, (P - 1) / 2, P) != 1) {
            puts("1");
        } else {
            puts("0");
        }

    }
}