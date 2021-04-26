/* Round 1B
 * https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae37b
 */

#include <bits/stdc++.h>
using namespace std;

using LD = long double;
const int MX = 21, MXB = 15;

// dp[full][full-1][full-2][small_size]
long double dp[MX][MX][MX][MX];
long double pow_10[MXB];
int action[MX][MX][MX][MX][10];

void solve(int n, int b) {
    int i = 0, j = 0, k = 0, l = 0;
    int tot = n * b;
    while(tot--) {
        int digit;
        cin >> digit;
        int res = action[i][j][k][l][digit];
        cout << res << endl;
        if(res == i + j + k + 1) {
            l++;
            if(l == b - 2) {
                k++, l = 0;
            }
        } else if(res == i + j + 1) {
            assert(k > 0);
            k--, j++;
        } else if(res == i + 1) {
            assert(j > 0);
            j--, i++;
        }
    }
}

int main() {
    int T, n, b;
    long long p;
    cin >> T >> n >> b >> p;

    pow_10[0] = 1.;
    for(int i = 1; i < b; i++) {
        pow_10[i] = pow_10[i - 1] * 10.;
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = n - i; j >= 0; j--) {
            for(int k = n - i - j; k >= 0; k--) {
                for(int l = b - 3; l >= 0; l--) {
                    // no small
                    if(i + j + k == n && l != 0) {
                        continue;
                    }
                    for(int digit = 0; digit < 10; digit++) {
                        LD cur_max = -1;
                        // put to full-1
                        if(j != 0) {
                            LD tmp = dp[i + 1][j - 1][k][l] + digit * pow_10[b - 1];
                            if(tmp > cur_max) {
                                cur_max = tmp;
                                action[i][j][k][l][digit] = i + 1;
                            }
                        }
                        // put to full-2
                        if(k != 0) {
                            LD tmp = dp[i][j + 1][k - 1][l] + digit * pow_10[b - 2];
                            if(tmp > cur_max) {
                                cur_max = tmp;
                                action[i][j][k][l][digit] = i + j + 1;
                            }
                        }
                        // put to small
                        if(i + j + k != n) {
                            LD tmp = (l == b - 3 ? dp[i][j][k + 1][0] : dp[i][j][k][l + 1]) + digit * pow_10[l];
                            if(tmp > cur_max) {
                                cur_max = tmp;
                                action[i][j][k][l][digit] = i + j + k + 1;
                            }
                        }
                        assert(cur_max > -1);
                        dp[i][j][k][l] += cur_max / 10;
                    }
                }
            }
        }
    }

    while(T--) {
        solve(n, b);
    }
    return 0;
}
