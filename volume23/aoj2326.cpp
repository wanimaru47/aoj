#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

template <class T>
class BIT
{
private :
    vector<T> bit;
    int n;
public :
    T sum(int, T);
    void add (int, T, T);

    BIT (int i) {
        n = i;
        bit.resize(i + 1);
    }
};

template <typename T>
T BIT<T>::sum (int i, T K) {
    T s = (T)(0);
    while (i) {
        s += bit[i];
        s %= K;
        i -= i & -i;
    }

    return s;
}

template <typename T>
void BIT<T>::add (int i, T x, T K) {
    while (i <= n) {
        bit[i] += x;
        bit[i] %= K;
        i += i & -i;
    }
}

int main() {
    ll A, B, P;
    while (cin >> A >> B >> P, A || B || P) {
        vector<string> vs;
        for (int i = A; i <= B; i++) {
            stringstream ss;
            ss << i;
            string s;
            ss >> s;
            vs.push_back(s);
        }

        sort(vs.begin(), vs.end());

        BIT<ll> b(B - A + 1);
        for (int i = 0; i < vs.size(); i++) {
            stringstream ss;
            ss << vs[i];
            ll v;
            ss >> v;
            ll sum = b.sum((int)(v-A), P);
            b.add((int)(v-A+1LL), sum + 1LL, P);
        }

        cout << b.sum(B - A + 1LL, P) << endl;
    }

    return 0;
}
