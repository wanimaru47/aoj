#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    bool first = true;
    while (cin >> N, N) {
        if (!first) cout << endl;
        first = false;

        set<int> s;
        vector<string> name(N);
        vector<int> score(N);
        for (int i = 0; i < N; i++) {
            cin >> name[i];
            int x, y, z;
            cin >> x >> y >> z;
            score[i] = x * 3 + z;
            s.insert(-score[i]);
        }

        vector<int> idx;
        for (auto i : s) {
            for (int j = 0; j < N; j++) {
                if (score[j] == -i) {
                    idx.push_back(j);
                }
            }
        }

        for (auto i : idx) cout << name[i] << "," << score[i] << endl;
    }

    return 0;
}
