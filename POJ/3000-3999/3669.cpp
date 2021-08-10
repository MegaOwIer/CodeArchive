#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

const int MX = 305;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

unsigned dtime[MX][MX], atime[MX][MX];

void update(int x, int y, unsigned val) {
    if(x < 0 || y < 0 || x >= MX || y >= MX) return;
    dtime[x][y] = min(dtime[x][y], val);
}

int main() {
    int n;
    scanf("%d", &n);

    memset(dtime, -1, sizeof(dtime));
    for(int i = 1; i <= n; i++) {
        int x, y;
        unsigned t;
        scanf("%d%d%u", &x, &y, &t);
        update(x, y, t);
        update(x - 1, y, t);
        update(x + 1, y, t);
        update(x, y - 1, t);
        update(x, y + 1, t);
    }

    memset(atime, -1, sizeof(atime));
    atime[0][0] = 0;
    
    queue<pair<int, int> > que;
    que.push(make_pair(0, 0));
    
    while(!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();

        int x = cur.first, y = cur.second;
        if(atime[x][y] >= dtime[x][y]) continue;
        if(dtime[x][y] == -1u) {
            printf("%d\n", atime[x][y]);
            return 0;
        }
        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= MX || ny >= MX) {
                continue;
            }
            if(atime[nx][ny] != -1u) {
                continue;
            }
            atime[nx][ny] = atime[x][y] + 1;
            que.push(make_pair(nx, ny));
        }
    }
    puts("-1");
    return 0;
}
