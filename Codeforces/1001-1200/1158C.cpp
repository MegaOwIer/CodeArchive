#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
using pii = pair<int, int>;
const int MX = 500005;

int r[MX], ans[MX];
vector<pii> seg;

int work() {
    int N;
    cin >> N;
    seg.clear();
    for(int i = 1; i <= N; i++) {
        cin >> r[i];
        if(r[i] != -1)
            seg.push_back({i, r[i]});
    }
    memset(ans + 1, 0, sizeof(int) * N);
    sort(seg.begin(), seg.end());
    priority_queue<int, vector<int>, greater<int>> rval;
    rval.push(N + 1);
    for(vector<pii>::iterator i = seg.begin(), j; i != seg.end(); i = j) {
        while(rval.size() > 1 && rval.top() <= i -> first) rval.pop();
        for(j = i; j != seg.end() && j -> first == i -> first; j++);
        for(auto k = i; k != j; k++)
            if(k -> second > rval.top())
                return cout << "-1" << ENDL, 0;
        for(auto k = i; k != j; k++)
            rval.push(k -> second);
    }
    sort(seg.begin(), seg.end(), [](const pii &a, const pii &b){
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    });
    int curval = N;
    ans[N + 1] = N + 1;
    for(auto &qwq : seg) {
        if(!ans[qwq.second])
            ans[qwq.second] = curval--;
        if(!ans[qwq.first])
            ans[qwq.first] = curval--;
    }
    for(int i = 1; i <= N; i++)
        if(!ans[i]) ans[i] = curval--;
    for(int i = 1; i <= N; i++)
        cout << ans[i] << ' ';
    cout << ENDL;
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) work();
    return 0;
}
