#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;
    if (str.size() < 6) {
        cout << "INVALID" << endl;
    } else {
        bool num = false, big= false, small = false;
        for (auto s : str) {
            if ('0' <= s && s <= '9') num = true;
            if ('a' <= s && s <= 'z') small = true;
            if ('A' <= s && s <= 'Z') big = true;
        }

        if (num && big && small) {
            cout << "VALID" << endl;
        } else {
            cout << "INVALID" << endl;
        }
    }

    return 0;
}
