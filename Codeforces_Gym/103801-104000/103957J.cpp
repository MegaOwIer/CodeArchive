#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using LD = long double;

int read() {
    string str;
    cin >> str;
    str.erase(str.length() - 5, 1);
    return atoi(str.c_str()) * 2;
}

LL sqr(LL x) { return x * x; }

LD solve() {
    int n;
    cin >> n;

    vector<LL> bricks;
    for(int i = 1; i <= n; i++) {
        int a = read(), b = read();
        if(a < b) {
            swap(a, b);
        }
        LL chr = (LL)a * a / 4 + (LL)b * b;
        bricks.push_back(chr);
    }

    sort(bricks.begin(), bricks.end(), greater<LL>());

    LD l = sqrtl(bricks[0] / 4e8), r = 1.5e5;
    for(int i = 1; i <= 40; i++) {
        LD mid = (l + r) / 2, tmp = mid * mid;
        
        long double supr = 0.5;
        for(int i = 1; 2 * i - 1 < bricks.size(); i++) {
            supr = min(supr, sqrtl(tmp - bricks[2 * i - 1] / 4e8) - i);
        }

        long double supl = 1;
        for(int i = 0; 2 * i < bricks.size(); i++) {
            supl = min(supl, sqrtl(tmp - bricks[2 * i] / 4e8) - i);
        }

        if(supl + supr < 1 - 1e-6) {
            l = mid;
        } else {
            r = mid;
        }
    }

    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for(int _ = 1; _ <= t; _++) {
        printf("Case #%d: %.9Lf\n", _, solve());
    }
    return 0;
}
