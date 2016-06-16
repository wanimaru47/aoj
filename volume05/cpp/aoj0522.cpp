#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    while (cin >> str) {
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < (int)str.size() - 2; i++) {
            if (str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I') count1++;
            if (str[i] == 'J' && str[i+1] == 'O' && str[i+2] == 'I') count2++;
        }
        cout << count2 << endl << count1 << endl;
    }

    return 0;
}
