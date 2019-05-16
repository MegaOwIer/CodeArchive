#include<bits/stdc++.h>
using namespace std;

int ans[4], arr[7], prod = 4 * 8 * 16 * 15 * 42 * 23, index = 21;
pair<int, int> ask[4] = {{1, 2}, {3, 4}, {2, 5}, {4, 5}};

void work(int val, int mod) {
    int id;
    if(ans[0] % mod == 0) {
        arr[id = (ans[2] % mod == 0 ? 2 : 1)] = val;
    } else if(ans[1] % mod == 0) {
        arr[id = (ans[3] % mod == 0 ? 4 : 3)] = val;
    } else {
        arr[id = (ans[2] % mod == 0 ? 5 : 6)] = val;
    }
    index -= id, prod /= val;
}

int main() {
    for(int i = 0; i <= 3; i++) {
        cout << "? " << ask[i].first << ' ' << ask[i].second << endl;
        cin >> ans[i];
    }
    work(23, 23), work(42, 7), work(15, 5);

    if(arr[1] && arr[2]) {
        if(!arr[5]) {
            arr[5] = ans[2] / arr[2];
            index -= 5, prod /= arr[5];
        }
    } else if(arr[1]) {
        arr[2] = ans[0] / arr[1];
        index -= 2, prod /= arr[2];
    } else if(arr[2]) {
        arr[1] = ans[0] / arr[2];
        index -= 1, prod /= arr[1];
    } else {
        arr[index - 3] = prod / ans[0];
        arr[2] = ans[2] / arr[5];
        arr[1] = ans[0] / arr[2];
    }

    if(arr[3] && arr[4]) {
        if(!arr[5]) {
            arr[5] = ans[3] / arr[4];
            index -= 5, prod /= arr[5];
        }
    } else if(arr[3]) {
        arr[4] = ans[1] / arr[3];
        index -= 4, prod /= arr[4];
    } else if(arr[4]) {
        arr[3] = ans[1] / arr[4];
        index -= 3, prod /= arr[3];
    } else {
        arr[index - 7] = prod / ans[1];
        arr[4] = ans[3] / arr[5];
        arr[3] = ans[1] / arr[4];
    }

    if(!arr[5]) {
        arr[5] = ans[2] / arr[2];
        index -= 5, prod /= arr[5];
    }

    if(!arr[6]) {
        arr[6] = prod;
    }

    cout << "! ";
    for(int i = 1; i <= 6; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
