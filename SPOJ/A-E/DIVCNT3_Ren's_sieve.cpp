#include <bits/stdc++.h>
using namespace std;

using LL = long long;
#define ENDL "\n"
const int MX = 316300;

int pr[27300], cnt, d3[MX], d[MX];
bool vis[MX];

LL GetSum(LL);

int main()
{
    d3[1] = 1;
    for(int i = 2; i < MX; i++)
    {
        if(!vis[i])
            pr[++cnt] = i, d3[i] = 4, d[i] = i;
        for(int j = 1, cur; j <= cnt && (cur = i * pr[j]) < MX; j++)
        {
            vis[cur] = true;
            if(i % pr[j] == 0)
            {
                d[cur] = d[i] * pr[j];
                if(i == d[i]) d3[cur] = d3[i] + 3;
                else d3[cur] = d3[i / d[i]] * d3[d[cur]];
                break;
            }
            else
                d3[cur] = d3[i] * 4, d[cur] = pr[j];
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

int L0[MX], L1[MX], PI[MX];
LL f0[MX], f1[MX], g0[MX], g1[MX];

void GetF(int SqrtN, int Pi, LL n)
{
    for(int i = 1; i < SqrtN; i++)
        f0[i] = f1[i] = 1;
    for(int i = Pi; i >= 1; i--)
    {
        for(int j = 1; j < SqrtN && i < L1[j]; j++)
        {
            LL tmp = n / j / pr[i];
            for(int c = 4; tmp; tmp /= pr[i], c += 3)
                if(tmp < SqrtN)
                    f1[j] += c * (f0[tmp] + 4 * max(0, PI[tmp] - max(i + 1, L0[tmp]) + 1));
                else
                    f1[j] += c * (f1[n / tmp] + 4 * max(0, Pi - max(i + 1, L1[n / tmp]) + 1));
        }
        for(int j = SqrtN - 1; j >= 1 && i < L0[j]; j--)
        {
            LL tmp = j / pr[i];
            for(int c = 4; tmp; tmp /= pr[i], c += 3)
                f0[j] += c * (f0[tmp] + 4 * max(0, PI[tmp] - max(i + 1, L0[tmp]) + 1));
        }
    }
    for(int i = 1; i < SqrtN; i++)
        f0[i] += 4 * (PI[i] - L0[i] + 1),
        f1[i] += 4 * (Pi - L1[i] + 1);
}

void GetG(int SqrtN, int Pi, LL n)
{
    for(int i = 1; i < SqrtN; i++)
        g0[i] = i, g1[i] = n / i;
    for(int i = 1; i <= Pi; i++)
    {
        for(int j = 1; j < SqrtN && i < L1[j]; j++)
        {
            LL tmp = n / j / pr[i];
            if(tmp < SqrtN)
                g1[j] -= g0[tmp] - max(0, min(i - 1, PI[tmp]) - L0[tmp] + 1);
            else
                g1[j] -= g1[n / tmp] - max(0, i - L1[n / tmp]);
        }
        for(int j = SqrtN - 1; j >= 1 && i < L0[j]; j--)
        {
            LL tmp = j / pr[i];
            g0[j] -= g0[tmp] - max(0, min(i - 1, PI[tmp]) - L0[tmp] + 1);
        }
    }
    for(int i = 1; i < SqrtN; i++)
        g0[i] -= PI[i] - L0[i] + 1, g1[i] -= Pi - L1[i] + 1;
    for(int i = 1; i < SqrtN; i++)
        g0[i] = (g0[i] - 1) * 4, g1[i] = (g1[i] - 1) * 4;
}

auto Sqr = [](LL u) -> LL {return u * u;};

LL GetSum(LL n)
{
    int SqrtN = 1;
    for(; Sqr(SqrtN) <= n; ++SqrtN);
    int Pi = upper_bound(pr + 1, pr + cnt + 1, SqrtN - 1) - pr - 1;
    L0[0] = 0;
    for(int i = 1; i < SqrtN; i++)
        for(L0[i] = L0[i - 1]; Sqr(pr[L0[i]]) <= i; L0[i]++);
    L1[SqrtN] = 0;
    for(int i = SqrtN - 1; i >= 1; i--)
    {
        LL x = n / i;
        for(L1[i] = L1[i + 1]; Sqr(pr[L1[i]]) <= x; L1[i]++);
    }
    PI[0] = 0;
    for(int i = 1; i < SqrtN; i++)
    {
        for(PI[i] = PI[i - 1] + 1; pr[PI[i]] <= i; PI[i]++);
        PI[i]--;
    }
    GetG(SqrtN, Pi, n), GetF(SqrtN, Pi, n);
    LL ans = f1[1];
    for(int i = 1; i < SqrtN; i++)
        ans += d3[i] * g1[i];
    return ans;
}
