#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int sum = 0;
        for (int i = 0; i < (N-1) * N / 2; i++) {
            int x;
            cin >> x;
            sum += x;
        }

        cout << sum / (N-1) << endl;
    }

    return 0;
}
