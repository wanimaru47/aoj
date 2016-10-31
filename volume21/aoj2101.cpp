#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int sum = 0;
        if (N > 1) sum = 1;
        for (int i = 2; i <= sqrt(N); i++) {
            if (N % i == 0) {
                if (i != (N/i))
                    sum += i + (N/i);
                else
                    sum += i;
            }
        }

        if (sum < N) cout << "deficient number" << endl;
        else if (sum == N) cout << "perfect number" << endl;
        else cout << "abundant number" << endl;
    }

    return 0;
}
