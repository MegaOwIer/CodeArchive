#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;

    vector<int> arr;
    while(n--) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    if(arr.size() == 1 || arr[0] == 1) {
        cout << arr[0] << "\n";
    } else if(arr[1] / 2 >= arr[0]) {
        cout << arr[0] << "\n";
    } else {
        cout << arr[0] / 2 << "\n";
    }

    return 0;
}