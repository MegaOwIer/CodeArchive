#include<bits/stdc++.h>
using namespace std;

using LL = long long;

queue<int> pos[6];

int getID(int x) {
    switch(x) {
        case 4: return 0;
        case 8: return 1;
        case 15: return 2;
        case 16: return 3;
        case 23: return 4;
        case 42: return 5;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        pos[getID(val)].push(i);
    }
    int ans = 0;
    while(!pos[0].empty()) {
        int pre = pos[0].front();
        pos[0].pop();
        bool flag = false;
        for(int i = 1; i < 6; i++) {
            while(!pos[i].empty() && pos[i].front() < pre)
                pos[i].pop();
            if(pos[i].empty()) {
                flag = true;
                break;
            }
            pre = pos[i].front();
            pos[i].pop();
        }
        if(flag) break;
        ans++;
    }
    cout << n - ans * 6 << "\n";
    return 0;
}
