#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 2005;

char s[MX][MX], t[MX][MX];
pair<int, int> mx[30], mn[30];

inline int getID(char x) {return x == '.' ? 0 : x - 'a' + 1;}

int work() {
    for(int i = 1; i <= 26; i++) {
        mn[i] = {INT_MAX, INT_MAX};
        mx[i] = {0, 0};
    }
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for(int j = 1; j <= m; j++) {
            int id = getID(s[i][j]);
            ans = max(ans, id);
            mn[id] = min(mn[id], {i, j});
            mx[id] = max(mx[id], {i, j});
        }
        memset(t[i] + 1, '.', sizeof(char[m]));
    }
    for(int i = 1; i <= ans; i++) {
        if(mx[i].first == 0) continue;
        if(mn[i].first != mx[i].first && mn[i].second != mx[i].second)
            return puts("NO");
    }
    for(int i = 1; i <= ans; i++) {
        if(mx[i].first == 0) {
            mn[i] = mn[ans];
            mx[i] = mx[ans];
        }
        if(mn[i].first == mx[i].first) {
            for(int j = mn[i].second; j <= mx[i].second; j++)
                t[mn[i].first][j] = 'a' + i - 1;
        } else {
            for(int j = mn[i].first; j <= mx[i].first; j++)
                t[j][mn[i].second] = 'a' + i - 1;
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(s[i][j] != t[i][j]) return puts("NO");
    printf("YES\n%d\n", ans);
    for(int i = 1; i <= ans; i++)
        printf("%d %d %d %d\n", mn[i].first, mn[i].second, mx[i].first, mx[i].second);
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) work();
    return 0;
}
