#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1<<28;
int N, Q;

void solve() {
    vector<set<int> > T(N+1);
    vec rT(N+1);
    rT[1] = 1;
    for (int i = 2; i <= N; i++) {
        int par; cin >> par;
        T[par].insert(i);
        rT[i] = par;
    }

    vector<bool> isleaf(N+1);
    for (int i = 1; i <= N; i++)
        if (T[i].size() == 0) isleaf[i] = true;

    vec MarkedTime(N+1, INF);
    MarkedTime[1] = -1;
    vector<set<int> > QueryTime(N+1);
    for (int i = 0; i < Q; i++) {
        char q;
        int v;
        cin >> q >> v;
        if (q == 'M') MarkedTime[v] = min(MarkedTime[v], i);
        else QueryTime[v].insert(i);
    }

    vector<bool> used(N+1, false);
    priority_queue<P, vector<P> > que;
    int now = 1;
    int cost = 0;
    while (true) {
        for (auto i : QueryTime[now]) {
            que.push(P(i, ));
        }
        QueryTime[now].clear();
        while (que.size() > 0 && que.top() > MarkedTime[now]) {
            cost += now;
            que.pop();
        }
        if (T[now].size()) {
            int next = *(T[now].begin());
            T[now].erase(next);
            now = next;
        }
        else
    }
}

int main() {
    while (cin >> N >> Q, N || Q) solve();

    return 0;
}
