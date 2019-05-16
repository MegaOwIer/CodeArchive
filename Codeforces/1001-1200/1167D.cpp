#include<bits/stdc++.h>
using namespace std;

int N;
string str, ans;
stack<int> S;

inline void push(int u) {
    S.push(u);
    ans.push_back(u + 48);
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> str;
    for(char i : str) {
        if(i == '(') {
            if(S.empty()) push(0);
            else push(S.top() ^ 1);
        } else {
            ans.push_back(S.top() + 48);
            S.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
