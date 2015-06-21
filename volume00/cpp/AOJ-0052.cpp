#include <iostream>
using namespace std;

int main ()
{
    int t;
    while (cin >> t, t) {
        int res = 0;
        for (int i = 5; i <= t; i *= 5) {
            res += t / i;
        }
        cout << res << endl;
    }
    
    return 0;
}
