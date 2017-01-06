#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        string process;
        cin >> process;
        vector<int> locked(N);
        vector<set<int>> next(1<<12);
        vector<int> is(1<<12);
        bool ans = true;

        for (int i = 0, now = 0; i < N; i++) {
            is[now] = true;
            if (process[i] == 'u') {
                now = 0;
                continue;
            }
            int s = process[i] - '0';
            if (now & (1 << s)) ans = false;

            next[now].insert(s);
            now += (1 << s);
        }

        for (int i = 0; ans && i < (1 << 11); i++) {
            for (int j = 0; j < (1 << 11); j++) {
                if ((i & j) != j) continue;
                int nj = i ^ j;
                bool flag = false;

                if (j == nj) continue;
                if (!is[j] || !is[nj]) continue;
                if (next[j].size() == 0 || next[nj].size() == 0) continue;
                is[i] = true;

                for (auto k : next[j]) {
                    if (!(nj & (1 << k))) flag = true;
                    if (!(j & (1 << k)) && !(nj & (1 << k)))
                        next[i].insert(k);
                }
                for (auto k : next[nj]) {
                    if (!(j & (1 << k))) flag = true;
                    if (!(j & (1 << k)) && !(nj & (1 << k)))
                        next[i].insert(k);
                }

                if (!flag) ans = false;
            }
        }

        if (ans) cout << "SAFE" << endl;
        else cout << "UNSAFE" << endl;
    }

    return 0;
}
