#include <bits/stdc++.h>
using namespace std;

int main() {
    int sum, sub;
    while (cin >> sum, sum) {
        sub = 0;
        for (int i = 1, j; i < 10; i++) cin >> j, sub += j;
        cout << sum - sub << endl;
    }

    return 0;
}
