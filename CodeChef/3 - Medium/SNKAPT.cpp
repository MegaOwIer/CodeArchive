#include<bits/stdc++.h>
using namespace std;

const int MX = 256, ME = 125190, MV = 41480;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

struct edge {
    int to, nxt, f, c;
}e[ME << 1];

int n, m, z, t, S, T, tot = 1, head[MV];
int dis[MV], from[MV];
bool inq[MV];
char s[MX][MX];
vector<tuple<int, int, int>> Tree[MX][MX];

inline int getID(int x, int y, int t, int res) {
    return (1 + t * n * m + x * m + y) * 2 - res;
}
inline bool check(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return false;
    if(s[x][y] == '#') return false;
    return true;
}

int getVal(int x, int y, int t) {
    int ans = 0;
    for(auto &cur : Tree[x][y])
        if(get<0>(cur) <= t && t < get<1>(cur))
            ans = max(ans, get<2>(cur));
    return ans;
}

void add_edge(int u, int v, int f, int c) {
    e[++tot] = (edge){v, head[u], f, c}, head[u] = tot;
    e[++tot] = (edge){u, head[v], 0, -c}, head[v] = tot;
}

bool SPFA() {
    memset(dis + 1, 0xc0, sizeof(int[T]));
    memset(inq + 1, false, sizeof(bool[T]));
    queue<int> Q;
    Q.push(S), dis[S] = 0;
    while(!Q.empty()) {
        int nw = Q.front();
        Q.pop(), inq[nw] = false;
        for(int i = head[nw]; i; i = e[i].nxt)
            if(e[i].f && dis[nw] + e[i].c > dis[e[i].to]) {
                dis[e[i].to] = dis[nw] + e[i].c;
                from[e[i].to] = i;
                if(!inq[e[i].to])
                    Q.push(e[i].to), inq[e[i].to] = true;
            }
    }
    return dis[T] != 0xc0c0c0c0;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> z >> t;
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 1; i <= z; i++) {
        int x, y, p, q, h;
        cin >> x >> y >> p >> q >> h;
        Tree[x - 1][y - 1].push_back({p, q, h});
    }
    for(int i = 0; i < t; i++) {
        for(int x = 0; x < n; x++)
            for(int y = 0; y < m; y++) if(s[x][y] != '#') {
                for(int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if(!check(nx, ny)) continue;
                    add_edge(getID(x, y, i, 0), getID(nx, ny, i + 1, 1), 1, 0);
                }
                add_edge(getID(x, y, i, 0), getID(x, y, i + 1, 1), 1, getVal(x, y, i));
                add_edge(getID(x, y, i, 1), getID(x, y, i, 0), 1, 0);
            }
    }
    S = 2 * n * m * (t + 1) + 1, T = S + 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            add_edge(getID(i, j, t, 0), T, 1, 0);
            add_edge(getID(i, j, t, 1), getID(i, j, t, 0), 1, 0);
            if(s[i][j] == 'S')
                add_edge(S, getID(i, j, 0, 1), 1, 0);
        }
    long long ans = 0;
    while(SPFA()) {
        if(dis[T] <= 0) break;
        for(int i = T; i != S; i = e[from[i] ^ 1].to) {
            int id = from[i];
            e[id].f--, e[id ^ 1].f++;
        }
        ans += dis[T];
    }
    cout << ans << endl;
    return 0;
}
