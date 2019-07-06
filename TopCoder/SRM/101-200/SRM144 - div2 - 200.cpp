#include<bits/stdc++.h>
using namespace std;

class Time {
public:
    string whatTime(int seconds) {
        int h = seconds / 3600;
        int m = (seconds % 3600) / 60;
        int s = seconds % 60;
        return to_string(h) + ":" + to_string(m) + ":" + to_string(s);
    }
};
