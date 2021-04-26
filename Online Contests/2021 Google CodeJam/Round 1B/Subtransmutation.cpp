/* Round 1B
 * https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae4aa
 */

#include <bits/stdc++.h>
using namespace std;

using LL = long long;

bool check(int x, map<int, LL> need, int a, int b) {
    map<int, LL> own;
    own[x] = 1;
    if(need.size() == 1 && need.count(x)) {
        return need[x] == 1;
    }

    auto get_next = [&] (map<int, LL> pre) {
        map<int, LL> ans;
        for(auto cur : pre) {
            int key = cur.first;
            if(key > a) ans[key - a] += cur.second;
            if(key > b) ans[key - b] += cur.second;
        }
        return ans;
    };

    while(!need.empty()) {
        if(own.empty()) return false;
        own = get_next(own);
        map<int, LL> tmp = need;
        for(auto cur : tmp) {
            int key = cur.first;
            if(own.count(key)) {
                int d = min(need[key], own[key]);
                if(!(need[key] -= d)) {
                    need.erase(key);
                }
                if(!(own[key] -= d)) {
                    own.erase(key);
                }
            }
        }

    }
    return true;
}

string solve() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    map<int, LL> need;
    for(int i = 1; i <= n; i++) {
        int cnt;
        scanf("%d", &cnt);
        if(cnt) need[i] = cnt;
    }
    for(int i = 1; i <= 600; i++) {
        if(check(i, need, a, b)) {
            return to_string(i);
        }
    }
    return "IMPOSSIBLE";
}

int main() {
    int _;
    scanf("%d", &_);
    for(int i = 1; i <= _; i++) {
        printf("Case #%d: %s\n", i, solve().c_str());
    }
    return 0;
}