#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> v(N);
        for (auto& i : v) cin >> i;

        int sum = 32;
        int c = 0;
        while (sum) {
            if (c % 2 == 0) {
                sum -= (sum - 1) % 5;
            } else {
                sum = max(0, sum - v[(c/2)%N]);
            }
            c++;
            cout << sum << endl;
        }
    }

    return 0;
}
