#include <bits/stdc++.h>
using namespace std;

int main () {
    int N, M;
    cin >> N >> M;
    vector<vector<int> > card(M + 1, vector<int>(N * 2));
    for (int i = 0; i < N * 2; i++) card[0][i] = i + 1;

    for (int t = 0; t < M; t++) {
        int q; cin >> q;
        if (q == 0) {
            for (int i = 0; i < N; i++) {
                card[t+1][i*2] = card[t][i];
                card[t+1][i*2+1] = card[t][i+N];
            }
        } else {
            for (int i = 0; i < q; i++) card[t+1][i+2*N-q] = card[t][i];
            for (int i = 0; i < 2*N-q; i++) card[t+1][i] = card[t][i+q];
        }
    }

    for (auto c : card[M]) cout << c << endl;

    return 0;
}
