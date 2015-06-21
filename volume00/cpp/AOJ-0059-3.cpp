#include <iostream>
using namespace std;

int main ()
{
    double ax1, ax2, ay1, ay2, bx1, bx2, by1, by2;
    while (cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2)
    {
        if (ax1 <= bx2 && by1 <= ay2 && bx1 <= ax2 && ay1 <= by2)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
