/* 2021-02-03
 * Stern-Brocot Tree
 */

#include <bits/stdc++.h>
using namespace std;

class Ostream {
    const static int BUFF_SIZE = 5000000;
    FILE *F;
    char bf[BUFF_SIZE], *p1, *const p2;
    
public:
    Ostream(FILE *_F = stdout) : F(_F), p1(bf), p2(bf + BUFF_SIZE) {}
    Ostream(string f) : F(fopen(f.c_str(), "w")), p1(bf), p2(bf + BUFF_SIZE) {}
    ~Ostream() {flush(), fclose(F);}
    
    void putchar(int x) {
        *p1++ = static_cast<char>(x);
        if(p1 == p2) flush();
    }
    Ostream& operator<< (char c) {return putchar(c), *this;}
    template<typename T>
    Ostream& operator<< (T x) {
        static char dig[45], *top = dig;
        if(x < 0) putchar('-'), x = -x;
        do *top++ = static_cast<char>('0' + x % 10);
        while(x /= 10);
        while(top != dig) putchar(*--top);
        return *this;
    }
    Ostream& operator<< (const char *s) {
        while(*s) putchar(*s++);
        return *this;
    }
    void flush() {fwrite(bf, sizeof(char), p1 - bf, F), p1 = bf;}
};

using ull = unsigned long long;
using uLL = __uint128_t;

Ostream fout;

uLL solve(ull n) {
    ull v = sqrtl(n), w = cbrtl(n);
    while(v * v <= n) v++;
    while(v * v > n) v--;

    auto outside = [&](ull x, ull y) {return x * y > n;};
    auto cut_off = [&](ull x, ull dx, ull dy) {return (uLL)dy * x * x >= (uLL)n * dx;};

    ull x = n / v, y = n / x + 1, dx, dy;
    uLL ans = 0;
    vector<pair<ull, ull>> que = {{1, 0}, {1, 1}};
    while(!que.empty()) {
        tie(dx, dy) = que.back();
        while(outside(x + dx, y - dy)) {
            ans += x * dy + (uLL)(dy + 1) * (dx - 1) / 2;
            x += dx, y -= dy;
        }
        if(y <= w) break;
        ull ux, uy, mx, my;
        do {
            que.pop_back();
            ux = dx, uy = dy;
            tie(dx, dy) = que.back();
        } while(!outside(x + dx, y - dy));
        while(true) {
            mx = dx + ux, my = dy + uy;
            if(outside(x + mx, y - my)) {
                que.emplace_back(dx = mx, dy = my);
            } else {
                if(cut_off(x + mx, dx, dy)) break;
                ux = mx, uy = my;
            }
        }
    }
    while(--y) ans += n / y;
    return ans * 2 - v * v;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        ull x;
        scanf("%llu", &x);
        fout << solve(x) << "\n";
    }
    return 0;
}
