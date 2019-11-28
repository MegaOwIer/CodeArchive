#include<bits/stdc++.h>
using namespace std;

using LD = long double;
const LD _2pi = acosl(-1.0l) * 2;

vector<string> oper;

bool check(long double x) {
	stack<LD> res;
	for(string cur : oper) {
		if(cur == "x") res.push(x);
		else if(cur.length() == 3) {
			LD num = res.top();
			res.pop();
			if(cur[0] == 's') res.push(sinl(num));
			else if(cur[0] == 'c') res.push(cosl(num));
			else {
				int deg = floorl(num / _2pi * 360 + 1e-6);
				if((deg % 180 + 180) % 180 == 90) return true;
				res.push(tanl(num));
			}
		} else {
			LD a = res.top(); res.pop();
			LD b = res.top(); res.pop();
			if(cur == "+") res.push(a + b);
			else if(cur == "-") res.push(b - a);
			else res.push(b * a);
		}
	}
	return fabsl(res.top()) < 1e-6;
}

int main() {
	ios::sync_with_stdio(false);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		oper.clear();
		for(int i = 1; i <= n; i++) {
			string str;
			cin >> str;
			oper.push_back(str);
		}
		bool ans = true;
		for(int i = 1; i <= 360; i++)
			ans = ans && check((LD)i / 360 * _2pi);
		puts(ans ? "Identity" : "Not an identity");
	}
	return 0;
}
