#include <bits/stdc++.h>
using namespace std;

const int MX = 200005;

struct oper_t {
    int type; // 0 for modify, 1 for query
    tuple<int, int, int> info; // (x, y, delta) for modify, (x, y, ctrb) for query

    oper_t(int t, tuple<int, int, int> i) : type(t), info(i) {}
};

struct Trie {
    shared_ptr<Trie> son[26];
    vector<int> labels;
    int dfn, end;
};

void Trie_insert(shared_ptr<Trie> o, const char *s, int label) {
    while(*s != '\0') {
        if(o->son[*s - 'a'] == nullptr) {
            o->son[*s - 'a'] = make_shared<Trie>();
        }
        o = o->son[*s - 'a'];
        s++;
    }
    o->labels.push_back(label);
}

pair<int, int> Trie_query(shared_ptr<Trie> o, const char *s, int k) {
    for(int i = 0; i < k; i++) {
        o = o->son[s[i] - 'a'];
        if(o == nullptr) {
            return {-1, -1};
        }
    }
    return {o->dfn, o->end};
}

int dfn_str[MX];

void dfs(shared_ptr<Trie> u) {
    static int cnt = 0;
    u->dfn = ++cnt;

    for(int id : u->labels) {
        dfn_str[id] = cnt;
    }

    for(shared_ptr<Trie> cur : u->son) {
        if(cur != nullptr) {
            dfs(cur);
        }
    }
    u->end = cnt;
}

void solve(oper_t *begin, oper_t *end, vector<int> &ans) {
    size_t n = (end - begin);
    if(n == 1) {
        return;
    }
    oper_t *mid = begin + n / 2;

    vector<oper_t *> modify;
    for(oper_t *i = begin; i != mid; i++) {
        if(i->type == 0) {
            modify.push_back(i);
        }
    }
    sort(modify.begin(), modify.end(), [&] (oper_t * u, oper_t * v) {
        return get<0>(u->info) < get<0>(v->info);
    });

    vector<oper_t *> query;
    for(oper_t *i = mid; i < end; i++) {
        if(i->type == 1) {
            query.push_back(i);
        }
    }
    sort(query.begin(), query.end(), [&] (oper_t * u, oper_t * v) {
        return get<0>(u->info) < get<0>(v->info);
    });

    static int bit[MX + 10];
    auto bit_insert = [&] (int u, int val) {
        while(u <= MX) {
            bit[u] += val;
            u += u & -u;
        }
    };
    auto bit_query = [&] (int u) {
        int res = 0;
        while(u) {
            res += bit[u];
            u -= u & -u;
        }
        return res;
    };

    size_t it = 0;
    for(oper_t *cur_query : query) {
        auto [cur_x, cur_y, ctrb] = cur_query->info;

        while(it != modify.size()) {
            auto [xx, yy, delta] = modify[it]->info;
            if(xx > cur_x) {
                break;
            }
            bit_insert(yy, delta);
            it++;
        }

        if(ctrb > 0) {
            ans[ctrb] += bit_query(cur_y);
        } else {
            ans[-ctrb] -= bit_query(cur_y);
        }
    }

    for(size_t i = 0; i < it; i++) {
        auto [xx, yy, delta] = modify[i]->info;
        bit_insert(yy, -delta);
    }

    solve(begin, mid, ans);
    solve(mid, end, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    shared_ptr<Trie> o = make_shared<Trie>();
    for(int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        Trie_insert(o, str.c_str(), i);
    }
    dfs(o);

    vector<oper_t> ops;
    for(int i = 1; i <= n; i++) {
        ops.emplace_back(0, make_tuple(dfn_str[i], i, 1));
    }

    int qid = 0;
    for(int i = 1; i <= m; i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x, y;
            cin >> x >> y;
            ops.emplace_back(0, make_tuple(dfn_str[x], x, -1));
            ops.emplace_back(0, make_tuple(dfn_str[y], y, -1));
            swap(dfn_str[x], dfn_str[y]);
            ops.emplace_back(0, make_tuple(dfn_str[x], x, 1));
            ops.emplace_back(0, make_tuple(dfn_str[y], y, 1));
        } else {
            string str;
            int k, l, r;
            cin >> str >> k >> l >> r;
            ++qid;
            
            pair<int, int> dfn_rg = Trie_query(o, str.c_str(), k);
            if(dfn_rg.first != -1) {
                ops.emplace_back(1, make_tuple(dfn_rg.second, r, qid));
                ops.emplace_back(1, make_tuple(dfn_rg.first - 1, r, -qid));
                ops.emplace_back(1, make_tuple(dfn_rg.second, l - 1, -qid));
                ops.emplace_back(1, make_tuple(dfn_rg.first - 1, l - 1, qid));
            }
        }
    }

    vector<int> ans(qid + 1);
    solve(ops.data(), ops.data() + ops.size(), ans);

    for(int i = 1; i <= qid; i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
