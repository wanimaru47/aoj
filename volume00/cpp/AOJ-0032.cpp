#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    int a, b, c;
    int sq = 0, dy = 0;

    while (scanf("%d,%d,%d", &a, &b, &c) != EOF) {
        if (a == b && a*a + b*b == c*c) {            
        } else if (a != b && a*a + b*b == c*c) {
            sq++;
        } else if (a != b && a*a + b*b != c*c) {
        } else {
            dy++;
        }
    }
    cout << sq << endl << dy << endl;

    return 0;
}
