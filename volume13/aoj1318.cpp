#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<P, int> sP;

void solve(int N, int M, int C) {
    string start, goal;
    cin >> start >> goal;

    set<string> citys;
    vector<string> slist(N), elist(N);
    vector<int> edge(N);
    for (int i = 0; i < N; i++) {
        cin >> slist[i] >> elist[i] >> edge[i];
        citys.insert(slist[i]);
        citys.insert(elist[i]);
    }

    map<string,int> s_num;
    int _idx = 0;
    for (auto i : citys) {
        s_num[i] = _idx;
        _idx++;
    }

    vector<vector<P>> m(citys.size());
    for (int i = 0; i < N; i++) {
        m[s_num[slist[i]]].push_back(P(s_num[elist[i]], edge[i]));
        m[s_num[elist[i]]].push_back(P(s_num[slist[i]], edge[i]));
    }

    vector<int> store(M);
    for (auto& i : store) {
        string x;
        cin >> x;
        i = s_num[x];
    }
    

    vector<map<int,int>> dp(citys.size());
    dp[s_num[start]][C*10] = 0;

    priority_queue<sP, vector<sP>, greater<sP>> que;
    que.push(sP(P(0, C*10), s_num[start]));

    while (que.size() > 0) {
        auto sp = que.top(); que.pop();
        int now = sp.second;
        int cost = sp.first.first;
        int cap = sp.first.second;

        if (dp[now].size() > 0
            && dp[now].find(cap) != dp[now].end()
            && dp[now][cap] < cost) continue;

        if (now == s_num[goal]) break;

        for (auto city : m[now]) {
            int next = city.first;
            int dist = city.second;
            int _cap = cap - dist;

            if (_cap < 0) continue;
            if (find(store.begin(), store.end(), next) != store.end()) _cap = C * 10;
            
            if (dp[next].size() == 0 || dp[next].find(_cap) == dp[next].end()) {
                dp[next][_cap] = cost + dist;
                que.push(sP(P(cost + dist, _cap), next));
            } else if (dp[next][_cap] > cost + dist) {
                dp[next][_cap] = cost + dist;
                que.push(sP(P(cost + dist, _cap), next));
            }
        }
    }

    if (dp[s_num[goal]].size() == 0) cout << -1 << endl;
    else {
        int ans = 1 << 28;
        for (auto i : dp[s_num[goal]]) ans = min(ans, i.second);
        cout << ans << endl;
    }
}

int main() {
    int N, M, C;
    while (cin >> N >> M >> C, N || M || C) solve(N, M, C);

    return 0;
}
