#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<pair<int,int> > v;
        for (int i = 0; i < N; i++) {
            int id, am, as, bm, bs, cm, cs, dm, ds;
            cin >> id >> am >> as >> bm >> bs >> cm >> cs >> dm >> ds;
            int sum = (am + bm + cm + dm) * 60 + as + bs + cs + ds;
            v.push_back(pair<int,int>(sum, id));
        }

        sort(v.begin(), v.end());

        cout << v[0].second << endl;
        cout << v[1].second << endl;
        cout << v[N-2].second << endl;
    }

    return 0;
}
