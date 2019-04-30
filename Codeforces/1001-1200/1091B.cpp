#include<bits/stdc++.h>
using namespace std;

const int MX = 1005;

struct Point
{
    int x, y;
    bool operator < (const Point& a) const {return x == a.x ? y < a.y : x < a.x;}
}A[MX], B[MX];

istream& operator >> (istream& os, Point& P)
{
    os >> P.x >> P.y;
    return os;
}

int main()
{
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];
    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1), reverse(B + 1, B + N + 1);
    int xx = A[1].x + B[1].x, yy = A[1].y + B[1].y;
    cout << xx << " " << yy << endl;
    return 0;
}
