#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> v;
    v.push_back("ABC");
    v.push_back("DEF");
    v.push_back("GHI");
    for (int c = 0; c < 1000; c++) {
        string str;
        cin >> str;
        int x = 10000, y = 10000;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (v[i][j] == str[0]) x = i, y = j;

        bool flag = true;
        for (int k = 1; k < str.size(); k++) {
            int x_ = 10000, y_ = 10000;
            for (int i = 0; i < 3; i++)
                for (int j = 0; j < 3; j++)
                    if (v[i][j] == str[k]) x_ = i, y_ = j;

            if (abs(x_ - x) == 0 && abs(y_ - y) == 1);
            else if (abs(x_ - x) == 1 && abs(y_ - y) == 0);
            else flag = false;

            x = x_;
            y = y_;
        }

        if (flag) cout << str << endl;
    }

    return 0;
}
