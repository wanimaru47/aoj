#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> d(10);
        for (int i = 0; i < N; i++) {
            int x = 0;
            cin >> x;
            d[x]++;
        }

        for (auto i : d) {
            if (i == 0) cout << "-" << endl;
            else {
                for (int j = 0; j < i; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
