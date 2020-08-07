#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using LD = long double;

const int MX = 3005;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n, K;
    string s;
    cin >> n >> K >> s;
    vector<vector<int>> T;
    int mxval = 0;
    while(true) {
        vector<int> tmp;
        for(size_t i = 0; i < s.length() - 1; i++)
            if(s[i] == 'R' && s[i + 1] == 'L') tmp.push_back(i);
        for(int u : tmp) swap(s[u], s[u + 1]);
        if(tmp.empty()) break;
        T.push_back(tmp);
        mxval += tmp.size();
    }
    if(K < T.size() || K > mxval) return puts("-1"), 0;
    for(size_t i = 0; i < T.size(); i++) {
        int num = min(K - (T.size() - i), T[i].size() - 1);
        while(num--) {
            cout << "1 " << T[i].back() + 1 << "\n";
            K--, T[i].pop_back();
        }
        cout << T[i].size() << ' ';
        for(int u : T[i]) cout << u + 1 << ' ';
        cout << "\n";
        K--;
    }
    return 0;
}
