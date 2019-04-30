#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y, b, r;
    cin >> y >> b >> r;
    r -= 2;
    b -= 1;
    int mx = min({y, b, r});
    cout << 3 * mx + 3;
    return 0;
}
