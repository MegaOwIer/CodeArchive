#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 1000005;

int ans[MX];
string str[MX];
vector<bool> dp1[MX], dp2[MX];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        dp1[i].resize(m);
        dp2[i].resize(m);
    }

    dp1[0][0] = true;
    for(int i = 1; i < m; i++)
        if(str[0][i] == '.') dp1[0][i] = dp1[0][i - 1];
    for(int i = 1; i < n; i++)
        if(str[i][0] == '.') dp1[i][0] = dp1[i - 1][0];
    for(int i = 1; i < n; i++)
        for(int j = 1; j < m; j++)
            if(str[i][j] == '.') dp1[i][j] = (dp1[i - 1][j] || dp1[i][j - 1]);
    
    dp2[n - 1][m - 1] = true;
    for(int i = n - 2; i >= 0; i--)
        if(str[i][m - 1] == '.') dp2[i][m - 1] = dp2[i + 1][m - 1];
    for(int i = m - 2; i >= 0; i--)
        if(str[n - 1][i] == '.') dp2[n - 1][i] = dp2[n - 1][i + 1];
    for(int i = n - 2; i >= 0; i--)
        for(int j = m - 2; j >= 0; j--)
            if(str[i][j] == '.') dp2[i][j] = (dp2[i + 1][j] || dp2[i][j + 1]);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(dp1[i][j] && dp2[i][j]) ans[i + j]++;
    cout << *min_element(ans + 1, ans + n + m - 2) << "\n";
    return 0;
}
