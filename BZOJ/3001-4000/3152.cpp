#include <bits/stdc++.h>
using namespace std;

const int MX = 2000005;

int a[MX];

int solve(int n) {
    if(n == 1) return 0;
    priority_queue<int> heap;
    int ans = 1, res = a[1] - 1;
    for(int i = 2; i <= n; i++) {
        if(res == 0) {
            if(heap.empty() || heap.top() < 2) {
                return -1;
            } else {
                ans++;
                res += heap.top() - 1;
                heap.pop();
            }
        }
        res--;
        heap.push(a[i]);
    }
    return ans;
}

int main() {
    int _;
    scanf("%d", &_);
    while(_--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
        printf("%d\n", solve(n));
    }
    return 0;
}
