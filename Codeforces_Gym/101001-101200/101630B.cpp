#include <bits/stdc++.h>
using namespace std;

int a, b, c, m, n;

inline bool check(int a, int b, int c)
{
    int M, N;
    M = 2 * (a + c), N = b + c + c;
    if (M > N)
        swap(M, N);
    if (N <= n && M <= m)
        return true;
    M = a + b + c, N = a + a + b + c;
    if (M > N)
        swap(M, N);
    if (N <= n && M <= m)
        return true;
    M = a + b, N = a + b + c + c + c;
    if (M > N)
        swap(M, N);
    if (N <= n && M <= m)
        return true;
    return false;
}

int main()
{
    cin >> a >> b >> c >> m >> n;
    if (m > n)
        swap(m, n);
    if (check(a, b, c) || check(a, c, b) || check(b, a, c) || check(b, c, a) || check(c, a, b) || check(c, b, a))
        puts("Yes");
    else
        puts("No");
    return 0;
}