#include<bits/stdc++.h>
using namespace std;

using mit = map<int, vector<int>>::iterator;
using sit = set<int>::iterator;
const int MX = 105;

map<int, vector<int>> points;

int main() {
    ifstream cin("cricket.in");
    ofstream cout("cricket.out");
    int n, w, h, ansl = 0;
    pair<int, int> ans = {0, 0};
    
    cin >> n >> w >> h;
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        points[x].push_back(y);
    }
    points[0].push_back(0);
    points[w].push_back(h);
    for(mit i = points.begin(), j; i != points.end(); i++) {
        set<int> S;
        S.insert(0), S.insert(h);
        for(j = i, ++j; j != points.end(); j++) {
            int cur = 0;
            pair<int, int> curans = {i -> first, 0};
            sit it1 = S.begin(), it2 = ++S.begin();
            while(it2 != S.end()) {
                if(cur < *it2 - *it1) {
                    cur = *it2 - *it1;
                    curans.second = *it1;
                }
                it1 = it2++;
            }
            cur = min(cur, j -> first - i -> first);
            if(cur > ansl)
                ansl = cur, ans = curans;
            if(cur != j -> first - i -> first)
                break;
            for(int &val : j -> second)
                S.insert(val);
        }
    }
    cout << ans.first << ' ' << ans.second << ' ' << ansl << endl;
    return 0;
}
