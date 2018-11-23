#include <bits/stdc++.h>
using namespace std;

const int MX = 20005;

char s1[MX], s2[MX], ans[MX];

inline int trans(char *s)
{
    char cur[3] = {s[0], s[1], 0};
    int tmp;
    sscanf(cur, "%X", &tmp);
    return tmp;
}

int main()
{
    ifstream cin("decode.in");
    s1[1] = '2', s1[2] = '0';
    cin >> (s1 + 3) >> (s2 + 1);
    int len = strlen(s1 + 1);
    for (int i = 1, lst = 0; i <= len; i += 2)
    {
        lst = trans(s1 + i) ^ trans(s2 + i) ^ lst;
        sprintf(ans + i, "%02X", lst);
    }
    ofstream cout("decode.out");
    cout << (ans + 1) << endl;
    return 0;
}