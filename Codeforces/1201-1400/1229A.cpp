#include<bits/stdc++.h>
using namespace std;

using LL = long long;

const int MX = 7000;

long long a[MX];
int n, b[MX];
bool tag[MX];
bitset<MX> G[MX], S;

int check() {
    for(int i = 0; i < n; i++) if(!tag[i]) {
        if((G[i] & S) == S) return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i != j) {
            if((a[i] ^ a[j]) & a[i]) G[i].set(j);
        }
        G[i].set(i);
    }
    for(int i = 0; i < n; i++) S.set(i);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
        ans += b[i];
    }
    int res = n;
    while(res) {
        int index = check();
        if(index == -1) break;
        S.set(index, false);
        ans -= b[index];
        tag[index] = true;
        res--;
    }
    cout << ans << "\n";
    return 0;
}
