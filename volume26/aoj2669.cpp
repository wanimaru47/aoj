#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    bool f = true, c = false;
    for(int i = 0; i < str.size(); i++) {
        if(f && str[i] == 'A') f = false;
        else if(!f && str[i] == 'Z') {
            f = true;
            cout << "AZ";
            c = true;
        }
    }
    cout << (!c ? "-1\n" : "\n");

    return 0;
}
