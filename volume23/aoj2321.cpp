#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        vector<long long int> score(N);
        for (int i = 0; i < N; i++) {
            int t;
            cin >> t >> score[i];
            int s = 0;
            for (int j = 0; j < t; j++) {
                int start, end;
                cin >> start >> end;
                for (int k = start; k < end; k++) v[i] |= (1 << (k - 6));
            }
        }

        vector<map<int, long long int> > m(N+1);
        m[0][0] = 0;
        for (int i = 0; i < N; i++) {
            for (auto j : m[i]) {
                m[i+1][j.first] = max(m[i+1][j.first], j.second);
                if (j.first & v[i]) continue;
                int next = j.first + v[i];
                m[i+1][next] = max(m[i+1][next], j.second + score[i]);
            }
        }

        long long int res = 0;
        for (auto i : m[N]) {
            res = max(res, i.second);
        }

        cout << res << endl;
    }

    return 0;
}
