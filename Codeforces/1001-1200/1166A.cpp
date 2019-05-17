#include<bits/stdc++.h>
using namespace std;

int a[30], ans;

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    while(n--) {
        string name;
        cin >> name;
        a[name[0] - 'a']++;
    }
    auto get = [](int x){return x * (x - 1) / 2;};
    for(int i = 0; i < 26; i++)
        ans += get(a[i] - a[i] / 2) + get(a[i] / 2);
    cout << ans << endl;
    return 0;

}
