#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string str;
    cin >> str;
    int ans = 0;
    while (N--) {
        string old;
        cin >> old;

        bool flag = false;
        for (int i = 0, len = old.size(); i < len; i++) {
            for (int j = 1; i + (j - 1) * ((int)str.size() - 1) + (int)str.size() <= len; j++) {
                bool f = true;
                for (int k = 0, l = str.size(); f && k < l; k++) {
                    if (str[k] != old[i + k * j]) f = false;
                }
                if (f) flag = true;
            }
            if (flag) break;
        }
        if (flag) ans++;
    }
    cout << ans << endl;

    return 0;
}
