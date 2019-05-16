#include<bits/stdc++.h>
using namespace std;

int getNum(char x) {
    x = toupper(x);
    if(x >= 'W') return 9;
    else if(x >= 'T') return 8;
    else if(x >= 'P') return 7;
    else if(x >= 'M') return 6;
    else if(x >= 'J') return 5;
    else if(x >= 'G') return 4;
    else if(x >= 'D') return 3;
    else return 2;
}

string translate(string s) {
    for(char &val : s)
        val = getNum(val) + '0';
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    while(N--) {
        string str;
        cin >> str;
        str = translate(str);
        string str2 = str;
        reverse(str.begin(), str.end());
        puts(str == str2 ? "YES" : "NO");
    }
    return 0;
}
