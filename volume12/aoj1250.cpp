#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

void solve () {
    vector<ll> num(9);
    for (auto &i : num) cin >> hex >> i;
    num.push_back(0LL);

    vector<vector<bool> > bits_list(10, vector<bool>(33));
    auto itr = 0;
    for (auto i : num) {
        for (int j = 0; j < 32; j++) {
            bits_list[itr][j] = i % 2LL;
            i /= 2LL;
        }
        itr++;
    }

    int c = 0;
    for (int i = 0; i < 32; i++) {
        int count0 = c;
        int count1 = c;
        for (int j = 0; j < 8; j++) {
            count0 += bits_list[j][i] ^ false;
            count1 += bits_list[j][i] ^ true;
        }

        int tmp1 = (count0 + c) % 2;
        int tmp2 = (count1 + c) % 2;
        int tmp3 = bits_list[8][i];

        if (count0 % 2 == bits_list[8][i]) {
            bits_list[9][i] = 0;
            c = count0 / 2;
        } else {
            bits_list[9][i] = 1;
            c = count1 / 2;
        }
    }

    ll res = 0;
    c = 1;
    for (int i = 0; i < 32; i++) {
        res += bits_list[9][i] * c;
        c *= 2;
    }

    cout << hex << (int)res << endl;
}

int main() {
    int Q; cin >> Q;
    while (Q--) solve();

    return 0;
}
