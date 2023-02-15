#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    cin.get();

    vector<int> value(m, -1);
    vector<vector<int>> in_conditions(m);
    vector<int> conditions_left(n);
    vector<string> consequence(n);

    // -1 -> conflict, 2 -> unchanged, 0/1 -> modified to 0/1
    function<int(string)> set_value = [&] (string str) {
        if(str[0] == '!') {
            str[0] = '-';
        }
        int pos = stoi(str);
        int val = pos > 0;
        pos = abs(pos);
        if(value[pos - 1] == (val ^ 1)) {
            return -1;
        }
        if(value[pos - 1] == val) {
            return 2;
        }
        return value[pos - 1] = val;
    };
    
    for(int i = 0; i < n; i++) {
        string str;
        getline(cin, str);

        stringstream ss;
        ss << str;

        vector<string> items;
        while(ss >> str) {
            items.push_back(str);
        }

        if(items.size() == 1) {
            if(set_value(items[0]) == -1) {
                puts("conflict");
                return 0;
            }
        } else {
            bool flag = false;
            for(const string &s : items) {
                if(s == "->") {
                    flag = true;
                } else if(flag) {
                    consequence[i] = s;
                } else {
                    in_conditions[stoi(s) - 1].push_back(i);
                    conditions_left[i]++;
                }
            }
        }
    }

    queue<int> que;
    for(int i = 0; i < m; i++) {
        if(value[i] == 1) {
            que.push(i);
        }
    }

    while(!que.empty()) {
        int u = que.front();
        que.pop();
        for(int x : in_conditions[u]) {
            if(--conditions_left[x] == 0) {
                int ret = set_value(consequence[x]);
                if(ret == -1) {
                    puts("conflict");
                    return 0;
                }
                if(ret == 1) {
                    que.push(stoi(consequence[x]) - 1);
                }
            }
        }
    }

    for(int v : value) {
        putchar(v == 1 ? 'T' : 'F');
    }

    return 0;
}
