#include<bits/stdc++.h>
using namespace std;

vector<int> work(int x, int r) {
    vector<int> res;
    for(int i = 2; i * i <= x; i++) if(x % i == 0) {
        res.push_back(i);
        while(x % i == 0) x /= i;
    }
    if(x > 1) res.push_back(x);
    sort(res.begin(), res.end(), greater<int>());
    // while(res.back() <= r) res.pop_back();
    return res;
}

int vis[31999];
bool check(int x, vector<int> &prime) {
    static int cnt = 0;
    ++cnt;
    for(size_t i = 0; i < prime.size(); i++) {
        int cur = x * x % prime[i];
        if(cur > 31999) continue;
        if(vis[cur] == cnt) return false;
        vis[cur] = cnt;
    }
    cout << "1 " << x << endl;
    int res;
    cin >> res;
    for(int i : prime) if(x * x % i == res) {
        cout << "2 " << i << endl;
        string result;
        cin >> result;
        assert(result == "Yes");
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        int rem;
        cout << "1 31624" << endl;
        cin >> rem;
        vector<int> prime = work(31624 * 31624 - rem, rem);
        for(int i = 2; !check(i, prime); i++);
    }
    return 0;
}
