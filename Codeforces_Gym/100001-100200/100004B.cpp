#include<bits/stdc++.h>
using namespace std;

using rule = pair<string, string>;

vector<rule> mp = {{"aa", ""}, {"bb", ""}, {"cc", ""}, 
                   {"ababab", "ba"}, {"bababa", "ab"}, 
                   {"bcbcbc", "cb"}, {"cbcbcb", "bc"}, 
                   {"cacaca", "ac"}, {"acacac", "ca"}};

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        while(true) {
            int flag = false;
            for(const rule &cur : mp) {
                int l = cur.first.length();
                for(size_t i = 0; i + l <= str.length(); i++)
                    if(str.substr(i, l) == cur.first) {
                        str = str.substr(0, i) + cur.second + str.substr(i + l);
                        flag = true;
                    }
            }
            if(!flag) break;
        }
        puts(str == "" ? "closed" : "open");
    }
    return 0;
}
