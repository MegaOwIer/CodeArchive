#include<bits/stdc++.h>
using namespace std;

struct Line { // Ax + By = C
    int A, B, C;
    Line() {}
    Line(int A, int B, int C) : A(A), B(B), C(C) {}
    bool onLine(const pair<int, int> &P) const {
        return A * P.first + B * P.second == C;
    }
}cut[305];

int N, M, K, ans;
vector<pair<int, int>> P;
vector<int> G[45000];

int isInVector(int a, const vector<int> &vec) {
    for(const int &val : vec)
        if(val == a) return 1;
    return 0;
}

int main() {
    ifstream cin("inlay.in");
    ofstream cout("inlay.out");
    cin >> N >> M >> K;
    N *= 2, M *= 2;
    P.push_back({0, 0}), P.push_back({N, 0});
    P.push_back({0, M}), P.push_back({N, M});
    for(int i = 1; i <= K; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 *= 2, y1 *= 2, x2 *= 2, y2 *= 2;
        if(x1 == x2)
            cut[i] = Line(1, 0, x1);
        else if(y1 == y2)
            cut[i] = Line(0, 1, y1);
        else if(y1 - x1 == y2 - x2)
            cut[i] = Line(1, -1, x1 - y1);
        else if(y1 + x1 == y2 + x2)
            cut[i] = Line(1, 1, x1 + y1);
        else throw;
        P.push_back({x1, y1});
        P.push_back({x2, y2});
    }
    for(int i = 1; i < K; i++)
        for(int j = i + 1; j <= K; j++) {
            int D = cut[i].A * cut[j].B - cut[i].B * cut[j].A;
            if(D == 0)
                continue;
            int X = (cut[i].C * cut[j].B - cut[i].B * cut[j].C) / D;
            int Y = (cut[i].A * cut[j].C - cut[i].C * cut[j].A) / D;
            if(X >= 0 && X <= N && Y >= 0 && Y <= M)
                P.push_back({X, Y});
        }
    sort(P.begin(), P.end());
    P.erase(unique(P.begin(), P.end()), P.end());
    cut[++K] = Line(1, 0, 0);
    cut[++K] = Line(1, 0, N);
    cut[++K] = Line(0, 1, 0);
    cut[++K] = Line(0, 1, M);
    for(int l = 1; l <= K; l++) {
        for(size_t i = 0, pre = -1u; i < P.size(); i++) {
            if(!cut[l].onLine(P[i]))
                continue;
            if(pre != -1u)
                G[pre].push_back(i);
            pre = i;
        }
    }
    for(size_t i = 0; i < P.size(); i++) {
        for(auto it1 = G[i].begin(); it1 != G[i].end(); ++it1)
            for(auto it2 = it1 + 1; it2 != G[i].end(); ++it2) {
                if(*it1 < *it2)
                    ans += isInVector(*it2, G[*it1]);
                else
                    ans += isInVector(*it1, G[*it2]);
            }
    }
    cout << ans << endl;
    return 0;
}
