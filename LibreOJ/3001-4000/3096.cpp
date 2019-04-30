#include<bits/stdc++.h>
using namespace std;

/*----------------- Fast Input Begin ----------------------------*/

template<int MX = 2000000>
struct Istream {
private:
	FILE *F;
	char bf[MX], *p1, *p2;
	int getchar() {
		return p1 == p2 && (p2 = (p1 = bf) + fread(bf, sizeof(char), MX, F)) == bf ? 
            EOF : 
            static_cast<int>(*p1++);
	}
public:
	Istream() : F(stdin), p1(bf), p2(bf) {}
	Istream(FILE *F) : F(F), p1(bf), p2(bf) {}
	Istream(string f) : F(fopen(f.c_str(), "r")), p1(bf), p2(bf) {}
	~Istream() {fclose(F);}
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

/*----------------- Fast Input End ----------------------------*/

using LL = long long;
const int MX = 1000005;

vector<LL> A[MX], B[MX];

void modify(int &P, int &Q, int g) {
    for(int i = 2; i * i <= g; i++) {
        int d = 1, di;
        while(g % i == 0)
            d *= i, g /= i;
        di = d * i;
        (P % di != 0) ? (P /= d) : (Q /= d);
    }
    if(g > 1)
        (P / g % g != 0) ? (P /= g) : (Q /= g);
}

int getInv(int u, int mod) {
    int phi = mod, v = mod;
    for(int i = 2; i * i <= v; i++) {
        bool flag = false;
        while(v % i == 0)
            flag = true, v /= i;
        if(flag)
            phi = phi / i * (i - 1);
    }
    if(v > 1)
        phi = phi / v * (v - 1);
    phi--;
    int ans = 1;
    for(; phi; phi >>= 1, u = (LL)u * u % mod)
        if(phi & 1) ans = (LL)ans * u % mod;
    return ans;
}

LL work(const vector<LL>& A, vector<LL>& B, LL L, LL R) {
    LL cnt = 0;
    vector<LL>::iterator l = --B.end(), r = --B.end();
    for(LL val : A) {
        while(l >= B.begin() && val + *l >= L) l--;
        while(r >= B.begin() && val + *r >= R) r--;
        cnt += r - l;
    }
    return cnt;
}

int main() {
    int P, Q, n, m, g;
    LL T, a0 = 0, mod, ans = 0;
    Istream<> cin;

    cin >> P >> Q >> n >> m >> T;
    mod = (LL)P / (g = __gcd(P, Q)) * Q;
    modify(P, Q, g);
    LL P0 = (LL)P * getInv(P, Q);
    LL Q0 = (LL)Q * getInv(Q, P);
    for(int i = 1, val; i <= n; i++) {
        cin >> val;
        A[val % g].push_back((LL)val * Q0 % mod);
    }
    for(int i = 1, val; i <= m; i++) {
        cin >> val;
        B[val % g].push_back((LL)val * P0 % mod);
    }

    for(int i = 0; i < g; i++) {
        if(A[i].empty() || B[i].empty())
            continue;
        a0 += (LL)A[i].size() * B[i].size();
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        ans += work(A[i], B[i], 0, T % mod);
        ans += work(A[i], B[i], mod, mod + T % mod);
    }
    cout << ans + T / mod * a0 << endl;
    return 0;
}
