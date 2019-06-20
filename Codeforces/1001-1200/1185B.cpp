#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string s, t;
        vector<pair<char, int>> S, T;
        cin >> s >> t;
        for(size_t i = 0, j = 0; i < s.length(); i = j) {
            while(j < s.length() && s[i] == s[j]) j++;
            S.push_back({s[i], j - i});
        }
        for(size_t i = 0, j = 0; i < t.length(); i = j) {
            while(j < t.length() && t[i] == t[j]) j++;
            T.push_back({t[i], j - i});
        }
        if(S.size() != T.size()) {
            puts("NO");
        } else {
            bool ans = true;
            for(size_t i = 0; i < S.size(); i++) {
                if(S[i].first != T[i].first || S[i].second > T[i].second)
                    ans = false;
            }
            puts(ans ? "YES" : "NO");
        }
    }
    return 0;
}
