#include <bits/stdc++.h>
using namespace std;

struct BigInt {
    static const int MOD = 1000000000;
    static const int N_BIT = 9;
    vector<int> nums;

    BigInt(const char *s, int n) {
        int val = 0, base = 1;
        for(int i = n - 1; i >= 0; i--) {
            val += (s[i] - '0') * base;
            base *= 10;
            if(base == MOD) {
                nums.push_back(val);
                val = 0;
                base = 1;
            }
        }
        if(nums.empty() || val != 0) {
            nums.push_back(val);
        }
    }

    BigInt &operator= (const BigInt &&u) {
        nums = move(u.nums);
        return *this;
    }

    BigInt &operator+= (const BigInt &u) {
        nums.resize(max(nums.size(), u.nums.size()));
        int carry = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            nums[i] += carry + (i < u.nums.size() ? u.nums[i] : 0);
            if(nums[i] >= MOD) {
                nums[i] -= MOD;
                carry = 1;
            } else {
                carry = 0;
            }
        }
        if(carry) {
            nums.push_back(carry);
        }
        return *this;
    }

    bool operator< (const BigInt &u) {
        if(nums.size() != u.nums.size()) {
            return nums.size() < u.nums.size();
        }
        for(size_t i = nums.size() - 1; i < nums.size(); i--) {
            if(nums[i] != u.nums[i]) {
                return nums[i] < u.nums[i];
            }
        }
        return false;
    }
};

ostream& operator<< (ostream &os, const BigInt &u) {
    ios states(nullptr);
    states.copyfmt(os);

    os << u.nums.back();
    for(int i = (int)u.nums.size() - 2; i >= 0; i--) {
        os << setw(BigInt::N_BIT) << setfill('0') << u.nums[i];
    }

    os.copyfmt(states);
    return os;
}

void solve() {
    int n, k;
    string str;
    cin >> n >> k >> str;

    vector<int> lths(k + 1);
    BigInt ans(str.c_str(), n);

    function<void(int)> dfs = [&] (int idx) {
        if(idx > k) {
            partial_sum(lths.begin(), lths.end(), lths.begin());

            int base = accumulate(lths.begin(), lths.end(), 0);
            if((n - base) % (k + 1) == 0) {
                base = (n - base) / (k + 1);
                if(base + *min_element(lths.begin(), lths.end()) > 0) {
                    BigInt res(nullptr, 0);
                    int l = 0;
                    for(int cur : lths) {
                        res += BigInt(str.c_str() + l, base + cur);
                        l += base + cur;
                    }
                    if(res < ans) {
                        ans = move(res);
                    }
                }
            }

            adjacent_difference(lths.begin(), lths.end(), lths.begin());
            return;
        }
        
        for(int i = -1; i <= 1; i++) {
            lths[idx] = i;
            dfs(idx + 1);
        }
    };

    dfs(1);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
