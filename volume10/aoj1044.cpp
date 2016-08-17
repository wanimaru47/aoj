#include <bits/stdc++.h>
using namespace std;

int main() {
    string name;
    char type;
    string UP;
    for (int i = 0; i < 26; i++) {
        UP += 'A' + i;
    }

    while (cin >> name >> type) {
        if (type == 'U') {
            stringstream ss;
            for (auto& i : name) if (i == '_') i = ' ';
            ss << name;
            string str;
            while (ss >> str) {
                str[0] = toupper(str[0]);
                cout << str;
            }
            cout << endl;
        } else if (type == 'L') {
            stringstream ss;
            for (auto& i : name) if (i == '_') i = ' ';
            ss << name;
            string str;
            ss >> str;
            str[0] = tolower(str[0]);
            cout << str;
            while (ss >> str) {
                str[0] = toupper(str[0]);
                cout << str;
            }
            cout << endl;
        } else if (type == 'D'){
            for (int i = 0; i < name.size(); i++) {
                if (UP.find(name[i]) != string::npos) {
                    name[i] = name[i] - 'A' + 'a';
                    name.insert(i, " ");
                }
            }
            stringstream ss;
            ss << name;
            string str;
            ss >> str;
            cout << str;
            while (ss >> str) {
                cout << "_" << str;
            }
            cout << endl;
        } else {
            break;
        }
    }

    return 0;
}
