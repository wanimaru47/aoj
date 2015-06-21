#include <iostream>
#include <set>
#include <string>
using namespace std;

int main ()
{
    int n;
    cin >> n;
    set<string> str;
    while (n--) {
        string tmp;
        cin >> tmp;
        str.insert(tmp);
    }

    cin >> n;
    int key = 0;
    while (n--) {
        string tmp;
        cin >> tmp;
        if (str.find(tmp) == str.end()) {
            cout << "Unknown " << tmp << endl;
        } else {
            cout << (key ? "Closed by " : "Opened by ") << tmp << endl;
            key = key ? 0 : 1;
        }
    }

    return 0;
}
