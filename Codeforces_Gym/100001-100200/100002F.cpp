#include <bits/stdc++.h>
using namespace std;

using ULL = unsigned long long;
const int MX = 105, P = 29;

ULL val[MX][MX];
char s[MX];
string dp[MX][MX];

inline void update(string &o, string p)
{
    if (o.length() > p.length())
        o = p;
}

bool check(int L, int R, int step)
{
    for (int l = L + step; l <= R; l += step)
        if (val[l][l + step - 1] != val[l - step][l - 1])
            return false;
    return true;
}

void initial(int L, int R)
{
    int len = R - L + 1;
    string res(s + L, s + R + 1);
    for (int i = 1; i < len; i++)
        if (len % i == 0 && check(L, R, i))
        {
            string cur = to_string(len / i) + "(" + dp[L][L + i - 1] + ")";
            update(res, cur);
        }
    dp[L][R] = res;
}

int main()
{
    ifstream cin("folding.in");
    ofstream cout("folding.out");
    cin >> (s + 1);
    int N = strlen(s + 1);
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j++)
            val[i][j] = val[i][j - 1] * P + ULL(s[j] - 'A' + 1);
    for (int i = 1; i <= N; i++)
        for (int j = 1; i + j - 1 <= N; j++)
        {
            initial(j, j + i - 1);
            for (int k = j; k < i + j - 1; k++)
            {
                string cur = dp[j][k] + dp[k + 1][j + i - 1];
                update(dp[j][i + j - 1], cur);
            }
        }
    cout << dp[1][N] << endl;
    return 0;
}
