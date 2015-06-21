#include <iostream>
using namespace std;

int main ()
{
    int n;
    while (cin >> n, n != -1) {
        long long res = 0;
        long long pos = 1;
        while (n > 0) {
            res += pos * (n & 0b0011);
            n = n >> 2;
            pos *= 10;
        }
        cout << res << endl;
    }

    return 0;
}
