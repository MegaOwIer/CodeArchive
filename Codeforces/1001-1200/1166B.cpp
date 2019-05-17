#include<bits/stdc++.h>
using namespace std;

const char v[] = "aeiou";

int main() {
    ios::sync_with_stdio(false);
    int n, a = -1, b = -1;
    cin >> n;
    for(int i = 5; i <= n; i++)
        if(n % i == 0) {
            a = i, b = n / i;
            break;
        }
    if(!(a >= 5 && b >= 5))
        return puts("-1"), 0;
    for(int i = 0; i < a; i++)
        for(int j = 0; j < b; j++)
            putchar(v[(i + j) % 5]);
    return 0;
}
