#include<bits/stdc++.h>
using namespace std;

string num;
vector<int> dig[3];

pair<int, string> work(int index, int cnt) {
    if(dig[index].size() < cnt)
        return {INT_MAX, "-1"};
    string res = num;
    for(int i = 1, id; i <= cnt; i++) {
        id = dig[index].back();
        res.erase(res.begin() + id, res.begin() + id + 1);
        dig[index].pop_back();
    }
    if(res == "")
        return {INT_MAX, "-1"};
    reverse(res.begin(), res.end());
    while(res.back() == '0')
        res.pop_back(), ++cnt;
    if(res == "")
        res = "0", --cnt;
    reverse(res.begin(), res.end());
    return {cnt, res};
}

int main() {
    ios::sync_with_stdio(false);
    int rem = 0;
    cin >> num;
    for(size_t i = 0; i < num.length(); i++)
        dig[num[i] % 3].push_back(i);
    rem = (dig[1].size() + 2 * dig[2].size()) % 3;
    if(rem == 0)
        cout << num << endl;
    else if(rem == 1) {
        pair<int, string> ans1 = work(1, 1);
        pair<int, string> ans2 = work(2, 2);
        cout << min(ans1, ans2).second << endl;
    } else {
        pair<int, string> ans1 = work(1, 2);
        pair<int, string> ans2 = work(2, 1);
        cout << min(ans1, ans2).second << endl;
    }
    return 0;
}
