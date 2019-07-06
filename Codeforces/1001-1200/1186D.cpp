#include<bits/stdc++.h>
using namespace std;

const int MX = 100005;
const double eps = 1e-6;

int a[MX];
double s[MX];
bool flag[MX];

int main() {
    ios::sync_with_stdio(false);
    int n;
    long long sum = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        a[i] = floor(s[i]);
        flag[i] = fabs(a[i] - s[i]) < eps;
        sum += a[i];
    }
    for(int i = 1; i <= n && sum < 0; i++) {
        if(flag[i]) continue;
        a[i]++, sum++;
    }
    assert(sum == 0);
    for(int i = 1; i <= n; i++)
        cout << a[i] << "\n";
    return 0;
}
