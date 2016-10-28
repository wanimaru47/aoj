#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int N, M;
    while (cin >> N >> M, N || M) {
        int count = 0;
        if (M > N) {
            int tmp = N;
            N = M;
            M = tmp;
        }
        while (M) {
            long long int tmp = N % M;
            N = M;
            M = tmp;
            count++;
        }

        cout << N << " " << count << endl;
    }

    return 0;
}
