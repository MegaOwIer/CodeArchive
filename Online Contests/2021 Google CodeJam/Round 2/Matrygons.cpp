/* Round 2
 * https://codingcompetitions.withgoogle.com/codejam/round/0000000000435915/00000000007dbf06
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000000;

int dp1[MX + 5], dp2[MX + 5];

void update(int &u, int v) { if(u < v) u = v; }

int main() {
    dp1[0] = 0;
    for(int i = 0; i <= MX / 2 - 1; i++) {
        update(dp2[(i + 1) * 2], dp2[i] + 1);
        for(int j = 3, tmp; (tmp = (i + 1) * j) <= MX; j++) {
            update(dp1[tmp], dp2[i] + 1);
            update(dp2[tmp], dp2[i] + 1);
        }
    }

    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int n;
        cin >> n;
        printf("Case #%d: %d\n", _, dp1[n]);
    }
    return 0;
}
