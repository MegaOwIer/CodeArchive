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

using LL = long long;
const int MX = 1000005;

int to[MX], vis[MX];

int main() {
    Istream<> cin(stdin);
    int T;
    cin >> T;
    for(int cas = 1; cas <= T; cas++) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            int val;
            cin >> val;
            to[i] = i - val;
            assert(to[i] >= 1 && to[i] <= n);
        }
        int lst = 1;
        while(vis[lst] != cas) {
            vis[lst] = cas;
            lst = to[lst];
        }
        vector<int> S = {lst};
        for(int u = to[lst]; lst != u; u = to[u]) S.push_back(u);
        cout << S.size() << "\n";
        for(int u : S) cout << u << ' ';
        cout << "\n";
    }
    return 0;
}
