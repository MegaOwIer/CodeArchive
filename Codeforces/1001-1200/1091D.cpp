#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 998244353, MX = 1000005;

int fac[MX], ans, inv[MX];

int GetInv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * GetInv(mod % u) % mod;}
inline LL C(int n, int m) {return (LL)fac[n] * inv[m] % mod * inv[n - m] % mod;}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    fac[0] = 1;
    for(int i = 1; i <= N; i++) fac[i] = (LL)fac[i - 1] * i % mod;
    inv[N] = GetInv(fac[N]);
    for(int i = N; i; i--) inv[i - 1] = (LL)inv[i] * i % mod;
    ans = N * LL(fac[N] - 1) % mod;
    for(int i = 1; i < N; i++)
    {
        int cur = C(N, i + 1) * i % mod * fac[N - i - 1] % mod;
        ans = (ans - (LL)cur * i % mod + mod) % mod;
    }
    cout << (ans + 1) % mod << endl;
    return 0;
}
