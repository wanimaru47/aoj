#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, C, N;
    while (cin >> M >> C >> N, M || C || N) {
        vector<deque<int>> vd(M+1);
        for (int i = 1; i <= 100; i++) vd[M].push_back(i);

        queue<queue<int>> vs;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            queue<int> q;
            for (int j = 0; j < k; j++) {
                int x;
                cin >> x;
                q.push(x);
            }
            vs.push(q);
        }

        int ans = 0;
        while (vs.size()) {
            auto q =  vs.front();
            vs.pop();
            int book = q.front();
            q.pop();
            if (q.size() > 0) vs.push(q);

            for (int i = 0; i <= M; i++) {
                for (int j = 0; j < vd[i].size(); j++) {
                    if (vd[i][j] == book) {
                        ans += i + 1;
                        vd[i].erase(vd[i].begin() + j);
                        break;
                    }
                }
            }

            if (vd[0].size() < C) {
                vd[0].push_back(book);
                ans += 1;
            } else {
                int p1 = -1, p2 = -1;
                for (int i = 1; i <= M; i++) {
                    if (vd[i].size() < C || i == M) {
                        if (p1 < 0) {
                            p1 = i;
                            if (i == M || vd[i].size() + 1 < C) i--;
                        } else if (p2 < 0) {
                            p2 = i;
                        }
                    }
                }

                int rebook = vd[0].front();
                vd[0].pop_front();
                
                vd[p2].push_back(rebook);
                vd[0].push_back(book);

                ans += (p1 + 1) * 2 + 1;
                ans += p2 + 2;
            }
        }

        cout << ans << endl;
    }

  return 0;
}
