#include<bits/stdc++.h>
using namespace std;

int n, k, index;
vector<int> id;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        id.push_back(i);
    while(k--) {
        int val;
        cin >> val;
        index = (index + val) % id.size();
        cout << id[index] << ' ';
        id.erase(id.begin() + index, id.begin() + index + 1);
    }
    return 0;
}
