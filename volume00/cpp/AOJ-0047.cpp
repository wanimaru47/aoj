#include <iostream>
#include <string>
#include <map>
using namespace std;

int main ()
{
    string str;
    map<char,int> n;
    n['A'] = 1; n['C'] = n['B'] = 0;
    while (cin >> str) {
        int p = n[str[0]];
        n[str[0]] = n[str[2]];
        n[str[2]] = p;
    }
    for (char i = 'A'; i < 'D'; i++) {
        if (n[i] == 1) {
            cout << i << endl;
            return 0;
        }
    }
}
