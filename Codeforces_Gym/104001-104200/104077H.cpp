/**
 * @date 2023-01-14
 * @author MegaOwIer (megaowier@gmail.com)
 * @brief Simulation with VERY complex classification discussion
 */

#include <bits/stdc++.h>
using namespace std;

const int MX = 65536;

void solve() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    map<int, int> cnt;
    for(int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        cnt[val]++;
    }

    // statistics
    vector<int> odds, evens, gt1;
    for(auto [key, value] : cnt) {
        ((value & 1) ? odds : evens).push_back(key);
        if(value > 1) {
            gt1.push_back(key);
        }
    }

    string ans(n, '0'), op_array;
    vector<int> op_num;

    function<void(char, int)> update_answer = [&] (char c, int val) {
        op_array.push_back(c);
        op_num.push_back(val);
    };

    function<int()> pop_answer = [&] {
        int ret = op_num.back();
        op_array.pop_back();
        op_num.pop_back();
        return ret;
    };

    if(y + z <= cnt.size()) {       // or + xor <= #
        for(auto &[key, val] : cnt) {
            while(x > 0 && val > 1) {
                update_answer('&', key);
                val--, x--;
            }
        }
        for(auto &[key, val] : cnt) {
            if(x > 0) {
                update_answer('&', key);
                x--;
            } else if(y > 0) {
                update_answer('|', key);
                ans[key] = '1';
                y--;
            } else {
                update_answer('^', key);
                ans[key] = '1';
                z--;
            }
        }
    } else if(y >= cnt.size()) {    // or >= #
        for(auto &[key, val] : cnt) {
            while(x > 0 && val > 1) {
                update_answer('&', key);
                val--, x--;
            }
            while(z > 0 && val > 1) {
                update_answer('^', key);
                val--, z--;
            }
        }
        assert(x == 0 && z == 0);
        for(auto &[key, val] : cnt) {
            while(val--) {
                update_answer('|', key);
                ans[key] = '1';
            }
        }
    } else if(x == 0) {             // only or + xor
        while(y > 0 && !evens.empty()) {
            int key = evens.back(), &value = cnt[key];
            while(value > 1) {
                update_answer('^', key);
                value--;
            }
            update_answer('|', key);
            y--, value--;
            ans[key] = '1';
            evens.pop_back();
        }
        for(int i = 0; i < y; i++) {
            update_answer('|', odds[i]);
            ans[odds[i]] = '1';
            cnt[odds[i]]--;
        }

        for(auto [key, value] : cnt) {
            while(value--) {
                update_answer('^', key);
                ans[key] ^= 1;
            }
        }
    } else if(y == 0) {             // only and + xor
        z -= cnt.size();
        if(gt1.size() == 1) {
            if(z % 2 == 1) {
                update_answer('&', cnt.begin()->first);
                cnt.begin()->second--;
                x--;
            }

            int special = gt1.front();
            while(x > 0) {
                update_answer('&', special);
                x--, cnt[special]--;
            }

            for(auto &[key, value] : cnt) {
                while(value--) {
                    update_answer('^', key);
                    ans[key] ^= 1;
                }
            }
        } else if(x == 1) {
            bool flag = false;
            int special = gt1.front();
            for(int key : gt1) {
                if(cnt[key] % 2 == 0) {
                    special = key;
                    flag = true;
                    break;
                }
            }

            if(flag) {              // xor sum != 0
                cnt[special]--;
                for(int key : gt1) {
                    int &value = cnt[key];
                    while(value > 1) {
                        update_answer('^', key);
                        value--;
                    }
                }
                update_answer('&', special);
                for(auto [key, _] : cnt) {
                    update_answer('^', key);
                    ans[key] = '1';
                }
            } else {
                update_answer('&', cnt.begin()->first);
                cnt.begin()->second--;
                for(auto [key, value] : cnt) {
                    while(value--) {
                        update_answer('^', key);
                        ans[key] ^= 1;
                    }
                }
            }
        } else {
            cnt[gt1.front()]--;
            cnt[gt1.back()]--;
            x -= 2;

            for(int key : gt1) {
                int &value = cnt[key];
                while(value > 1) {
                    if(z > 0) {
                        update_answer('^', key);
                        z--;
                    } else {
                        update_answer('&', key);
                        x--;
                    }
                    value--;
                }
            }

            update_answer('&', gt1.front());
            update_answer('&', gt1.back());
            for(auto [key, _] : cnt) {
                update_answer('^', key);
                ans[key] = '1';
            }
        }
    } else {                        // or + xor > # && or < #
        z -= cnt.size() - y;
        if(y >= evens.size()) {     // or >= #evens
            sort(odds.begin(), odds.end(), [&] (int u, int v) {
                return cnt[u] > cnt[v];
            });
            
            for(int key : evens) {
                int &value = cnt[key];
                while(z > 0 && value > 1) {
                    update_answer('^', key);
                    z--, value--;
                }
            }

            y -= evens.size();
            for(int i = 0; i < y; i++) {
                int key = odds[i], &value = cnt[key];
                while(z > 0 && value > 1) {
                    update_answer('^', key);
                    z--, value--;
                }
            }

            if(z != 0) {                        // xor left
                if(z % 2 == 1) {
                    z++, cnt[pop_answer()]++;
                }
                for(int i = y; i < odds.size(); i++) {
                    int key = odds[i], &value = cnt[key];
                    while(value > 1 && z > 0) {
                        update_answer('^', key);
                        value--, z--;
                    }
                }
            }
            assert(z == 0);

            for(auto &[key, value] : cnt) {
                while(x > 0 && value > 1) {
                    update_answer('&', key);
                    x--, value--;
                }
            }
            assert(x == 0);

            for(int key : evens) {
                update_answer('|', key);
                ans[key] = '1';
            }
            for(int i = 0; i < odds.size(); i++) {
                update_answer(i < y ? '|' : '^', odds[i]);
                ans[odds[i]] = '1';
            }
        } else {                    // not too bad
            sort(evens.begin(), evens.end(), [&] (int u, int v) {
                return cnt[u] < cnt[v];
            });

            if(z % 2 == 1) {
                int key = evens.back();
                update_answer('^', key);
                cnt[key]--;
                z--;
            }

            for(int key : odds) {
                int &value = cnt[key];
                while(z > 0 && value > 1) {
                    update_answer('^', key);
                    z--, value--;
                }
            }

            y = evens.size() - y;
            for(int i = 0; i < evens.size(); i++) {
                int key = evens[i], &value = cnt[key];
                while(z > 0 && value > 1 + (i < y)) {
                    update_answer('^', key);
                    z--, value--;
                }
            }

            for(int i = 0; i < y; i++) {
                int key = evens[i], &value = cnt[key];
                while(z > 0 && value > 1) {
                    assert(value == 2);
                    update_answer('^', key);
                    z--, value--;
                }
            }

            for(auto &[key, value] : cnt) {
                while(x > 0 && value > 1) {
                    update_answer('&', key);
                    value--, x--;
                }
            }
            assert(x == 0);

            for(int key : odds) {
                update_answer('^', key);
                ans[key] = '1';
            }
            for(int i = 0; i < evens.size(); i++) {
                update_answer(i < y ? '^' : '|', evens[i]);
                ans[evens[i]] = '1';
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << "\n" << op_array << "\n";
    for(int val : op_num) {
        cout << val << ' ';
    }
    cout << "\n";
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
