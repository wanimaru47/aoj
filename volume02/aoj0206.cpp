#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N , N) {
        vector<int> v(12);
        for (auto& i : v) {
            int x, y;
            cin >> x >> y;
            i = x - y;
        }

        int sum = 0;
        for (int i = 0; i < 12; i++) {
            sum += v[i];
            if (sum >= N) {
                cout << i + 1 << endl;
                break;
            }

            if (i == 11) {
                cout << "NA" << endl;
            }
        }
    }

    return 0;
}
