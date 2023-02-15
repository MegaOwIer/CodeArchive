#include <bits/stdc++.h>
using namespace std;

using LL = long long;

void DFT(LL *A, int n, bool rev = false) {
    if(n == 1) {
        return;
    }
    int half = n / 2;
    DFT(A, half, rev);
    DFT(A + half, half, rev);
    for(int i = 0; i < half; i++) {
        LL u = A[i], v = A[half + i];
        if(!rev) {
            A[i] = u + v;
            A[half + i] = -u + v;
        } else {
            A[i] = (u - v) / 2;
            A[half + i] = (u + v) / 2;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    LL k;
    cin >> n >> m >> k;

    k = (LL)n * n - k * 2;

    vector<LL> A(1 << m);
    for(int i = 1; i <= n; i++) {
        string answer;
        cin >> answer;
        for(char &c : answer) {
            c = (c == 'A') ? '0' : '1';
        }
        A[stoi(answer, 0, 2)]++;
    }

    DFT(A.data(), 1 << m);
    for(LL &cur : A) {
        cur = cur * cur;
    }
    DFT(A.data(), 1 << m, true);

    for(int j = 0; j < m; j++) {
        for(int i = (1 << m) - 1; i >= 0; i--) {
            if((i >> j) & 1) {
                A[i ^ (1 << j)] += A[i];
            }
        }
    }

    cout << count_if(A.begin(), A.end(), [&](LL u) { return u <= k; }) << "\n";

    return 0;
}
