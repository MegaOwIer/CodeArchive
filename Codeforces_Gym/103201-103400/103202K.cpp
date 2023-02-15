#include <bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int n;
    cin >> n;

    vector<int> pos, neg;
    while(n--) {
        string op;
        int val;

        cin >> op >> val;
        if(op == "+") {
            pos.push_back(val);
        } else {
            neg.push_back(val);
        }
    }

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end(), greater<int>());

    LL ans = 0;
    for(size_t i = 0; i < neg.size(); ) {
        size_t j = upper_bound(neg.begin(), neg.end(), neg[i], greater<int>()) - neg.begin();
        size_t ff = upper_bound(pos.begin(), pos.end(), neg[i]) - pos.begin();
        ans += (j - i) * (pos.size() - ff);
        i = j;
    }

    cout << (long double)ans / (pos.size() * neg.size()) << "\n";

    return 0;
}
/*
3
+ 2
- 3
- 1

*/