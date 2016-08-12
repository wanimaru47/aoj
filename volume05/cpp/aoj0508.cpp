#include <bits/stdc++.h>
using namespace std;

int dfs (vector<vector<int> > &v, int now, vector<bool> &used, int count) {
    if (used[now]) return count;
    count++;

    used[now] = true;
    int ret = count;
    for (auto i : v[now]) {
        ret = max(ret, dfs(v, i, used, count));
    }
    used[now] = false;

    return ret;
}

int main() {
    int N;
    while (cin >> N, N) {
        vector<vector<int> > v(101);
        for (int i = 0; i < N; i++) {
            int x, y;
            cin >> x >> y;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        int ans = 0;
        vector<bool> used(101, false);
        for (int i = 1; i <= 100; i++) {
            ans = max(ans, dfs(v, i, used, 0));
        }
        cout << ans << endl;
    }

    return 0;
}
