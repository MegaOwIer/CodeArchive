/* Qualification Round
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9f
 */

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for(int _ = 1; _ <= T; _++) {
        string str, ans;
        cin >> str;
        int depth = 0;
        for(char c : str) {
            int cur = c - '0';
            while(depth < cur) {
                ans.push_back('(');
                depth++;
            }
            while(depth > cur) {
                ans.push_back(')');
                depth--;
            }
            ans.push_back(c);
        }
        while(depth--) {
            ans.push_back(')');
        }
        cout << "Case #" << _ << ": " << ans << "\n";
    }
    return 0;
}
