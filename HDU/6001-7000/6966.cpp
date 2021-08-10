#include <bits/stdc++.h>
using namespace std;

class Istream {
    static const int BUFF_SIZE = 10000000;
    FILE *F;
    char bf[BUFF_SIZE], *p1, *p2;

public:
    Istream(FILE *_F = stdin) : F(_F), p1(bf), p2(bf) {}
    Istream(string f) : F(fopen(f.c_str(), "r")), p1(bf), p2(bf) {}
    ~Istream() {fclose(F);}

    int getChar() {
        return p1 == p2 && (p2 = (p1 = bf) + fread(bf, sizeof(char), BUFF_SIZE, F)) == bf ? 
            EOF : 
            static_cast<int>(*p1++);
    }
    template<typename T = int>
    T getNumber() {
        int f = 1, c;
        T x = 0;
        while(!isdigit(c = getChar()))
            if(c == '-') f = -1;
        while(isdigit(c))
            x = x * 10 + c - '0', c = getChar();
        return x * f;
    }
    
    Istream& operator>> (char &c) {
        c = static_cast<char>(getChar());
        return *this;
    }
    template<typename T>
    Istream& operator>> (T &x) {
        x = getNumber<T>();
        return *this;
    }
};

using LL = long long;
const int MX = 200005;
const int mod = 1000000007;

vector<int> a, b, c;
set<int> pw3;

const int trans[2][3][3] = {
    {{1, 1, 1}, {1, 0, 1}, {1, 0, 0}}, 
    {{0, 0, 1}, {1, mod - 1, 0}, {0, 1, mod - 1}}
};

void DFT(int *A, int *end, int f) {
    int n = end - A;
    if(n == 1) return;
    int l = n / 3;
    for(int i = 0; i < 3; i++) {
        DFT(A + l * i, A + l * (i + 1), f);
    }
    for(int i = 0; i < l; i++) {
        int tmp[3] = {A[i], A[i + l], A[i + l * 2]};
        for(int j = 0; j < 3; j++) {
            int &cur = A[i + l * j];
            cur = 0;
            for(int k = 0; k < 3; k++) {
                cur = (cur + (LL)trans[f][j][k] * tmp[k]) % mod;
            }
        }
    }
}

int A[MX * 3], B[MX * 3];

int main() {
    for(int i = 0, tmp = 1; i <= 12; i++, tmp *= 3) {
        pw3.insert(tmp);
    }

    Istream cin(stdin);
    int n;
    cin >> n;

    a.resize(n);
    b.resize(n);
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int lst = 0, lth = 0;
    int ans = 0;
    for(int p = 1; p <= n; p++) {
        if(n / p != lst) {
            lst = n / p;
            a.resize(lst), b.resize(lst);
            
            lth = *pw3.upper_bound(lst);
            
            memset(A, 0, sizeof(int[lth]));
            memcpy(A + 1, a.data(), sizeof(int[lst]));
            DFT(A, A + lth, 0);
            
            memset(B, 0, sizeof(int[lth]));
            memcpy(B + 1, b.data(), sizeof(int[lst]));
            DFT(B, B + lth, 0);

            for(int i = 0; i < lth; i++) {
                A[i] = (LL)A[i] * B[i] % mod;
            }
            DFT(A, A + lth, 1);
        }

        int cur = 0, x = c[p - 1];
        for(int i = lth - 1; i >= 0; i--) {
            cur = ((LL)cur * x + A[i]) % mod;
        }
        ans = (ans + cur) % mod;
    }
    cout << ans << "\n";
    return 0;
}
