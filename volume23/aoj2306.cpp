#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[100][100];

set<set<int>> mem;

int dfs(set<int> used) {
    int cost = 0;
    for (auto i: used) {
        int min_cost = 1 << 28;
        for (auto j: used) {
            if (i == j) continue;
            min_cost = min(min_cost, v[i][j]);
        }
        if (min_cost == 1 << 28) min_cost = 0;
        cost += min_cost;
    }

    mem.insert(used);

    for (int i = 0; i < n; i++) {
        if (used.find(i) != used.end()) continue;
        
        bool flag = true;
        for (auto j: used) {
            if (v[i][j] == 0) flag = false;
        }

        if (flag) {
            auto tmp = used;
            tmp.insert(i);
            if (mem.find(tmp) == mem.end())
                cost = max(cost, dfs(tmp));
        }
    }

    return cost;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        v[x-1][y-1] = v[y-1][x-1] = z;
    }

    cout << dfs(set<int>()) << endl;
    
    return 0;
}
