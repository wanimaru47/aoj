#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> d(8);
    for (auto& i : d) cin >> i;

    cout << 90 << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << d[7-j][i];
        }
        cout << endl;
    }

    cout << 180 << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << d[7 - i][7 - j];
        }
        cout << endl;
    }

    cout << 270 << endl;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << d[j][7-i];
        }
        cout << endl;
    }

    return 0;
}
