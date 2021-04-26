/* Qualification Round
 * https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e
 */

#include <bits/stdc++.h>
using namespace std;

char getChar() {
    string c;
    cin >> c;
    return c[0];
}

char query(int i) {
    cout << i << endl;
    return getChar();
}

void submit_answer(string s) {
    cout << s << endl;
}

int main() {
    ios::sync_with_stdio(false);
    int T, B;
    cin >> T >> B;
    while(T--) {
        string half_1, half_2;
        int comp = 0, mid = B / 2, delta = 0;
        int r_flag = -1, c_flag = -1;
        while(delta <= 4) {
            half_1.push_back(query(mid - delta));
            ++delta;
            half_2.push_back(query(mid + delta));
            if(r_flag == -1 && half_1.back() != half_2.back()) r_flag = delta - 1;
            if(c_flag == -1 && half_1.back() == half_2.back()) c_flag = delta - 1;
        }
        while(delta < mid) {
            if(r_flag == -1 || c_flag == -1) {
                if(query(mid) != (half_1[0] ^ comp)) comp ^= 1;
                query(mid);
            } else {
                bool r = query(mid - r_flag) == (half_1[r_flag] ^ comp);
                bool c = query(mid - c_flag) == (half_1[c_flag] ^ comp);
                if(!r && c) swap(half_1, half_2);
                else if(!r && !c) comp ^= 1;
                else if(r && !c) swap(half_1, half_2), comp ^= 1;
            }
            for(int i = 1; i <= 4 && delta < mid; i++) {
                half_1.push_back(query(mid - delta) ^ comp);
                ++delta;
                half_2.push_back(query(mid + delta) ^ comp);
                if(r_flag == -1 && half_1.back() != half_2.back()) r_flag = delta - 1;
                if(c_flag == -1 && half_1.back() == half_2.back()) c_flag = delta - 1;
            }
        }
        reverse(half_1.begin(), half_1.end());
        if(comp) {
            for(char &c : half_1) c ^= comp;
            for(char &c : half_2) c ^= comp;
        }
        submit_answer(half_1 + half_2);
        if(getChar() == 'N') break;
    }
    return 0;
}
