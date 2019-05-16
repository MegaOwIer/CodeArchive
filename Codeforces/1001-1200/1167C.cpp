#include<bits/stdc++.h>
using namespace std;

const int MX = 500005;

int N, M, ans[MX];
bool vis[MX];
vector<int> G[MX], cur;

int bfs(int S) {
    int ans = 1;
    queue<int> Q;
    Q.push(S), vis[S] = true;
    cur = {S};
    while(!Q.empty()) {
        int nw = Q.front();
        Q.pop();
        for(int &u : G[nw]) if(!vis[u]) {
            Q.push(u), ans++;
            vis[u] = true;
            cur.push_back(u);
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    while(M--) {
        int siz, pre = -1, nw;
        cin >> siz;
        for(int i = 1; i <= siz; i++) {
            cin >> nw;
            if(pre != -1) {
                G[nw].push_back(pre);
                G[pre].push_back(nw);
            }
            pre = nw;
        }
    }
    for(int i = 1; i <= N; i++) if(!vis[i]) {
        int siz = bfs(i);
        for(int &val : cur) ans[val] = siz;
    }
    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    return 0;
}
