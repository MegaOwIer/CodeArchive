#include<bits/stdc++.h>
using namespace std;

using LL = long long;

LL pws[20];

inline int cmp(char a, char b) {
    return a == b ? 0 : (a > b ? 1 : -1);
}

long long ask(const string n, const string k, int index, int cmpn, bool cmpk) {
    long long ans = (index != 0);
    if(cmpk) {
        if(index == static_cast<int>(k.size())) return 1;
        ans += ask(n, k, index + 1, cmpn ? cmpn : cmp(k[index], n[index]), true);
        for(int i = index ? 0 : 1; i < k[index] - '0'; i++)
            ans += ask(n, k, index + 1, cmpn ? cmpn : cmp('0' + i, n[index]), false);
    } else {
        if(index == static_cast<int>(n.length())) {
            return cmpn > 0 ? 0 : 1;
        }
        if(cmpn == 0) {
            for(int i = 0; i < 10; i++)
                ans += ask(n, k, index + 1, cmp('0' + i, n[index]), false);
        } else {
            return pws[n.length() - index - (cmpn == 1)];
        }
    }
    return ans;
}

int main() {
    ifstream cin("amusing.in");
    ofstream cout("amusing.out");
    pws[0] = 1;
    for(int i = 1; i <= 18; i++)
        pws[i] = pws[i - 1] * 10LL + 1;

    int k, m;
    cin >> k >> m;

    LL l = k, r = static_cast<LL>(1e18), ans = 0;
    while(l <= r) {
        long long mid = (l + r) >> 1;
        long long tmp = ask(to_string(mid), to_string(k), 0, 0, true);
        if(tmp >= m) r = mid - 1;
        else l = mid + 1;
        if(tmp == m) ans = mid;
    }
    cout << ans << endl;
    return 0;
}
