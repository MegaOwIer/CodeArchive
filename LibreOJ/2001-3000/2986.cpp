#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;

struct info_t {
    bool vis[4][4];

    info_t() {memset(vis, false, sizeof(vis));}
    
    info_t operator+ (const info_t &u);
    bool *operator[] (int u) {return vis[u];}
    const bool *operator[] (int u) const {return vis[u];}
};

info_t info_t::operator+ (const info_t &u) {
    info_t res;
    res[0][1] = vis[0][1] || (u[0][1] && ((vis[0][2] && vis[1][3]) || (vis[0][3] && vis[1][2])));
    res[0][2] = (vis[0][2] && u[0][2]) || (vis[0][3] && u[1][2]);
    res[0][3] = (vis[0][2] && u[0][3]) || (vis[0][3] && u[1][3]);
    res[1][2] = (vis[1][2] && u[0][2]) || (vis[1][3] && u[1][2]);
    res[1][3] = (vis[1][2] && u[0][3]) || (vis[1][3] && u[1][3]);
    res[2][3] = u[2][3] || (vis[2][3] && ((u[0][2] && u[1][3]) || (u[0][3] && u[1][2])));
    return res;
}

bool edges[3][MX];
info_t node[MX << 2];

void update(int l, int r, int id, int pos) {
    if(l == r) {
        info_t &cur = node[id];
        cur[0][1] = edges[0][pos] || (edges[0][pos + 1] && edges[1][pos] && edges[2][pos]);
        cur[0][2] = edges[1][pos] || (edges[0][pos] && edges[2][pos] && edges[0][pos + 1]);
        cur[0][3] = (edges[1][pos] && edges[0][pos + 1]) || (edges[0][pos] && edges[2][pos]);
        cur[1][2] = (edges[0][pos] && edges[1][pos]) || (edges[2][pos] && edges[0][pos + 1]);
        cur[1][3] = edges[2][pos] || (edges[0][pos] && edges[1][pos] && edges[0][pos + 1]);
        cur[2][3] = edges[0][pos + 1] || (edges[1][pos] && edges[0][pos] && edges[2][pos]);
        return;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) update(l, mid, id << 1, pos);
    else update(mid + 1, r, id << 1 | 1, pos);
    node[id] = node[id << 1] + node[id << 1 | 1];
}

info_t query(int l, int r, int id, int L, int R) {
    if(L <= l && r <= R) return node[id];
    info_t res;
    res[0][2] = res[1][3] = true;
    int mid = (l + r) >> 1;
    if(L <= mid) res = res + query(l, mid, id << 1, L, R);
    if(R > mid) res = res + query(mid + 1, r, id << 1 | 1, L, R);
    return res;
}

int main() {
    int n;
    scanf("%d", &n);
    while(true) {
        char type[5];
        scanf("%s", type);
        if(type[0] == 'E') {
            break;
        }
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        if(type[0] == 'A') {
            bool ans = false;
            if(y1 == y2) {
                ans = query(0, n, 1, 0, y1 - 1)[2][3] || query(0, n, 1, y1, n)[0][1];
            } else {
                if(y1 > y2) {
                    swap(x1, x2);
                    swap(y1, y2);
                }
                int id1 = x1 - 1, id2 = x2 + 1;
                info_t lft = query(0, n, 1, 0, y1 - 1), 
                       mid = query(0, n, 1, y1, y2 - 1), 
                       rgt = query(0, n, 1, y2, n);
                int l = (lft[2][3] || mid[0][1]), r = (mid[2][3] || rgt[0][1]);
                ans = mid[id1][id2] || mid[id1 ^ l][id2] || mid[id1][id2 ^ r] || mid[id1 ^ l][id2 ^ r];
            }
            puts(ans ? "Y" : "N");
        } else {
            if(x1 == x2) {
                edges[x1][min(y1, y2)] = (type[0] == 'O');
                update(0, n, 1, min(y1, y2));
            } else {
                edges[0][y1] = (type[0] == 'O');
                update(0, n, 1, y1 - 1);
                update(0, n, 1, y1);
            }
        }
    }
    return 0;
}
