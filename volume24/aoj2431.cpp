#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct SegmetTree
{
    int N;
    vector<T> dat;

    SegmetTree(int n) {
        N = 1;
        while (N < n) N *= 2;
        dat.resize(N * 2 - 1, 0);
    }

    void update(int k, T a) {
        k += N - 1;
        dat[k] = a;
        while (k > 0) {
            k = (k - 1) / 2;
            dat[k] = max(dat[k * 2 + 1], dat[k * 2 + 2]);
        }
    }

    T Max(int limit, int k, int l, int r) {
        if (limit <= l) return 0;
        if (r <= limit) return dat[k];
        T vl = Max(limit, k * 2 + 1, l, (r + l) / 2);
        T vr = Max(limit, k * 2 + 2, (r + l) / 2, r);

        return max(vl, vr);
    }
};

int main() {
    long long int N; cin >> N;
    SegmetTree<long long int> st(N + 1);

    for (int i = 0; i < N; i++) {
        int now;
        cin >> now;
        st.update(now, now + st.Max(now, 0, 0, (st.dat.size() + 1) / 2));
    }
    cout << (((N + 1) * N) / 2) - st.dat[0] << endl;

    return 0;
}
