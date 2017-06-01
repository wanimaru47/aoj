#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<int>> v, rv;
vector<int> cmp, vs;
bool used[10001];
const long long int MOD = 1e9+7LL;

void dfs(int now) {
    used[now] = true;

    for (auto next: v[now]) {
        if (!used[next]) dfs(next);
    }

    vs.push_back(now);
}

void rdfs(int now, int k) {
    used[now] = true;
    cmp[now] = k;

    for (auto next: rv[now]) {
        if (!used[next]) rdfs(next, k);
    }
}

int scc() {
    memset(used, 0, sizeof(used));
    vs.clear();
    for (int i = 0; i < N; i++)
        if (!used[i]) dfs(i);

    memset(used, 0, sizeof(used));
    int k = 0;
    for (int i = vs.size() - 1; i >= 0; i--) {
        if (!used[vs[i]]) rdfs(vs[i], k++);
    }

    return k;
}

int main() {
    cin >> N >> M;
    v.resize(N), rv.resize(N), cmp.resize(N);

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--, y--;

        v[x].push_back(y);
        rv[y].push_back(x);
    }

    int k = scc();
    vector<int> next(k, -1);
    for (int i = 0; i < N; i++) {
        if (v[i].size())
            next[cmp[i]] = cmp[v[i][0]];
    }

    vector<long long int> sum(k, 0);
    memset(used, 0, sizeof(used));
    long long int ans = 1LL;
    for (int i = 0; i < k; i++) {
        if (sum[i]) {
            sum[i]++;
        } else {
            sum[i] = 2LL;
        }

        if (next[i] < 0 || next[i] == i) 
            ans = (ans * sum[i]) % MOD;
        else if (sum[next[i]]) 
            sum[next[i]] = (sum[next[i]] * sum[i]) % MOD;
        else 
            sum[next[i]] = (sum[next[i]] + sum[i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}
