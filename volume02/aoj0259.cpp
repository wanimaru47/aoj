#include <bits/stdc++.h>
using namespace std;

int main () {
    string str;
    while (cin >> str) {
        bool f = false;
        for (auto i : str) if (i != '0') f = true;

        if (!f) break;

        f = false;
        for (auto i : str) if (i != str[0]) f = true;

        if (!f) {
            cout << "NA" << endl;
            continue;
        }

        int count = 0;
        int now;
        stringstream org;
        org << str;
        org >> now;
        while (1) {
            if (now == 6174) {
                cout << count << endl;
                break;
            }
            count++;
            sort(str.begin(), str.end());
            auto rstr = str;
            reverse(rstr.begin(), rstr.end());

            stringstream ss;
            ss << rstr << " " << str;
            int A, B;
            ss >> A >> B;
            now = A - B;
            stringstream next;
            next << now;
            next >> str;
            while (str.size() < 4) str = "0" + str;
        }
    }

    return 0;
}
