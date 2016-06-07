#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

void add(vector<deque<int> >& v, int x, int y) {
    int next_y = -1;
    if (v[x].size()) {
        next_y = v[x].front();
        v[x].pop_front();
    }
    v[x].push_back(y);
    if (next_y > -1) {
        if (v[next_y].size() == 0) return ;
        int next_x = v[next_y].front();
        v[next_y].pop_front();
        add(v, next_x, next_y);
    }
}

int main() {
    int N;
    cin >> N;
    vector<int> u(N), d(N), q(N);
    for (int i = 0; i < N; i++) {
        string str;
        cin >> u[i] >> str >> d[i];
        if (str == "wait") q[i] = 1;
        u[i] += 99;
        d[i]--;
    }

    vector<deque<int> > v(200);
    bool ans = false;
    for (int i = 0; i < N; i++) {
        if (q[i]) {
            v[d[i]].push_back(u[i]);
        } else {
            add(v, u[i], d[i]);
        }

        for (int j = 100; j < 200; j++) {
            if (v[j].size() == 0) continue;
            vector<bool> used(200, false);
            queue<int> que;
            que.push(v[j].front());
            used[j] = true;
            while (que.size()) {
                int now = que.front(); que.pop();
                if (now == j) {
                    ans = true;
                    goto FAILURE;
                }
                for (auto k : v[now]) que.push(k);
                if (used[now]) break;
                used[now] = true;
            }
        }
    }

  FAILURE:

    cout << ans << endl;

    return 0;
}
