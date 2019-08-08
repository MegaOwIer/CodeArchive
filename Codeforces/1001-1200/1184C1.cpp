#include<bits/stdc++.h>
using namespace std;

map<int, vector<int>> X, Y;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 0; i <= 4 * n; i++) {
        int x, y;
        cin >> x >> y;
        X[x].push_back(y);
        Y[y].push_back(x);
    }
    if((X.begin() -> second).size() == 1)
        return printf("%d %d\n", X.begin() -> first, (X.begin() -> second).front()), 0;
    if((X.rbegin() -> second).size() == 1)
        return printf("%d %d\n", X.rbegin() -> first, (X.rbegin() -> second).front()), 0;
    if((Y.begin() -> second).size() == 1)
        return printf("%d %d\n", (Y.begin() -> second).front(), Y.begin() -> first), 0;
    if((Y.rbegin() -> second).size() == 1)
        return printf("%d %d\n", (Y.rbegin() -> second).front(), Y.rbegin() -> first), 0;
    int x1 = X.begin() -> first, x2 = X.rbegin() -> first;
    int y1 = Y.begin() -> first, y2 = Y.rbegin() -> first;
    for(auto &cur : X) if(cur.first != x1 && cur.first != x2) {
        for(int y : cur.second) if(y != y1 && y != y2)
            return printf("%d %d\n", cur.first, y), 0;
    }
    return 19260817;
}