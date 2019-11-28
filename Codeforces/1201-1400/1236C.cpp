#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		for(int cur = i, j = 1; j <= n / 2; j++, cur += n)
			cout << cur << ' ';
		for(int cur = n * n + 1 - i, j = 1; j <= n - n / 2; j++, cur -= n)
			cout << cur << ' ';
		cout << "\n";
	}
	return 0;
}
