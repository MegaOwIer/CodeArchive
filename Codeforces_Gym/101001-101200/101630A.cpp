#include <bits/stdc++.h>
using namespace std;

#define ENDL "\n"
using LL = long long;
const int INF = 1000000000, MX = 200005;

pair<int, int> Circle[MX];

struct segTree
{
    set<int> S;
    int L, R;
    segTree *lson, *rson;
    segTree(int L, int R) : L(L), R(R), lson(nullptr), rson(nullptr) {}
    void insert(int, int, int);
    int query(int, int);
    void erase(int, int, int);
} *root = new segTree(-INF, INF);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int Q;
    cin >> Q;
    for(int i = 1; i <= Q; i++)
    {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1)
        {
            root -> insert(x - y, x + y, i);
            Circle[i] = make_pair(x, y);
        }
        else
        {
            int id = root -> query(x, y);
            if (id != -1)
            {
                int x0 = Circle[id].first, y0 = Circle[id].second;
                root -> erase(x0 - y0, x0 + y0, id);
            }
            cout << id << ENDL;
        }
    }
    return 0;
}

void segTree::insert(int l, int r, int id)
{
    if(l <= L && R <= r)
    {
        S.insert(id);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid)
    {
        if (!lson)
            lson = new segTree(L, mid);
        lson -> insert(l, r, id);
    }
    if (r > mid)
    {
        if (!rson)
            rson = new segTree(mid + 1, R);
        rson -> insert(l, r, id);
    }
}

inline bool check(int id, int x, int y)
{
    int x0 = Circle[id].first, y0 = Circle[id].second;
    return LL(x0 - x) * (x0 - x) + LL(y0 - y) * (y0 - y) < (LL) y0 * y0;
}

int segTree::query(int x, int y)
{
    for (int i : S)
        if (check(i, x, y))
            return i;
    int mid = (L + R) >> 1;
    if (x <= mid && lson != nullptr)
        return lson -> query(x, y);
    if (x > mid && rson != nullptr)
        return rson -> query(x, y);
    return -1;
}

void segTree::erase(int l, int r, int id)
{
    if(l <= L && R <= r)
    {
        S.erase(id);
        return;
    }
    int mid = (L + R) >> 1;
    if (l <= mid)
        lson -> erase(l, r, id);
    if (r > mid)
        rson -> erase(l, r, id);
}
