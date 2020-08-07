#include <bits/stdc++.h>
using namespace std;

const int MX = 105;
const double eps = 1e-6;

double f[MX][MX];
char s[MX];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++) {
        double tmp = 0;
        for(int j = 1; j <= n; j++) {
            scanf("%lf", &f[i][j]);
            if(i != j) tmp += f[i][j];
        }
        f[i][i] = tmp - n + 1;
    }
    for(int i = 1; i <= n; i++) f[n][i] = 1;
    f[n][n + 1] = 1;
    for(int i = 1; i <= n; i++) {
        if(fabs(f[i][i]) < eps) {
            int j = i + 1;
            while(j <= n && fabs(f[j][i]) < eps) j++;
            swap(f[i], f[j]);
        }
        double val = f[i][i];
        for(int j = i; j <= n + 1; j++) f[i][j] /= val;
        for(int j = i + 1; j <= n; j++) {
            double tmp = f[j][i];
            for(int k = i; k <= n + 1; k++) f[j][k] -= tmp * f[i][k];
        }
    }
    for(int i = n; i >= 1; i--) {
        for(int j = i - 1; j >= 1; j--) {
            f[j][n + 1] -= f[j][i] * f[i][n + 1];
        }
    }
    while(m--) {
        scanf("%s", s + 1);
        double ans = 0;
        for(int i = 1; i <= n; i++) if(s[i] == '1') ans += f[i][n + 1];
        printf("%.8lf\n", ans);
    }
    return 0;
}
