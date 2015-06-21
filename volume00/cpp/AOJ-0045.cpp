#include <cstdio>
#include <iostream>
using namespace std;

int main ()
{
    int n1, n2, sum = 0, count = 0;
    double t = 0;
    while(scanf("%d,%d", &n1, &n2) != EOF) {
        sum += n1 * n2;
        t += (double)n2;
        count++;
    }
    int avg = t / (double)count;
    avg = (t / (double)count) - avg >= 0.5 ? avg + 1 : avg;
    cout << sum << endl << avg << endl;
    

    return 0;
}
