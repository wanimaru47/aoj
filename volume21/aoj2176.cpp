#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int N, D;

void solve() {
    vector<vector<int> > C(N, vector<int>(10000));
    for (int i = 0; i < N; i++) {
        int m; cin >> m;
        C[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> C[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 9999; j++) {
            C[i][j + 1] += C[i][j];
        }
    }

    queue<P> que;
    multiset<int> s;
    for (int i = 0; i < N; i++) que.push(P(0, i)), s.insert(0);
    vector<int> iter(N, 0);

    int count = 0;
    while (que.size()) {
        P p = que.front(); que.pop();
        int num = p.first;
        int idx = p.second;

        if (iter[idx] >= C[idx].size()) continue;
        auto ite = s.find(num);
        s.erase(ite);
        int max_ = max(*s.rbegin(), C[idx][iter[idx]]);
        int min_ = min(*s.begin(), C[idx][iter[idx]]);
        if (max_ - min_ <= D) {
            que.push(P(C[idx][iter[idx]], idx));
            s.insert(C[idx][iter[idx]]);
            iter[idx]++;
            count = 0;
        } else {
            s.insert(num);
            que.push(p);
            count++;
        }

        if (count > N) {
            break;
        }
    }

    cout << (count > N ? "No" : "Yes") << endl;
}

int main() {
    while (cin >> N >> D, N || D) solve();

    return 0;
}
