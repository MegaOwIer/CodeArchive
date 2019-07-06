#include<bits/stdc++.h>
using namespace std;

class BinaryCode {
private:
    int ss[55], ans[55];
    string getStr(string message, int start) {
        int lth = message.length();
        for(int i = 0; i < lth; i++) ss[i + 1] = message[i] - '0';
        ans[1] = start;
        for(int i = 2; i <= lth; i++)
            ans[i] = ss[i - 1] - ans[i - 1] - ans[i - 2];
        if(ans[lth] + ans[lth - 1] != ss[lth])
            return "NONE";
        string res = "";
        for(int i = 1; i <= lth; i++) {
            if(ans[i] > 1 || ans[i] < 0) return "NONE";
            res.push_back('0' + ans[i]);
        }
        return res;
    }
public:
    vector<string> decode(string message) {
    	return {getStr(message, 0), getStr(message, 1)};
    }
};
