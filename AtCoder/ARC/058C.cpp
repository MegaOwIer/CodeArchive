#include <bits/stdc++.h>
using namespace std;

vector<int> dig {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void add_print(const string &s, int id) {
    if(id == -1) {
        putchar('0' + dig[dig[0] == 0]);
        return;
    }
    auto it = upper_bound(dig.begin(), dig.end(), s[id] - '0');
    if(it == dig.end()) {
        add_print(s, id - 1);
        putchar('0' + dig.front());
    } else {
        printf("%s%d", s.substr(0, id).c_str(), *it);
    }
}

int main() {
    ios::sync_with_stdio(false);
    string n;
    int K;
    cin >> n >> K;
    for(int i = 1; i <= K; i++) {
        int val;
        cin >> val;
        dig.erase(lower_bound(dig.begin(), dig.end(), val));
    }
    for(size_t i = 0; i < n.length(); i++) {
        auto it = lower_bound(dig.begin(), dig.end(), n[i] - '0');
        if(it == dig.end() || *it != n[i] - '0') {
            add_print(n, i);
            for(size_t j = 0; j < n.length() - i - 1; j++) putchar('0' + dig.front());
            return 0;
        }
    }
    cout << n << "\n";
    return 0;
}
