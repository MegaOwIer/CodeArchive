#include<bits/stdc++.h>
using namespace std;

using LL = long long;

bool vis[105];

bool check(string s, string t, string p) {
    map<char, int> M;
    for(char c : p) M[c]++;
    memset(vis, false, sizeof(vis));
    for(size_t i = 0, j = 0; i < s.length(); i++, j++) {
        while(j < t.length() && t[j] != s[i]) j++;
        if(j == t.length()) return false;
        vis[j] = true;
    }
    for(size_t i = 0; i < t.length(); i++) if(!vis[i]) {
        if(M[t[i]] == 0) return false;
        else M[t[i]]--;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string s, t, p;
        cin >> s >> t >> p;
        puts(check(s, t, p) ? "YES" : "NO");
    }
    return 0;
}
