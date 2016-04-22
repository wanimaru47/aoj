#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<P> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;

mat v;

int long_path(int now, int pre, int d) {
    if (v[now].size() == 1) return 0;
    int ret = 0;
    for (int i = 0; i < v[now].size(); i++) {
        if (v[now][i].second == pre) continue;
        ret = max(ret, long_path(v[now][i].second, now, v[now][i].first));
    }

    return ret + d;
}

int main() {
    int n;
    while(cin >> n, n) {
        v.resize(0);
        v.resize(n);
        vector <int> A(n), B(n);
        for (int i = 1; i < n; i++) cin >> A[i], A[i]--;
        for (int i = 1; i < n; i++) cin >> B[i];
        for (int i = 1; i < n; i++) {
            v[i].push_back(P(B[i], A[i]));
            v[A[i]].push_back(P(B[i], i));
        }

        int sum = 0;
        int sum_of_lev = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < v[i].size(); j++) {
                if (v[i].size() > 1 && v[v[i][j].second].size() > 1) {
                    sum += v[i][j].first * 3;
                } else {
                    sum_of_lev += v[i][j].first;
                }
            }
        }

        sum /= 2;
        sum_of_lev /= 2;

        int path = 0;
        for (int i = 0; i < n; i++) {
            path = max(path, long_path(i, -1, 0));
        }

        cout << sum - path + sum_of_lev << endl;
    }

    return 0;
}
