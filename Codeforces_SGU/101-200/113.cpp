#include<bits/stdc++.h>
using namespace std;

bool check(int x) {
    int cnt = 0;
    for(int i = 2; i * i <= x; i++)
        while(x % i == 0) x /= i, ++cnt;
    if(x > 1) ++cnt;
    return cnt == 2;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int x;
        cin >> x;
        puts(check(x) ? "Yes" : "No");
    }
    return 0;
}
