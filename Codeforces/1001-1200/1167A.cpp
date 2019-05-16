#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        string str;
        int N;
        cin >> N >> str;
        int index = 0;
        while(index < str.length() && str[index++] != '8');
        cout << (str.length() - index >= 10 ? "YES" : "NO") << ENDL;
    }
    return 0;
}
