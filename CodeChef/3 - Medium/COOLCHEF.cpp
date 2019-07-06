#include<bits/stdc++.h>
using namespace std;

template<int MX = 2000000>
struct Istream {
    FILE *F;
    char bf[MX], *p1, *p2;

    Istream() : F(stdin), p1(bf), p2(bf) {}
    Istream(FILE *F) : F(F), p1(bf), p2(bf) {}
    Istream(string f) : F(fopen(f.c_str(), "r")), p1(bf), p2(bf) {}
    ~Istream() {fclose(F);}
    
    int getchar() {
        return p1 == p2 && (p2 = (p1 = bf) + fread(bf, sizeof(char), MX, F)) == bf ? 
            EOF : 
            static_cast<int>(*p1++);
    }
    Istream& operator >> (char &c) {return c = getchar(), *this;}
    template<typename T>
    Istream& operator >> (T &x) {
        int f = 1, c;
        x = 0;
        while(!isdigit(c = getchar()))
            if(c == '-') f = -1;
        while(isdigit(c))
            x = x * 10 + c - '0', c = getchar();
        return x *= f, *this;
    }
};

template<int MX = 2000000>
struct Ostream {
    FILE *F;
    char bf[MX], *p1, *const p2;
    
    Ostream() : F(stdout), p1(bf), p2(bf + MX) {}
    Ostream(FILE *F) : F(F), p1(bf), p2(bf + MX) {}
    Ostream(string f) : F(fopen(f.c_str(), "w")), p1(bf), p2(bf + MX) {}
    ~Ostream() {flush(), fclose(F);}
    
    void putchar(int x) {*p1++ = x; if(p1 == p2) flush();}
    Ostream& operator << (char &c) {return putchar(c), *this;}
    template<typename T>
    Ostream& operator << (T x) {
        static char dig[20], *top = dig;
        if(x < 0) putchar('-'), x = -x;
        do *top++ = '0' + x % 10;
        while(x /= 10);
        while(top != dig) putchar(*--top);
        return *this;
    }
    Ostream& operator << (const char *s) {
        while(*s) putchar(*s++);
        return *this;
    }
    void flush() {fwrite(bf, sizeof(char), p1 - bf, F), p1 = bf;}
};

using LL = long long;
const int MX = 300005;
const int B = 549, MC = 549;
const int mod = 1000000007;

int n, a[MX], ls[MX], frac[MX];
int lft[MC], rgt[MC], Bcnt;
int ans[MC][MC], lcnt[MC][MC][B], rcnt[MC][MC][B];
int cnt[MX], vis[MX];

int Inv(int u) {return u == 1 ? 1 : LL(mod - mod / u) * Inv(mod % u) % mod;}

void getL(int l, int r) {
    for(int i = lft[l - 1], j = 0; i <= rgt[l - 1]; i++, j++)
        lcnt[l][r][j] = cnt[a[i]];
}
void getR(int l, int r) {
    for(int i = lft[r + 1], j = 0; i <= rgt[r + 1]; i++, j++)
        rcnt[l][r][j] = cnt[a[i]];
}

int BruteForce(int l, int r, int id) {
    int ans = 1;
    for(int i = l; i < r; i++) {
        if(vis[a[i]] != id)
            vis[a[i]] = id, cnt[a[i]] = 0;
        ans = ans * LL(++cnt[a[i]]) % mod;
    }
    return ans;
}
int work(int l, int r, int Bl, int Br, int id) {
    int ans = 1;
    for(int i = l, tmp = lft[Bl - 1]; i < lft[Bl]; i++) {
        if(vis[a[i]] != id)
            vis[a[i]] = id, cnt[a[i]] = 0;
        ans = ans * LL(lcnt[Bl][Br][i - tmp] + (++cnt[a[i]])) % mod;
    }
    for(int i = rgt[Br] + 1, k = 0; i <= r; i++, k++) {
        if(vis[a[i]] != id)
            vis[a[i]] = id, cnt[a[i]] = 0;
        ans = ans * LL(rcnt[Bl][Br][k] + (++cnt[a[i]])) % mod;
    }
    return ans;
}

int main() {
    Istream<> cin(stdin);
    Ostream<> cout(stdout);
    int Q;
    cin >> n >> Q;
    frac[0] = 1;
    for(int i = 1; i <= n; i++) frac[i] = (LL)frac[i - 1] * i % mod;
    for(int i = 1; i <= n; i++) cin >> a[i];
    memcpy(ls + 1, a + 1, sizeof(int[n]));
    sort(ls + 1, ls + n + 1);
    for(int i = 1; i <= n; i++)
        a[i] = lower_bound(ls + 1, ls + n + 1, a[i]) - ls;
    Bcnt = (n - 1) / B + 1;
    for(int i = 1; i <= Bcnt; i++) {
        lft[i] = (i - 1) * B + 1;
        rgt[i] = min(i * B, n);
    }
    lft[Bcnt + 1] = n + 1;
    for(int i = 1; i <= Bcnt; i++) {
        memset(cnt + 1, 0, sizeof(int[n]));
        int curans = 1;
        for(int j = i; j <= Bcnt; j++) {
            for(int k = lft[j]; k <= rgt[j]; k++)
                curans = curans * LL(++cnt[a[k]]) % mod;
            ans[i][j] = curans;
            if(i != 1) getL(i, j);
            if(j != Bcnt) getR(i, j);
        }
    }
    int lastans = 0;
    for(int T = 1; T <= Q; T++) {
        int l1, l2, r1, r2;
        cin >> l1 >> l2 >> r1 >> r2;
        int l = ((LL)l1 * lastans + l2) % n + 1;
        int r = ((LL)r1 * lastans + r2) % n + 1;
        if(l > r) swap(l, r);
        int Bl = lower_bound(lft + 1, lft + Bcnt + 1, l) - lft;
        int Br = upper_bound(rgt + 1, rgt + Bcnt + 1, r) - rgt - 1;
        if(Bl > Br) {
            lastans = BruteForce(l, r + 1, T);
        } else {
            lastans = (LL)ans[Bl][Br] * work(l, r, Bl, Br, T) % mod;
        }
        lastans = (LL)frac[r - l + 1] * Inv(lastans) % mod;
        cout << lastans << "\n";
    }
    return 0;
}
