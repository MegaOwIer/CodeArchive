#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;

int N, x, pre[MX];
vector<int> pos[MX], a;
vector<pair<int, int>> suf;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> x;
    for(int i = 1, val; i <= N; i++) {
        cin >> val;
        a.push_back(val);
        pos[val].push_back(i);
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    memset(pre + 1, -1, sizeof(int[x + 1]));
    for(int i = 1; i <= x; i++)
        if(pos[i].empty()) pre[i] = pre[i - 1];
        else if(pos[i].front() > pre[i - 1]) pre[i] = pos[i].back();
        else break;
    suf.push_back({N + 1, x + 1});
    for(int i = x; i >= 1; i--)
        if(pos[i].empty()) suf.push_back({suf.back().first, i});
        else if(pos[i].back() < suf.back().first) suf.push_back({pos[i].front(), i});
        else break;
    reverse(suf.begin(), suf.end());
    long long ans = x - max(1, suf.front().second - 1) + 1;
    for(int i = 1; i < x && pre[i] != -1; i++)
        ans += x + 1 - max(i + 1, lower_bound(suf.begin(), suf.end(), make_pair(pre[i] + 1, 0)) -> second - 1);
    cout << ans << endl;
    return 0;
}
