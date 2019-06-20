#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000006;

namespace BSGS {
    const int mod = 1000000007, g = 5;
    map<int, int> G;
    int B;
    
    int Pow(int a, int b) {
        int ans = 1;
        for(; b; b >>= 1, a = (LL)a * a % mod)
            if(b & 1) ans = (LL)ans * a % mod;
        return ans;
    }
    int getLog(int x) {
        for(int i = 0; i <= B; i++, x = (LL)x * g % mod)
            if(G.count(x)) return G[x] - i;
        throw;
    }
    int getVal(int x) {return Pow(g, x);}
    void __init__() {
        B = 31700;
        for(int i = 0; i < mod; i += B) G[Pow(g, i)] = i;
    }
}

struct Matrix {
    int a[5][5];
    Matrix() {memset(a, 0, sizeof(a));}
    int* operator [] (int x) {return a[x];}
    Matrix operator * (Matrix m) {
        Matrix ans;
        for(int i = 0; i < 5; i++)
            for(int k = 0; k < 5; k++)
                for(int j = 0; j < 5; j++)
                    ans[i][j] = (ans[i][j] + (LL)a[i][k] * m[k][j]) % mod;
        return ans;
    }
}trans;

int f[4], c;
LL n;

vector<int> d;

Matrix Pow(Matrix a, LL b) {
    Matrix ans;
    for(int i = 0; i < 5; i++) ans[i][i] = 1;
    for(; b; b >>= 1, a = a * a)
        if(b & 1) ans = ans * a;
    return ans;
}

int main() {
    BSGS::__init__();
    ios::sync_with_stdio(false);
    cin >> n >> f[1] >> f[2] >> f[3] >> c;
    for(int i : {1, 2, 3}) {
        int k = f[i];
        f[i] = BSGS::getLog(f[i]);
        assert(BSGS::getVal(f[i]) == k);
    }
    c = BSGS::getLog(c);
    trans[0][0] = trans[0][1] = trans[0][2] = 1;
    trans[0][3] = c * 2 % mod;
    trans[0][4] = c * LL(mod - 6) % mod;
    trans[1][0] = trans[2][1] = trans[3][3] = trans[3][4] = trans[4][4] = 1;
    trans = Pow(trans, n - 3);
    int ans = 0;
    ans = (ans + (LL)trans[0][0] * f[3]) % mod;
    ans = (ans + (LL)trans[0][1] * f[2]) % mod;
    ans = (ans + (LL)trans[0][2] * f[1]) % mod;
    ans = (ans + trans[0][3] * 4LL) % mod;
    ans = (ans + trans[0][4]) % mod;
    cout << BSGS::getVal(ans) << "\n";
    return 0;
}
