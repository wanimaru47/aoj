#include <iostream>
using namespace std;

int main ()
{
    double MAX, MIN;
    double n;
    cin >> n;
    MAX = MIN = n;
    while (cin >> n) {
        if (MAX < n) {
            MAX = n;
        } else if (MIN > n) {
            MIN = n;
        }
    }
    cout << (MAX - MIN) << endl;
    
    return 0;
}
