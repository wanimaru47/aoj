#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    int count = 0;
    bool ans = true;
    cin >> N;

    while (N--) {
        string s;
        cin >> s;
        if (s == "A") {
            count++;
        } else if (count) {
            count--;
        } else {
            ans = false;
        }
    }

    if (!ans || count) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

    return 0;
}
