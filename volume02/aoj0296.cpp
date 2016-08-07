#include <bits/stdc++.h>
using namespace std;

int main () {
    int d[] = {1,5,10,50,100,500};
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        int x;
        cin >> x;
        sum += d[i] * x;
    }
    if (sum >= 1000) cout << 1 << endl;
    else cout << 0 << endl;

    return 0;
}
