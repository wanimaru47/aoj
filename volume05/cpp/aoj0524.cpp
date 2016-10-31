#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
int main() {
    int M;
    while (cin >> M, M) {
        vector<int> x(M), y(M);
        for (int i = 0; i < M; i++) {
            cin >> x[i] >> y[i];
        }

        vector<P> sub(M);
        for (int i = 0; i < M; i++) {
            sub[i] = P(x[i] - x[0], y[i] - y[0]);
        }

        int N;
        cin >> N;
        vector<int> nx(N), ny(N);
        for (int i = 0; i < N; i++) {
            cin >> nx[i] >> ny[i];
        }

        for (int i = 0; i < N; i++) {
            set<P> s;
            for (int j = 0; j < N; j++) {
                s.insert(P(nx[j] - nx[i], ny[j] - ny[i]));
            }

            bool flag = true;
            for (int j = 0; flag && j < M; j++) {
                if (s.find(sub[j]) == s.end()) flag = false;
            }

            if (flag) {
                cout << nx[i] - x[0] << " " << ny[i] - y[0] << endl;
                break;
            }
        }
    }

    return 0;
}
