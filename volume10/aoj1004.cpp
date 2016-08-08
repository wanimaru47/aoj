#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<bool> prime(10001, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i <= 10000/2; i++) {
        if (!prime[i]) continue;
        for (int j = 2; j * i <= 10000; j++) {
            prime[i*j] = false;
        }
    }
    while (cin >> N) {
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (prime[i+1] && prime[N-i]) count++;
        }

        cout << count << endl;
    }

    return 0;
}
