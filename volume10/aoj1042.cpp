#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while (getline(cin, str)) {
        if (str == "END OF INPUT") break;
        int count = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') {
                cout << count;
                count = 0;
            } else {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}
