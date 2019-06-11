#include<bits/stdc++.h>
using namespace std;

struct status {
    int pos[3];
    
    status() {}
    status(int a, int b, int c) {
        pos[0] = a, pos[1] = b, pos[2] = c;
        sort(pos, pos + 3);
    }
    bool operator == (const status a) const {
        for(int i = 0; i < 3; i++)
            if(pos[i] != a.pos[i]) return false;
        return true;
    }
    int depth() {
        int ans = 0, l = pos[1] - pos[0], r = pos[2] - pos[1];
        while(l != r) {
            if(l < r) swap(l, r);
            ans += (l - 1) / r;
            l = (l - 1) % r + 1;
        }
        return ans;
    }
    status update(int delta) {
        int a = pos[0], b = pos[1], c = pos[2];
        while(delta) {
            int l = b - a, r = c - b;
            if(l == r) {
                break;
            } else if(l < r) {
                int op = min(delta, (r - 1) / l);
                r -= op * l;
                b = c - r, a = b - l;
                delta -= op;
            } else {
                int op = min(delta, (l - 1) / r);
                l -= op * r;
                b = a + l, c = b + r;
                delta -= op;
            }
        }
        return status(a, b, c);
    }
}pre, nxt;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c), pre = status(a, b, c);
    scanf("%d%d%d", &a, &b, &c), nxt = status(a, b, c);
    int dep1 = pre.depth(), dep2 = nxt.depth();
    if(pre.update(dep1) == nxt.update(dep2)) {
        if(dep1 < dep2)
            swap(dep1, dep2), swap(pre, nxt);
        int ans = dep1 - dep2;
        for(int i = 1 << 30; dep1 != dep2; i >>= 1)
            if(i <= dep1 - dep2) {
                pre = pre.update(i), dep1 -= i;
            }
        if(!(pre == nxt)) {
            for(int i = 1 << 30; i; i >>= 1) {
                status fp = pre.update(i), fn = nxt.update(i);
                if(fp == fn) continue;
                pre = fp, nxt = fn;
                ans += i << 1;
            }
            ans += 2;
        }
        printf("YES\n%d\n", ans);
    } else {
        return puts("NO"), 0;
    }
    return 0;
}
