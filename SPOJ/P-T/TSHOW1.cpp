#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        long long n;
        cin >> n;
        int len = 1;
        n--;
        while(n >= (1 << len))
            n -= 1 << len, len++;
        for(int i = len - 1; i >= 0; i--)
            putchar((n >> i) & 1 ? '6' : '5');
        putchar('\n');
    }
    return 0;
}
