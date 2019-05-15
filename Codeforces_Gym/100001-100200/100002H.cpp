#include<bits/stdc++.h>
using namespace std;

#define ENDL "\n"

int N, maxHP, HPM, dH, L[15];
int attack[105], moveFrom[11];
bool vis[51][101][11][101];
vector<string> ans;

bool dfs(int MP, int totalHP, int pos, int HP) {
    if(vis[MP][totalHP][pos][HP]) return false;
    vis[MP][totalHP][pos][HP] = true;
    if(totalHP == 0) return true;
    if(MP == 0) return false;
    int newPos, newHP;
    // Heal
    newPos = moveFrom[pos];
    newHP = min(HP + dH, maxHP) - (newPos == 1 ? attack[totalHP] : 0);
    if(newHP > 0 && dfs(MP - 1, totalHP, newPos, newHP)) {
        ans.push_back("H");
        return true;
    }
    // Lighting Bolt
    if(totalHP <= L[pos]) {
        ans.push_back("L");
        return true;
    }
    newPos = moveFrom[pos];
    newHP = HP - (newPos == 1 ? attack[totalHP - L[pos]] : 0);
    if(newHP > 0 && dfs(MP - 1, totalHP - L[pos], newPos, newHP)) {
        ans.push_back("L");
        return true;
    }
    // Teleport
    for(int i = 1; i <= N; i++) {
        newPos = moveFrom[i];
        newHP = HP - (newPos == 1 ? attack[totalHP] : 0);
        if(newHP > 0 && dfs(MP - 1, totalHP, newPos, newHP)) {
            ans.push_back("T " + to_string(i));
            return true;
        }
    }
    return false;
}

int main() {
    int MP, NM, V;
    ifstream cin("heroes.in");
    ofstream cout("heroes.out");
    cin >> N >> maxHP >> MP >> HPM >> NM >> V >> dH;
    for(int i = 1; i <= N; i++) {
        cin >> L[i];
        moveFrom[i] = max(1, i - V);
    }
    for(int i = 1; i <= NM; i++) attack[i * HPM] = i;
    for(int i = NM * HPM; i >= 1; i--)
        if(!attack[i]) attack[i] = attack[i + 1];
    if(!dfs(MP, HPM * NM, N, maxHP))
        cout << "DEFEATED" << ENDL;
    else {
        reverse(ans.begin(), ans.end());
        cout << "VICTORIOUS" << ENDL;
        for(string &res : ans)
            cout << res << ENDL;
    }
    return 0;
}
