#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;

int N, M, b[MX], g[MX];
long long ans;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        cin >> b[i];
        ans += b[i];
    }
    sort(b + 1, b + N + 1);
    for(int i = 1; i <= M; i++) cin >> g[i];
    sort(g + 1, g + M + 1);
    if(b[N] > g[1]) {
        return puts("-1"), 0;
    }
    ans *= M;
    bool flag = false;
    for(int i = 1; i <= M; i++) {
        if(g[i] == b[N])
            flag = true;
        ans += g[i] - b[N];
    }
    if(!flag) {
        if(N == 1)
            return puts("-1"), 0;
        else
            ans += b[N] - b[N - 1];
    }
    cout << ans << endl;
    return 0;
}
