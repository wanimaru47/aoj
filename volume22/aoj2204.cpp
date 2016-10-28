#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int t = 0, d = 500;
        for (int i = 0; i < N; i++) {
            int sum  = 0;
            for (int j = 0; j < 5; j++) {
                int n;
                cin >> n;
                sum += n;
            }

            t = max(t, sum);
            d = min(d, sum);
        }

        cout << t << " " << d << endl;
    }

    return 0;
}
