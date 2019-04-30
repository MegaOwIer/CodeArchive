#include<bits/stdc++.h>
using namespace std;

const int MX = 1000005;

int N;
char s[MX];
vector<pair<int, int>> arr, res[2];

int main() {
    ios::sync_with_stdio(false);
    cout.tie(nullptr);

    cin >> N >> (s + 1);
    for(int i = 1, j = 1; i <= N; i = j) {
        while(s[i] == s[j]) j++;
        arr.push_back({i, j - 1});
    }
    for(pair<int, int> &cur : arr)
        res[static_cast<int>(s[cur.second] < s[cur.second + 1])].push_back(cur);
    reverse(res[1].begin(), res[1].end());
    for(int index : {0, 1})
        for(pair<int, int> &cur : res[index])
            for(int i = cur.first; i <= cur.second; i++)
                cout << i << ' ';
    return 0;
}
