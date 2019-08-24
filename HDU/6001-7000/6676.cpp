#include<bits/stdc++.h>
using namespace std;

const int MX = (1 << 21) + 1;

int cnt[MX];
char s[MX];

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        memset(cnt + 1, 0, sizeof(int[n]));
        int ans = (n + 1) & 1;
        for(int i = 1; i <= n; i++) if(s[i] == '?') {
            int j = i;
            while(j <= n && s[j] == '?') j++;
            cnt[j - i]++;
            i = j - 1;
        }
        for(int i = n, it = 23; i; i--) while(cnt[i]--) {
            while((1 << it) > i + 1) it--;
            if(it == 0) break;
            ans |= 1 << it;
            cnt[i - (1 << it)]++, it--;
        }
        printf("%d\n", ans);
    }
    return 0;
}
