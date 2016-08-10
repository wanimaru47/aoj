#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, Q;
    while (cin >> W >> Q, W || Q) {
        vector<int> used(W+1, -1);
        vector<int> cat(Q);

        for (int i = 0; i < Q; i++) {
            char c;
            cin >> c;
            if (c == 'w') {
                int n;
                cin >> n;
                int car = cat[n];
                while (used[car] == n) used[car] = -1, car++;
            } else {
                int s, w;
                cin >> s >> w;

                bool flag = false;
                for (int i = 0; !flag && i < W-w+1; i++) {
                    if (used[i] != -1) continue;

                    bool f = true;
                    for (int j = 0; f && j < w; j++) {
                        if (used[i+j] != -1) f = false;
                    }
                    if (f) {
                        flag = true;
                        cat[s] = i;
                        cout << i << endl;

                        for (int j = 0; j < w; j++) {
                            used[i+j] = s;
                        }
                    }
                }
                if (!flag) cout << "impossible" << endl;
            }
        }

        cout << "END" << endl;
    }

    return 0;
}
