#include<bits/stdc++.h>
using namespace std;

using LL = long long;
using pii = pair<int, int>;
const int MX = 200005;

int n;
pii s[MX];
vector<int> tmp;

void check(int l, int r, int ans) {
    int d = (s[r].first - s[l].first) / (n - 2);
    for(int i = l; i <= r; i++)
        if(s[i].first != s[l].first + (i - l) * d)
            return;
    printf("%d\n", s[ans].second);
    exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int var;
        cin >> var;
        s[i] = {var, i};
    }
    if(n == 2) return puts("1"), 0;
    sort(s + 1, s + n + 1);
    s[n + 1].first = INT_MAX;

    check(2, n, 1), check(1, n - 1, n);

    int d = (s[n].first - s[1].first) / (n - 2);
    if(d * (n - 2) != s[n].first - s[1].first)
        return puts("-1"), 0;
    for(int i = 1, cur = s[1].first, j = 1; i <= n; i = ++j) {
        while(j <= n && s[j].first < cur) {
            tmp.push_back(s[j].second);
            j++;
        }
        if(s[j].first > cur) return puts("-1"), 0;
        cur += d;
    }
    assert(tmp.size() == 1);
    printf("%d\n", tmp[0]);
    return 0;
}
