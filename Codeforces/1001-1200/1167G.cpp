#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
const long double PI_2 = acosl(0.0), PI = acosl(-1.0);

int n, d, m;
vector<int> pos, all;

long double solve(int x) {
    if(x == 0 || x == pos.back() + 1) return PI_2;
    auto nxt = lower_bound(pos.begin(), pos.end(), x);
    auto pre = nxt - 1;
    if(*nxt == *pre + 1) return PI;
    if(*nxt == x || *pre == x - 1) return PI_2;
    long double ans = atanl(1.0l / min(*nxt - x, x - *pre - 1));
    nxt = lower_bound(all.begin(), all.end(), x);
    pre = nxt - 1;
    while(nxt < all.end()) {
        int target = 2 * x - *pre;
        while(nxt < all.end() && *nxt < target) ++nxt;
        if(nxt == all.end()) break;
        long double alpha = 2 * atanl(1.0l / (*nxt - x));
        if(alpha < ans + 1e-10l) break;
        target = 2 * x - *nxt;
        while(pre >= all.begin() && *pre > target) --pre;
        if(pre < all.begin()) break;
        if(*pre == target) {
            ans = max(ans, alpha);
            break;
        }
        ++nxt;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    cin >> n >> d;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        pos.push_back(val);
        all.push_back(val), all.push_back(val + 1);
    }
    all.erase(unique(all.begin(), all.end()), all.end());
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        cout << solve(x) << ENDL;
    }
    return 0;
}
