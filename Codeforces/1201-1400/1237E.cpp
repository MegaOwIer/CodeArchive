#include<bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, x = 1;
	cin >> n;
	while(x <= n) {
		if(n == x || n == x + 1)
			return puts("1"), 0;
		x = x * 2 + 1 + (x % 2);
	}
	return puts("0"), 0;
}
