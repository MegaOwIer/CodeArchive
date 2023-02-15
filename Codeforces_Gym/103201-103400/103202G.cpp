#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    cout << accumulate(arr.begin(), arr.begin() + k, 0ll) << "\n";
    return 0;
}
