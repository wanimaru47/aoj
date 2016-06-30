#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int n; cin >> n;
        sum += max(40, n);
    }

    cout << sum / 5 << endl;

    return 0;
}
