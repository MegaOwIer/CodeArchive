#include<bits/stdc++.h>
using namespace std;

int m, n;
bitset<10000> a[51], b[51], all;

int main() {
    ios::sync_with_stdio(false);
    cin >> m >> n;
    for(int i = 0; i < n; i++) all.set(i);
    for(int i = 1; i <= m; i++) {
        int k, val;
        cin >> k;
        while(k--) {
            cin >> val;
            a[i].set(val - 1);
        }
        b[i] = all ^ a[i];
    }
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= m; j++)
            if(i != j && (a[i] & b[j]) == a[i])
                return puts("impossible"), 0;
    }
    return puts("possible"), 0;
}
