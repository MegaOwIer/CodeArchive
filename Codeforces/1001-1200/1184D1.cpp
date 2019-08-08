#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int n, k, m, t, pos, siz;
    cin >> n >> k >> m >> t;
    pos = k, siz = n;
    while(t--) {
        int op, l;
        cin >> op >> l;
        if(op == 1) {
            ++siz;
            if(l <= pos) ++pos;
        } else {
            if(l >= pos) siz = l;
            else siz -= l, pos -= l;
        }
        printf("%d %d\n", siz, pos);
    }
    return 0;
}
