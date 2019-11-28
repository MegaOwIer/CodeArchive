#include<bits/stdc++.h>
using namespace std;

const int MX = 105;

string t[MX], del[MX];

bool check(int n, string str) {
	int length = str.length();
	for(int i = 1; i <= n; i++) {
		if(del[i].length() > length) {
			if(del[i].substr(0, length) != str) return false;
			int tmp = t[i].length() - length;
			if(del[i].substr(length) != t[i].substr(0, tmp)) return false;
		} else {
			if(del[i] != str.substr(0, del[i].length())) return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	while(true) {
		int n;
		cin >> n;
		if(n == 0) break;
		for(int i = 1; i <= n; i++) {
			string s, cur;
			cin >> s >> t[i];
			for(size_t j = 0; j < s.length(); j++)
				cur.push_back('A' + (t[i][j] - s[j] + 26) % 26);
			del[i] = cur;
		}
		string res, ans;
		for(int i = 1; i <= n; i++)
			if(del[i].length() > res.length()) res = del[i];
		while(res.length() > 0) {
			if(check(n, res)) ans = res;
			res.pop_back();
		}
		puts(ans.length() ? ans.c_str() : "Impossible");
	}
	return 0;
}
