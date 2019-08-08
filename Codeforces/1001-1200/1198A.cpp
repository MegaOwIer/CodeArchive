#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 400005;

int n, ML, sum[MX], cnt;
map<int, int> A;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> n >> ML;
    ML = ML * 8 / n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        A[val]++;
    }
    for(auto &tmp : A)
        sum[++cnt] = tmp.second;
    for(int i = 1; i <= cnt; i++) sum[i] += sum[i - 1];
    int B = min(cnt, ML <= 19 ? 1 << ML : INT_MAX);
    int ans = 0;
    for(int i = 0, j = B; j <= cnt; i++, j++)
        ans = max(ans, sum[j] - sum[i]);
    cout << n - ans << "\n";
    return 0;
}
