#include <bits/stdc++.h>
using namespace std;

const int MX = 105;
#define endl '\n'

int val[5], id[] = {0, 1, 2, 3}, cur[5], tmp[5], x[MX], y[MX], z[MX];
bool vis[MX][MX];

int main()
{
    ios::sync_with_stdio(false);
    cin >> val[1] >> val[2] >> val[3];
    for (int i = 1; i <= 3; i++)
        id[i] = i;
    sort(id + 1, id + 4, [](int a, int b) {return val[a] < val[b];});
    if (val[id[1]] * val[id[2]] < val[id[3]])
        return puts("-1"), 0;
    int N = val[id[3]];
    for (int i = 1; i <= val[id[1]]; i++)
        x[i] = y[i] = i, z[i] = 0, vis[i][i] = 1;
    for (int i = val[id[1]] + 1; i <= val[id[2]]; i++)
        x[i] = i, y[i] = 1, z[i] = 0, vis[i][1] = 1;
    int cnt = val[id[2]];
    for (int i = 1; i <= val[id[2]] && cnt <= N; i++)
        for (int j = 1; j <= val[id[1]] && cnt <= N; j++)
            if (!vis[i][j])
                ++cnt, x[cnt] = i, y[cnt] = j, z[cnt] = 0, vis[i][j] = 1;
    cout << N << endl;
    if (id[3] == 1)
    {
        if (id[2] == 3)
            swap(x, y);
    }
    else if (id[3] == 2)
    {
        swap(y, z);
        if (id[2] == 3)
            swap(x, z);
    }
    else
    {
        swap(x, z);
        if (id[2] == 1)
            swap(y, z);
    }
    for (int i = 1; i <= N; i++)
        cout << x[i] << ' ' << y[i] << ' ' << z[i] << endl;
    return 0;
}