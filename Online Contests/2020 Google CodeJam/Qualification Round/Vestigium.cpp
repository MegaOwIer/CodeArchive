/* Qualification Round
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/000000000020993c
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 105;

int a[MX][MX];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        int n, m, trace = 0;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
            trace += a[i][i];
        }
        int ansr = 0, ansc = 0;
        for(int i = 1; i <= n; i++) {
            unordered_set<int> S;
            for(int j = 1; j <= n; j++) {
                S.insert(a[i][j]);
            }
            ansr += (S.size() != n);
        }
        for(int j = 1; j <= n; j++) {
            unordered_set<int> S;
            for(int i = 1; i <= n; i++) {
                S.insert(a[i][j]);
            }
            ansc += (S.size() != n);
        }
        cout << "Case #" << _ << ": " << trace << ' ' << ansr << ' ' << ansc << "\n";
    }
    return 0;
}
