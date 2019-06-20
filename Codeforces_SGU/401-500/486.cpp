#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int A = 0, B = 0;
    string sA, sB;
    cin >> sA;
    for(size_t i = 0; i < sA.length(); i++) {
        A |= 1 << (sA[i] - '0');
    }
    cin >> sB;
    for(size_t i = 0; i < sB.length(); i++) {
        B |= 1 << (sB[i] - '0');
    }
    int ans1 = 0;
    for(size_t i = 0; i < sA.length(); i++)
        if(sA[i] == sB[i]) ans1++;
    int ans2 = __builtin_popcount(A & B) - ans1;
    printf("%d %d\n", ans1, ans2);
    return 0;
}
