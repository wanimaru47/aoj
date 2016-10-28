#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    long long int sum = 0;
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        sum += c;
    }

    cout << sum / N << endl;

    return 0;
}
