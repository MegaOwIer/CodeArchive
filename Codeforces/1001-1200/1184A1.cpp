#include<bits/stdc++.h>
using namespace std;

using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    LL r;
    cin >> r;
    --r;
    if(r <= 2 || r % 2 == 1) puts("NO");
    else printf("1 %lld\n", (r - 2) / 2);
    return 0;
}