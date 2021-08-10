#include <bits/stdc++.h>
using namespace std;

const int MX = 100005;

struct trieNode {
    trieNode *son[2];
    int mxVal;

    trieNode() : mxVal(-1) {
        son[0] = son[1] = nullptr;
    }

    void *operator new (size_t);
};

size_t pool_iter = 0;
void *trieNode::operator new (size_t) {
    static vector<trieNode> pool(MX * 30);
    return &pool[pool_iter++];
}

int val[MX];

void trie_insert(trieNode *o, int val, int pos) {
    for(int i = 29; i >= 0; i--) {
        int bit = (val >> i) & 1;
        if(!o->son[bit]) {
            o->son[bit] = new trieNode;
        }
        o = o->son[bit];
        o->mxVal = max(o->mxVal, pos);
    }
}

int trie_query(trieNode *o, int val, int k) {
    int ans = -1;
    for(int i = 29; i >= 0 && o; i--) {
        int vbit = (val >> i) & 1;
        int kbit = (k >> i) & 1;

        int dir = vbit ^ kbit;
        if(kbit == 0 && o->son[dir ^ 1]) {
            ans = max(ans, o->son[dir ^ 1]->mxVal);
        }
        o = o->son[dir];
    }
    if(o) {
        ans = max(ans, o->mxVal);
    }
    return ans;
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) {
            scanf("%d", &val[i]);
            val[i] ^= val[i - 1];
        }

        trieNode *root = new trieNode;
        trie_insert(root, 0, 0);

        int ansl = -1, ansr = n;
        for(int i = 1; i <= n; i++) {
            int cur = trie_query(root, val[i], k);
            if(cur != -1 && i - cur < ansr - ansl) {
                ansl = cur, ansr = i;
            }
            trie_insert(root, val[i], i);
        }

        if(ansl == -1) {
            puts("-1");
        } else {
            printf("%d %d\n", ansl + 1, ansr);
        }

        pool_iter = 0;
    }
    return 0;
}