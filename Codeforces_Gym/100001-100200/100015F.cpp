#include<bits/stdc++.h>
using namespace std;

const int MS = 1 << 18;

#define f(a, b, c) (1 << a) | (1 << b) | (1 << c)
const int tri[] = {
	f(0, 1, 2), f(3, 4, 5), f(6, 7, 8), 
	f(9, 10, 11), f(12, 13, 14), f(15, 16, 17), 
	f(2, 4, 6), f(5, 10, 12), f(8, 13, 15)
};
#undef f

int dp[MS];

int main() {
	for(int i = MS - 2; i >= 0; i--) {
		int &cur = dp[i];
		cur = -1000000000;
		for(int j = 0; j < 18; j++) if((~i >> j) & 1) {
			int delta = 0, nS = i | (1 << j);
			for(int num : tri)
				if(((num >> j) & 1) && (nS & num) == num) ++delta;
			if(!delta) cur = max(cur, -dp[i | (1 << j)]);
			else cur = max(cur, delta + dp[i | (1 << j)]);
		}
	}
	ios::sync_with_stdio(false);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		int res = 0;
		for(int i = 1; i <= n; i++) {
			int val;
			cin >> val;
			res ^= 1 << (val - 1);
		} 
		if(dp[res] == 0) puts("Draw");
		else if(dp[res] > 0) puts("Andy wins");
		else puts("Ralph wins");
	}
	return 0;
}
