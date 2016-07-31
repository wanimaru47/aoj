#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v(5);
    while (cin >> v[0], v[0]) {
        bool g = false, c = false, p = false;
        for (int i = 1; i < 5; i++) cin >> v[i];

        for (auto i : v) {
            if (i == 1) g = true;
            if (i == 2) c = true;
            if (i == 3) p = true;
        }

        if ((g&&c&&p)||(g&&!c&&!p)||(!g&&c&&!p)||(!g&&!c&&p)) {
            for (int i = 0; i < 5; i++) cout << 3 << endl;
        } else if (g && c && !p) {
            for (auto i : v) {
                if (i == 1) cout << 1 << endl;
                else cout << 2 << endl;
            }
        } else if (g && !c && p) {
            for (auto i : v) {
                if (i == 3) cout << 1 << endl;
                else cout << 2 << endl;
            }
        } else if (!g && c && p) {
            for (auto i : v) {
                if (i == 2) cout << 1 << endl;
                else cout << 2 << endl;
            }
        }
    }

    return 0;
}
