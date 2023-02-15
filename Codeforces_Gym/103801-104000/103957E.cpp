#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000000;
const int mod = 1000000007;

vector<int> primes;
int phi[MX + 5], d[MX + 5];

void preprocess(const vector<int> &perm, map<int, int> &cycle_length) {
    vector<bool> vis(perm.size());
    for(size_t i = 0; i < perm.size(); i++) {
        int cur = 0;
        while(!vis[i]) {
            vis[i] = true;
            i = perm[i];
            cur++;
        }
        if(cur != 0) {
            cycle_length[cur] += cur;
        }
    }
}

LL Pow(LL a, LL b) {
    LL ans = 1;
    a %= mod;
    for(; b; b >>= 1) {
        if(b & 1) ans = ans * a % mod;
        a = a * a % mod;
    }
    return ans;
}

template<class T>
void factorize(T n, vector<T> &f) {
    for(T i = 1; i * i <= n; i++) if(n % i == 0) {
        f.push_back(i);
        if(i * i != n) {
            f.push_back(n / i);
        }
    }
    ranges::sort(f);
}

int solve() {
    int K, r, c;
    cin >> K >> r >> c;

    LL RC = (LL)r * c / __gcd(r, c);

    vector<int> perm(K);
    for(int &val : perm) {
        cin >> val;
    }

    map<int, int> cycle_length;
    preprocess(perm, cycle_length);

    vector<int> fR, fC;
    factorize(r, fR);
    factorize(c, fC);

    vector<LL> fRC;
    factorize(RC, fRC);

    vector<LL> conv(fRC.size());
    for(size_t i = 0; i < fRC.size() && fRC[i] <= K; i++) {
        if(cycle_length.count(fRC[i])) {
            conv[i] = cycle_length[fRC[i]];
        }
    }
    for(int pr : primes) if(RC % pr == 0) {
        for(size_t i = 0; i < fRC.size(); i++) {
            if(fRC[i] % pr != 0) {
                continue;
            }
            size_t idx = lower_bound(fRC.begin(), fRC.end(), fRC[i] / pr) - fRC.begin();
            conv[i] += conv[idx];
        }
    }

    function<LL(int, int)> calc = [&] (int i, int j) {
        LL lcm = (LL)i / __gcd(i, j) * j;
        size_t idx = lower_bound(fRC.begin(), fRC.end(), lcm) - fRC.begin();
        return Pow(conv[idx], (LL)r * c / lcm) * phi[i] % mod * phi[j] % mod;
    };

    LL ans = 0;
    for(int i : fR) {
        for(int j : fC) {
            ans += calc(i, j);
        }
    }
    ans %= mod;
    return ans * Pow((LL)r * c, mod - 2) % mod;
}

int main() {
    phi[1] = 1;
    d[1] = 1;
    for(int i = 2; i <= MX; i++) {
        if(!d[i]) {
            primes.push_back(i);
            phi[i] = i - 1;
            d[i] = i;
        }
        for(int j : primes) {
            int cur = i * j;
            if(cur > MX) {
                break;
            }
            d[cur] = j;
            if(d[i] == j) {
                phi[cur] = phi[i] * j;
                break;
            }
            phi[cur] = phi[i] * (j - 1);
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++) {
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
