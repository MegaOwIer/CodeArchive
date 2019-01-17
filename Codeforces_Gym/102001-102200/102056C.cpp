#include<bits/stdc++.h>
using namespace std;

const int MX = 31622, B = 44100, TL = 125800;

int call_cnt;
vector<int> prime, divisor;
bitset<MX> vis;
bitset<200> current, pattern;

bool check(int u)
{
    current.set();
    int begin = u, end = u + 199;
    for(int d : {4, 9, 25, 49})
        for(int i = (begin + d - 1) / d * d; i <= end; i += d)
            if(pattern[i - begin]) return false;
            else current.set(i - begin, false);
    return true;
}

bool solve(int val)
{
    ++call_cnt;
    auto tmp = current;
    int begin = val, end = val + 199;
    for(int d : divisor)
    {
        if(d > end) break;
        for(int i = (begin + d - 1) / d * d; i <= end; i += d)
            if(pattern[i - begin]) return false;
            else tmp.set(i - begin, false);
    }
    return tmp == pattern;
}

int main()
{
    for(int i = 2; i < MX; i++) if(!vis[i])
    {
        prime.push_back(i);
        for(int j = i + i; j < MX; j += i) vis[j] = 1;
    }
    for(int p : prime)
        if(p > 7) divisor.push_back(p * p);
    ios::sync_with_stdio(false);
    for(int i = 0; i < 10; i++)
    {
        string tmp;
        cin >> tmp;
        for(int j = 0; j < 20; j++)
            if(tmp[j] == '1') pattern.set(i * 20 + j);
    }
    int ans = -1, upper = 1000000000 - 199 + 1;
    for(int i = 1; i <= B && call_cnt <= TL; i++)
    {
        if(!check(i)) continue;
        for(int j = i; j < upper && call_cnt <= TL; j += B)
            if(solve(j)) upper = ans = j;
    }
    cout << ans << endl;
    return 0;
}
