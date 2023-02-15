#include <bits/stdc++.h>
using namespace std;

using LL = long long;
using LD = long double;

const LD eps = 1e-7;

struct Point {
    int x, y;

    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    Point operator- (Point u) { return {x - u.x, y - u.y}; }

    LL operator* (Point u) { return (LL)x * u.y - (LL)y * u.x; }
    LL operator^ (Point u) { return (LL)x * u.x + (LL)y * u.y; }
};

int main()
{
    int T;
    scanf("%d", &T);
    while(T--) {
        Point d[3], X;

        for(int i = 0; i < 3; i++) {
            int x, y;
            scanf("%d%d", &x, &y);
            d[i] = {x, y};
        }
        scanf("%d%d", &X.x, &X.y);
        
        bool success = false;
        for(int i = 0; i < 3; i++) {
            int j = (i + 1) % 3, k = (i + 2) % 3;
            if(((d[i] - X) * (d[j] - X)) == 0 && ((d[i] - X) ^ (d[j] - X)) <= 0) {
                success = true;
                LD rr = 0;
                if(d[i].x == d[j].x) {
                    rr = (LD)(X.y - d[i].y) / (d[j].y - d[i].y);
                } else {
                    rr = (LD)(X.x - d[i].x) / (d[j].x - d[i].x);
                }

                if(fabsl(rr - 0.5) < eps) {
                    printf("%d %d\n", d[k].x, d[k].y);
                } else if(rr < 0.5) {
                    rr = 0.5 / (1 - rr);
                    LD x = d[j].x + (d[k].x - d[j].x) * rr;
                    LD y = d[j].y + (d[k].y - d[j].y) * rr;
                    printf("%.8Lf %.8Lf\n", x, y);
                } else {
                    rr = 0.5 / rr;
                    LD x = d[i].x + (d[k].x - d[i].x) * rr;
                    LD y = d[i].y + (d[k].y - d[i].y) * rr;
                    printf("%.8Lf %.8Lf\n", x, y);
                }
                break;
            }
        }
        
        if(!success) {
            puts("-1");
        }
    }
    return 0;
}
