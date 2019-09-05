#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int MX = 200005;

int n, arr[MX], mn;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> s;
    if(n & 1) return puts("No"), 0;
    for(int i = 1; i <= n; i++)
        arr[i] = arr[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    puts(*min_element(arr + 1, arr + n + 1) >= -1 && arr[n] == 0 ? "Yes" : "No");
    return 0;
}
