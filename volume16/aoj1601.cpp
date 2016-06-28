#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) {
            string str;
            cin >> str;
            i = str.size();
        }

        for (int i = 1; i < N; i++) {
            v[i] += v[i-1];
        }
        v.insert(v.begin(), 0);

        int idx = 0;
        int seq[] = {5, 12, 17, 24, 31};
        while (1) {
            bool flag = true;
            int idx_ = idx;
            for (int i = 0; flag && i < 5; i++) {
                while (idx_ < N && v[idx_] - v[idx] < seq[i]) {
                    idx_++;
                }
                if (v[idx_] - v[idx] != seq[i]) flag = false;
            }
            if (flag) break;
            idx++;
            if (N <= idx) {
                flag = false;
                break;
            }
        }

        cout << idx + 1 << endl;
    }

    return 0;
}
