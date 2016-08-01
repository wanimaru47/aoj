#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int sum = 0;
        for (int i = 0, x; i < N/4; i++) cin >> x, sum += x;
        cout << sum << endl;
    }

    return 0;
}
