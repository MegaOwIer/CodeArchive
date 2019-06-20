#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100005;
const char str[] = "aeiou";

int n;
map<int, vector<string>> G[5], res;
vector<pair<string, string>> All, Half;

int getID(char x) {
    switch(x) {
        case 'a': return 0;
        case 'e': return 1;
        case 'i': return 2;
        case 'o': return 3;
        case 'u': return 4;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        string ss;
        cin >> ss;
        int cnt = 0;
        char last = 0;
        for(char cur : ss)
            for(const char j : str) if(cur == j) {
                last = j;
                ++cnt;
            }
        G[getID(last)][cnt].push_back(ss);
    }
    for(int i = 0; i < 5; i++)
        for(auto tmp : G[i]) {
            for(size_t i = 0; i + 1 < tmp.second.size(); i += 2)
                All.push_back({tmp.second[i], tmp.second[i + 1]});
            if(tmp.second.size() % 2 == 1)
                res[tmp.first].push_back(tmp.second.back());
        }
    for(auto tmp : res) {
        for(size_t i = 0; i + 1 < tmp.second.size(); i += 2)
            Half.push_back({tmp.second[i], tmp.second[i + 1]});
    }
    int ans = min(All.size(), Half.size()) + max<int>(All.size() - Half.size(), 0) / 2;
    cout << ans << "\n";
    for(size_t i = 0; i < All.size() && i < Half.size(); i++) {
        cout << Half[i].first << ' ' << All[i].first << "\n";
        cout << Half[i].second << ' ' << All[i].second << "\n";
    }
    for(size_t i = min(All.size(), Half.size()); i + 1 < All.size(); i += 2) {
        cout << All[i].first << ' ' << All[i + 1].first << "\n";
        cout << All[i].second << ' ' << All[i + 1].second << "\n";
    }
    return 0;
}
