#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main() {
    int N, M;
    while (cin >> N >> M, N || M) {
        vector<vector<P> > V(N);
        for (int i = 0; i < M; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            V[a].push_back(P(c, b));
            V[b].push_back(P(c, a));
        }

        priority_queue<P, vector<P>, greater<P> > que;
        vector<int> used(N);
        que.push(P(0, 0));

        int sum = 0;
        while (que.size()) {
            P p = que.top(); que.pop();
            int now = p.second;
            int cost = p.first;

            if (used[now]) continue;
            used[now] = true;
            sum += cost;

            for (auto i : V[now]) {
                que.push(i);
            }
        }

        cout << sum << endl;
    }

    return 0;
}
