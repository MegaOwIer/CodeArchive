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

#define ENDL "\n"
const int MX = 10005;

struct edge {
    int to, nxt, w;
}e[MX * 10];

int sumw[MX], ind[MX], head[MX], tot, que[MX];
double dp[MX], p[MX];
bool vis[MX];

void dfs(int u) {
    if(vis[u]) return;
    vis[u] = true, dp[u] = 0;
    for(int i = head[u]; i; i = e[i].nxt) {
        int v = e[i].to, w = e[i].w;
        dfs(v);
        dp[u] += w * (dp[v] + 1);
    }
    if(sumw[u] > 0) dp[u] /= sumw[u];
}

void bfs(int n) {
    p[1] = 1;
    for(int i = 2; i <= n; i++) p[i] = 0;
    int tail = 0;
    for(int i = 1; i <= n; i++) if(!ind[i]) que[++tail] = i;
    for(int id = 1; id <= tail; ++id) {
        int nw = que[id];
        for(int i = head[nw]; i; i = e[i].nxt) {
            int v = e[i].to;
            p[v] += p[nw] * e[i].w / sumw[nw];
            if(!--ind[v]) que[++tail] = v;
        }
    }
}

int main() {
    Istream<> cin(stdin);
    while(true) {
        int n, m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        tot = 0;
        memset(head + 1, 0, sizeof(int[n]));
        memset(sumw + 1, 0, sizeof(int[n]));
        memset(vis + 1, false, sizeof(bool[n]));
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            ++u, ++v, ++ind[v];
            e[++tot] = (edge){v, head[u], w}, head[u] = tot;
            sumw[u] += w;
        }
        dfs(1), bfs(n);
        double ans = dp[1];
        for(int i = 1; i <= n; i++)
            for(int j = head[i]; j; j = e[j].nxt) {
                int v = e[j].to, w = e[j].w;
                if(e[j].w == sumw[i]) break;
                double tmp = (dp[i] * sumw[i] - w * (dp[v] + 1)) / (sumw[i] - w);
                ans = max(ans, dp[1] + (tmp - dp[i]) * p[i]);
            }
        printf("%.8lf\n", ans);
    }
    return 0;
}
