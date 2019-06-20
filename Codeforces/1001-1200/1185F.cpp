#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005, MS = 1 << 9, INF = 0x3f3f3f3f;

int n, m, f[MX], num[MS + 5];
pair<int, int> pr[MS + 5];

int read() {
    int x = 0, c = getchar();
    while(!isdigit(c)) c = getchar();
    while(isdigit(c))
        x = x * 10 + c - 48, c = getchar();
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    n = read(), m = read();
    for(int i = 1; i <= n; i++) {
        int t = read();
        while(t--)
            f[i] |= 1 << (read() - 1);
    }
    for(int i = 0; i < MS; i++) {
        for(int j = 1; j <= n; j++)
            if((i & f[j]) == f[j]) ++num[i];
    }
    for(int i = 0; i < MS; i++) pr[i] = {INF, -1};
    pair<pair<int, int>, pair<int, int>> ans = {{0, INT_MIN}, {-1, -1}};
    for(int i = 1; i <= m; i++) {
        int price = read(), sta = 0, t = read();
        while(t--)
            sta |= 1 << (read() - 1);
        ans = max(ans, {{num[sta], - price - pr[sta].first}, {pr[sta].second, i}});
        pr[sta] = min(pr[sta], {price, i});
    }
    for(int i = 0; i < MS; i++) if(pr[i].first != INF)
        for(int j = i + 1; j < MS; j++) if(pr[j].first != INF) {
            int sum = pr[i].first + pr[j].first, number = num[i | j];
            ans = max(ans, {{number, -sum}, {pr[i].second, pr[j].second}});
        }
    printf("%d %d\n", ans.second.first, ans.second.second);
    return 0;
}
