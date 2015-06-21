#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#define INF 1 << 28
#define MAX_DATA 1 << 17
using namespace std;

typedef pair<int,int> P;

template <class T>
class SegmentTree
{
private :
    int n;
    vector<T> data;
public :
    void init(int);
    void update(int, int);
    int query(int, int, int, int, int);
    int size();
    T top();
};

template <class T>
void SegmentTree<T>::init (int n_) {
    n = 1;
    while (n < n_ + 1) n *= 2;
    data.resize(n * 2);
    for (int i = 0; i < data.size(); i++) data[i] = 0;
}

template <class T>
void SegmentTree<T>::update (int k_, int l_) {
    for (int i = k_; i <= 1260 - 540 && i < l_; i++) {
        int tmp_ = i + n - 1;
        data[tmp_] = 1;
        while (tmp_) {
            tmp_ = (tmp_ - 1) / 2;
            data[tmp_] = data[tmp_ * 2 + 1] + data[tmp_ * 2 + 2];
        }
    }
}

template <class T>
int SegmentTree<T>::query (int a_, int b_, int k_, int l_, int r_) {
    if (r_ <= a_ || b_ <= l_) return 0;

    if (a_ <= l_ && r_ <= b_) {
        return data[k_];
    }
    else {
        T vl = query(a_, b_, k_ * 2 + 1, l_, (l_ + r_) / 2);
        T vr = query(a_, b_, k_ * 2 + 2, (l_ + r_) / 2, r_);

        return (vl + vr);
    }
}

template <class T>
int SegmentTree<T>::size () {
    return n;
}

template <class T>
T SegmentTree<T>::top () {
    return data[0];
}

int main()
{
    int N, M;
    while (cin >> N >> M, (N || M)) {
        int R;
        cin >> R;

        vector<SegmentTree<unsigned short> > p(M + 1);
        for (int i = 0; i < p.size(); i++) {
            p[i].init(1260 - 540);
        }
        map<P,int> dat;
        for (int i = 0; i < R; i++) {
            unsigned short t, n, m, s;
            cin >> t >> n >> m >> s;

            t -= 540;
            if (s) {
                dat[P(n,m)] = t;
            } else {
                int tmp = dat[P(n,m)];
                auto ite = dat.find(P(n,m));
                dat.erase(ite);
                p[m].update(tmp, t);
            }
        }

        for (auto i : dat) {
            p[i.first.second].update(i.second, INF);
        }

        int Q;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            unsigned short ts, te, m;
            cin >> ts >> te >> m;
            ts -= 540;
            te -= 540;
            cout << p[m].query(ts, te, 0, 0, p[m].size()) << endl;
        }
    }
    
    

    return 0;
}
