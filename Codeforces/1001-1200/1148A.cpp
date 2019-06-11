#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    long long a, b, c;
    cin >> a >> b >> c;
    if(a == b)
        cout << c * 2 + a + a << "\n";
    else
        cout << c * 2 + min(a, b) * 2 + 1 << "\n";
    return 0;
}
