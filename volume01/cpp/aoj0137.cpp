#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main ()
{
    int count;
    cin >> count;

    for (int x = 1; x <= count; x++) {
        long long  n;
        cin >> n;
        stringstream ss;
        ss << n;
        cout << "Case " << x << ":" << endl;
        for (int i = 0; i < 10; i++) {
            n *= n;
            n /= 100;
            int j = 0;
            int k = 1;
            int tmp = 0;
            while (j < 4) {
                tmp += (n % 10) * k;
                k *= 10;
                n /= 10;
                j++;
            }
            n =  tmp;
            cout << tmp << endl;
        }
    }

    return 0;
}
