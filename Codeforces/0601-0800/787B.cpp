#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    while(m--) {
        int k;
        bitset<10005> pos, neg;
        cin >> k;
        while(k--) {
            int val;
            cin >> val;
            if(val > 0) pos[val] = 1;
            else neg[-val] = 1;
        }
        if(!(pos & neg).count())
            return puts("YES"), 0;
    }
    return puts("NO"), 0;
}
