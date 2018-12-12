#include <bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 100000, MXLEN = 16;
const LL MXVAL = 1000000000000000LL;
const long double eps = 1e-5;
#define ENDL "\n"

int pr[9601], cnt;
bool vis[MX + 5];
vector<LL> ans;

int getNum(int);
bool work(LL, LL);

int main()
{
    pr[cnt = 1] = 2;
    for(int i = 3; i <= MX; i += 2)
    {
        if(!vis[i]) pr[++cnt] = i;
        for(int j = 1; j <= cnt && i * pr[j] <= MX; j++)
        {
            vis[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
    for(int a = 1; a <= MX; a++)
    {
        int b0 = getNum(a);
        for(int b = a + b0; work(a, b); b += b0);
    }
    sort(ans.begin(), ans.end());
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    for(int i = 1; i <= T; i++)
    {
        LL L, R;
        cin >> L >> R;
        cout << "Case #" << i << ": "
             << upper_bound(ans.begin(), ans.end(), R) - lower_bound(ans.begin(), ans.end(), L)
             << ENDL;
    }
    return 0;
}

int getNum(int a)
{
    int res = 1;
    for(int i = 1; pr[i] * pr[i] <= a; i++)
    {
        int cnt = 0;
        while(a % pr[i] == 0)
            a /= pr[i], cnt++;
        for(int j = (cnt + 1) / 2; j > 0; j--)
            res *= pr[i];
    }
    return res * a;
}

bool work(const LL a, const LL b)
{
    bool res = false;
    string cur_str = to_string(a) + to_string(b);
    LL nxt = b;
    while(nxt * b % a == 0)
    {
        nxt = nxt * b / a;
        cur_str += to_string(nxt);
        if(cur_str.length() > MXLEN || stoll(cur_str) > MXVAL)
            return res;
        ans.push_back(stoll(cur_str));
        res = true;
    }
    return res;
}
