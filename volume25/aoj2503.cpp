#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<P> vec;
typedef vector<vec> mat;

int main() {
    int N, M;

    cin >> N >> M;

    mat v(N);
    vector<int> sum(N);

    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back(P(b,c));
        sum[b]++;
    }

    queue<int> que;
    que.push(0);

    vector<int> cost(N);

    while (que.size()) {
        int now = que.front();
        que.pop();

        for (auto p : v[now]) {
            int next = p.first;
            int ncost = cost[now] + p.second;

            cost[next] = max(cost[next], ncost);

            sum[next]--;

            if (!sum[next]) {
                que.push(next);
            }
        }
    }

    cout << cost[N-1] << endl;

    return 0;
}
