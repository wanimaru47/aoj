#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> v(8);

    while (cin >> v[0]) {
        for (int i = 1; i < 8; i++) {
            cin >> v[i];
        }

        set<int> used;
        queu<int> next;

        int num = 0;
        for (int i = 0; i < 8; i++) {
            num = num * 10 + (v[i] - '0');
        }
        next.push(num);

        while (next.size()) {
            int now = next.front();
            next.pop();
            char d[2][4];
        }
    }

    return 0;
}
