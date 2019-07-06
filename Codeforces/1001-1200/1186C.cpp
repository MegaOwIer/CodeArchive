#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;

char s[MX];
int S[MX], T, ans;

int main() {
    ios::sync_with_stdio(false);
    string t;
    cin >> (s + 1) >> t;
    int ls = strlen(s + 1), lt = t.length();
    for(int i = 1; i <= ls; i++)
        S[i] = S[i - 1] + s[i] - 48;
    for(char c : t)
        T ^= c - 48;
    for(int l = 1, r = lt; r <= ls; l++, r++)
        ans += T == ((S[r] - S[l - 1]) & 1);
    cout << ans << endl;
    return 0;
}
