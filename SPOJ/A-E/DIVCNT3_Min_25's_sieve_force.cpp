#include <bits/stdc++.h>
using namespace std;

using LL = long long;
#define ENDL "\n"
const int MX = 316300;

int pr[27300], cnt;
bool vis[MX];

LL GetSum(LL);

int main()
{
    for(int i = 2; i < MX; i++)
    {
        if(!vis[i])
            pr[++cnt] = i;
        for(int j = 1, cur; j <= cnt && (cur = i * pr[j]) < MX; j++)
        {
            vis[cur] = true;
            if(i % pr[j] == 0)
                break;
        }
    }
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        LL n;
        cin >> n;
        cout << GetSum(n) << ENDL;
    }
    return 0;
}

LL f0[MX], f1[MX];

auto Sqr = [](LL u) -> LL {return u * u;};

void GetF(LL n, int PI, int SqrtN, vector<LL>& val)
{
    f0[0] = 0;
    for(int i = 1; i < SqrtN; i++)
        f0[i] = i, f1[i] = n / i;
    for(int i = 1; i <= PI; i++)
        for(LL j : val)
            if(j < Sqr(pr[i]))
                break;
            else
            {
                if(j < SqrtN)
                    f0[j] -= f0[j / pr[i]] - i;
                else
                {
                    LL tmp = j / pr[i];
                    if(tmp < SqrtN)
                        f1[n / j] -= f0[tmp] - i;
                    else
                        f1[n / j] -= f1[n / tmp] - i;
                }
            }
    for(int i = 1; i < SqrtN; i++)
        f0[i] = (f0[i] - 1) * 4, f1[i] = (f1[i] - 1) * 4;
}

LL G(LL n, int m, const LL N, const int PI, const int SqrtN)
{
    LL ans = max((n < SqrtN ? f0[n] : f1[N / n]) - 4 * m, 0LL);
    for(int i = m + 1; Sqr(pr[i]) <= n; i++)
    {
        int c = 4;
        LL tmp = n / pr[i];
        while(tmp)
        {
            ans += c * (1 + G(tmp, i, N, PI, SqrtN));
            if(c == 4)
                ans -= 4;
            c += 3, tmp /= pr[i];
        }
    }
    return ans;
}

LL GetSum(LL n)
{
    int SqrtN = 1;
    for(; Sqr(SqrtN) <= n; SqrtN++);
    int cnt = upper_bound(pr + 1, pr + ::cnt + 1, SqrtN - 1) - pr - 1;
    vector<LL> val;
    for(int i = 1; i < SqrtN; i++)
        val.push_back(i), val.push_back(n / i);
    sort(val.begin(), val.end(), greater<LL>());
    val.erase(unique(val.begin(), val.end()), val.end());
    GetF(n, cnt, SqrtN, val);
    return G(n, 0, n, cnt, SqrtN) + 1;
}
