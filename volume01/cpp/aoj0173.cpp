#include <iostream>
#include <string>
using namespace std;

int main ()
{
    int a, b;
    string str;

    while (cin >> str >> a >> b) {
        cout << str << " " << a + b << " " << a * 200 + b * 300 << endl;
    }

    return 0;
}
