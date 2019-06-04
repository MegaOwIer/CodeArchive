#include<bits/stdc++.h>
using namespace std;

int n, a[2005], sum;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n * 2; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n * 2 + 1);
    int tmp = 0;
    for(int i = 1; i <= n; i++) tmp += a[i];
    if(tmp * 2 == sum)
        return puts("-1"), 0;
    else
        for(int i = 1; i <= n * 2; i++)
            cout << a[i] << ' ';
    return 0;
}
