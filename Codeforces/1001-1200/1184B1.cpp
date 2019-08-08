#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;

int ans[MX], S[MX];
pair<int, int> B[MX];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> S[i];
    for(int i = 1; i <= m; i++)
        cin >> B[i].first >> B[i].second;
    sort(B + 1, B + m + 1);
    for(int i = 2; i <= m; i++) B[i].second += B[i - 1].second;
    for(int i = 1; i <= n; i++)
        printf("%d ", (upper_bound(B + 1, B + m + 1, make_pair(S[i], INT_MAX)) - 1) -> second);
    return 0;
}
