#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int k, p;
        cin >> k >> p;

        int mod = k % p;
        if (mod) cout << mod << endl;
        else cout << p << endl;
    }

    return 0;
}
