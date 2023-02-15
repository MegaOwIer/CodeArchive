#include <bits/stdc++.h>
using namespace std;

using LL = long long;

union data_t {
    unsigned mask;
    unsigned char ranks[4];
};

vector<unsigned> masks[6];

LL solve() {
    map<string, int> teams_id;
    map<int, array<int, 4>> teams_info;

    LL factor = 1;
    for(int i = 0; i <= 3; i++) {
        for(int j = 1; j <= 8; j++) {
            string str;
            cin >> str;
            if(!teams_id.count(str)) {
                teams_id[str] = teams_info.size();
            }
            factor *= ++teams_info[teams_id[str]][i];
        }
    }

    map<unsigned, LL> lst, cur;
    lst[0] = 1;

    for(const auto &[_, team] : teams_info) {
        for(const auto &[mask, val] : lst) {
            data_t S;
            S.mask = mask;

            function<void(size_t, unsigned)> dfs = 
                [&] (size_t rnk, unsigned groups) {
                    if(rnk == 4) {
                        cur[S.mask] += val;
                        return;
                    }
                    for(unsigned new_mask : masks[team[rnk]]) {
                        if(new_mask & (groups | S.ranks[rnk])) {
                            continue;
                        }

                        unsigned tmp = new_mask | groups;
                        if(abs(popcount(tmp & 0x0F) - popcount(tmp & 0xF0)) > 1) {
                            continue;
                        }

                        S.ranks[rnk] ^= new_mask;
                        dfs(rnk + 1, tmp);
                        S.ranks[rnk] ^= new_mask;
                    }
                };

            dfs(0, 0);
        }
        lst = cur;
        cur.clear();
    }

    return lst[-1] * factor;
}

int main() {
    for(unsigned i = 0; i < (1 << 8); i++) {
        int pc = popcount(i);
        if(pc <= 5) {
            masks[pc].push_back(i);
        }
    }

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for(int _ = 1; _ <= t; _++) {
        printf("Case #%d: %lld\n", _, solve());
    }
    return 0;
}
