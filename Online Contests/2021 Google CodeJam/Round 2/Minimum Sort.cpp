/* Round 2
 * https://codingcompetitions.withgoogle.com/codejam/round/0000000000435915/00000000007dc51c
 */

#include <bits/stdc++.h>
using namespace std;

void work(int n) {
    for(int i = 1; i < n; i++) {
        printf("M %d %d\n", i, n);
        fflush(stdout);
        int pos;
        scanf("%d", &pos);
        if(pos != i) {
            printf("S %d %d\n", i, pos);
            fflush(stdout);
            scanf("%*d");
        }
    }
    cout << 'D' << endl;
    scanf("%*d");
}

int main() {
    int T, n;
    scanf("%d%d", &T, &n);
    while(T--) {
        work(n);
    }
    return 0;
}
