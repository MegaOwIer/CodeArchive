#include <bits/stdc++.h>
using namespace std;

const int MX = 1005;

int N, cnt[MX], extra, num;
vector<int> ans;

int main()
{
    ios::sync_with_stdio(false);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int u;
        cin >> u;
        if (u > 0)
            cnt[u]++;
        else if (u == 0)
            extra++, num++;
        else
        {
            u = -u;
            if (cnt[u])
                cnt[u]--;
            else if (extra)
                extra--, ans.push_back(u);
            else
                return puts("No");
        }
    }
    cout << "Yes" << endl;
    for (int i : ans)
        cout << i << ' ';
    for (int i = ans.size() + 1; i <= num; i++)
        cout << 1 << ' ';
    return 0;
}