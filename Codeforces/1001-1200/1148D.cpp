#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if(a > b) A.push_back({b, i});
        else B.push_back({b, i});
    }
    if(A.size() > B.size()) {
        sort(A.begin(), A.end());
        cout << A.size() << "\n";
        for(auto tmp : A)
            cout << tmp.second << ' ';
    } else {
        sort(B.begin(), B.end(), greater<pair<int, int>>());
        cout << B.size() << "\n";
        for(auto tmp : B)
            cout << tmp.second << ' ';
    }
    return 0;
}
