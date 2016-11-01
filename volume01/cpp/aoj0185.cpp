#include <bits/stdc++.h>
using namespace std;

int main() {
    bool is_prime[1000001];
    for (int i = 0 ; i < 1000001; i++) is_prime[i] = true;
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= 1000000 / 2; i++) {
        if (is_prime[i])
            for (int j = 2; j * i <= 1000000; j++) {
                is_prime[i*j] = false;
            }
    }
    int N;
    while (cin >> N, N) {
        int count = 0;

        for (int i = 0; i <= N / 2; i++) {
            if (is_prime[i] && is_prime[N-i]) {
                count++;
            }
        }

        cout << count << endl;
    }

    return 0;
}
