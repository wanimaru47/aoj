#include <bits/stdc++.h>
using namespace std;

int main() {
    while (1) {
        string s1, s2, s3;
        cin >> s1;
        if (s1 == "0") break;
        cin >> s2 >> s3;
        int a = 0, b = 0;
        for (int i = 1; i < s1.size(); i++) {
            if (s1[i] == 'A') a++;
            else b++;
        }
        if (s2[0] == 'A') a++;
        else b++;
        cout << a << " " << b << endl;
        a = 0, b = 0;
        for (int i = 1; i < s2.size(); i++) {
            if (s2[i] == 'A') a++;
            else b++;
        }
        if (s3[0] == 'A') a++;
        else b++;
        cout << a << " " << b << endl;
        a = 0, b = 0;
        for (int i = 1; i < s3.size(); i++) {
            if (s3[i] == 'A') a++;
            else b++;
        }
        if (a < b) b++;
        else a++;
        cout << a << " " << b << endl;
    }

    return 0;
}
