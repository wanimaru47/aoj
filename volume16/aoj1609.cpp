#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<char> v(N);
        for (auto& i : v) cin >> i;

        vector<int> sum(26);
        for (int i = 0; i < N; i++) {
            sum[v[i] - 'A']++;
            vector<pair<int,int> > ssum;
            for (int j = 0; j < 26; j++) {
                ssum.push_back(pair<int,int>(sum[j], j));
            }
            sort(ssum.begin(), ssum.end());

            if (N - i - 1 + ssum[24].first < ssum[25].first) {
                cout << (char)(ssum[25].second + 'A') << " " << i + 1 << endl;
                break;
            }
            if (i + 1 == N) {
                cout << "TIE" << endl;
            }
        }
    }

    return 0;
}
