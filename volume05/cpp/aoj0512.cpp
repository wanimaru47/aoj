#include <bits/stdc++.h>
using namespace std;

string a = "DEFGHIJKLMNOPQRSTUVWXYZABC";

int main() {
    string str;
    cin >> str;
    for (auto c : str) cout << (char)('A' + a.find(c));
    cout << endl;

    return 0;
}
