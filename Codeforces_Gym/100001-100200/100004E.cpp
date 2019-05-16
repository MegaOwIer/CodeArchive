#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"
const int MX = 1005;

int pos[2][MX], eng[2][MX], dp[2][MX];

inline void update(int &u, int v) {if(u > v) u = v;}

int main() {
    ios::sync_with_stdio(false);
    int cas;
    cin >> cas;
    while(cas--) {
        int C, T, L;
        cin >> C >> T >> L;
        for(int i = 1; i <= T; i++) {
            cin >> pos[1][i] >> eng[1][i];
            dp[1][i] = eng[1][i] + pos[1][i];
        }
        for(int i = 2, lst = 1; i <= C; i++, lst ^= 1) {
            memset(dp[i & 1] + 1, 0x3f, sizeof(int[T]));
            for(int j = 1; j <= T; j++) {
                int &curpos = pos[i & 1][j], &cureng = eng[i & 1][j];
                cin >> curpos >> cureng;
                for(int k = 1; k <= T; k++)
                    update(dp[i & 1][j], dp[lst][k] + cureng + abs(curpos - pos[lst][k]));
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i <= T; i++)
            update(ans, dp[C & 1][i] + L - pos[C & 1][i]);
        cout << ans << ENDL;
    }
    return 0;
}
