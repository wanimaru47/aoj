#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    int N;
    cin >> str >> N;
    int ans = 0;
    while (N--) {
        string tmp;
        cin >> tmp;

        tmp = tmp + tmp;

        bool flag = false;
        for (int i = 0; i < (int)tmp.size() - (int)str.size() + 1; i++) {
            if (str[0] == tmp[i]) {
                bool check = true;
                for (int j = 0; check && j < (int)str.size(); j++) {
                    if (str[j] != tmp[j + i]) check = false;
                }
                if (check) flag = true;
            }
        }
        if (flag) ans++;
    }

    cout << ans << endl;

    return 0;
}
