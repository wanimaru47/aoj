#include <bits/stdc++.h>
using namespace std;



int main() {
    int N;

    bool isPrime[10001];
    for (int i = 0; i < 10001; i++) isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 0; i < 10001; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2; j * i < 10001; j++) {
            isPrime[i*j] = 0;
        }
    }

    vector<int> prime;
    prime.push_back(0);
    for (int i = 0; i < 10001; i++) if (isPrime[i]) prime.push_back(i);
    for (int i = 1; i < prime.size(); i++) prime[i] += prime[i-1];
    
    while (cin >> N, N) {
        int ans = 0;
        int i = 0, j = 0;
        while (i < prime.size() && j < prime.size()) {
            int sub = prime[j] - prime[i];
            if (sub < N) j++;
            else if (sub >= N) {
                i++;
                if (sub == N) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
