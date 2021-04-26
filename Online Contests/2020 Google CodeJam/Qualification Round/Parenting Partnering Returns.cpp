/* Qualification Round
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020bdf9
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;

int l[MX], r[MX];
char ans[MX], vis[MX << 1];
vector<int> G[MX << 1];

bool BFS(int i, int n) {
    queue<int> Q;
    Q.push(i), vis[i] = true;
    while(!Q.empty()) {
        int u = Q.front();
        if(u <= n) {
            if(ans[u]) return false;
            else ans[u] = 'J';
        } else {
            if(ans[u - n]) return false;
            else ans[u - n] = 'C';
        }
        Q.pop();
        for(int v : G[u]) if(!vis[v]) Q.push(v), vis[v] = true;
    }
    return true;
}

string solve(int n) {
    memset(ans + 1, 0, sizeof(int[n + 1]));
    memset(vis + 1, 0, sizeof(bool[n * 2]));

    for(int i = 1; i <= n; i++)
        if(!ans[i] && !BFS(i, n)) return "Impossible";

    return string(ans + 1, ans + n + 1);
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;

        for(int i = 1; i <= n * 2; i++) G[i].clear();
        for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];

        function<bool(int, int)> check = [&](int i, int j) {
            if(l[i] < l[j]) return l[j] < r[i];
            else return l[i] < r[j];
        };

        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) if(check(i, j)) {
                G[i].push_back(j + n);
                G[j].push_back(i + n);
                G[i + n].push_back(j);
                G[j + n].push_back(i);
            }
        }

        cout << "Case #" << _ << ": " << solve(n) << "\n";
    }
    return 0;
}
