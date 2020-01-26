#include<bits/stdc++.h>
using namespace std;

struct Node {
    int mx, tag, mn;
};

const int MX = 1000005;

int s[MX];
Node tr[MX << 2];

void pushdown(int id) {
    int tag = tr[id].tag;
    tr[id << 1].mx += tag, tr[id << 1 | 1].mx += tag;
    tr[id << 1].mn += tag, tr[id << 1 | 1].mn += tag;
    tr[id << 1].tag += tag, tr[id << 1 | 1].tag += tag;
    tr[id].tag = 0;
}

void increase(int l, int r, int id, int delta, int L) {
    if(l >= L) {
        tr[id].mx += delta;
        tr[id].mn += delta;
        tr[id].tag += delta;
        return;
    }
    pushdown(id);
    int mid = (l + r) >> 1;
    if(L <= mid) increase(l, mid, id << 1, delta, L);
    increase(mid + 1, r, id << 1 | 1, delta, L);
    tr[id].mx = max(tr[id << 1].mx, tr[id << 1 | 1].mx);
    tr[id].mn = min(tr[id << 1].mn, tr[id << 1 | 1].mn);
}

int main() {
    int n, cur = 1, sum = 0;
    scanf("%d", &n), getchar();
    for(int cas = 1; cas <= n; cas++) {
        char c = getchar();
        switch(c) {
            case 'L':
                cur = max(1, cur - 1);
                break;
            case 'R':
                cur = cur + 1;
                break;
            default:
                auto getVal = [](char _) {return _ == '(' ? 1 : (_ == ')' ? -1 : 0);};
                sum += getVal(c) - s[cur];
                increase(1, n, 1, getVal(c) - s[cur], cur);
                s[cur] = getVal(c);
                break;
        }
        cout << (tr[1].mn >= 0 && sum == 0 ? tr[1].mx : -1) << ' ';
    }
    return 0;
}
