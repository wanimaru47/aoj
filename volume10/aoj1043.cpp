#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main() {
    int N;
    while (cin >> N, N) {
        vector<vector<P> > rank(11);
        vector<int> univ_id(1001);

        for (int c = 0; c < N; c++) {
            int i, u, a, p;
            cin >> i >> u >> a >> p;
            rank[a].push_back(P(p,i));
            univ_id[i] = u;
        }

        for (auto& i : rank)
            sort(i.begin(), i.end());

        int count = 0;
        vector<int> univ_cnt(1001);
        for (int i = 10; i > -1; i--) {
            for (auto team : rank[i]) {
                int I = team.second;
                int pena = team.first;
                int limit = 0;
                if (count < 10) limit = 3;
                else if (count < 20) limit = 2;
                else if (count < 26) limit = 1;
                else limit = 0;
                if (univ_cnt[univ_id[I]] < limit) {
                    cout << I << endl;
                    univ_cnt[univ_id[I]]++;
                    count++;
                }
            }
        }
    }

    return 0;
}
