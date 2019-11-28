#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int mod = 1000000007, MX = 255;

int C[MX][MX], pwk[MX * MX], pwk_1[MX * MX];

int main() {
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	for(int i = 0; i <= n; i++) C[i][0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	pwk[0] = 1;
	for(int i = 1; i <= n * n; i++) pwk[i] = (LL)pwk[i - 1] * k % mod;
	pwk_1[0] = 1;
	for(int i = 1; i <= n * n; i++) pwk_1[i] = pwk_1[i - 1] * LL(k - 1) % mod;
	int ans = 0;
	for(int i = 0; i <= n; i++)
		for(int j = 0; j <= n; j++) {
			LL tmp = ((i + j) % 2) ? mod - 1 : 1;
			ans = (ans + tmp * C[n][i] % mod * C[n][j] % mod * pwk[(n - i) * (n - j)] % mod * pwk_1[(i + j) * n - i * j]) % mod;
		}
	cout << ans << "\n";
	return 0;
}
