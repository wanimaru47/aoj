#include <bits/stdc++.h>
using namespace std;

int pm(int y, int m) {
    int sum = 0;
    int s[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 0; i < m - 1; i++) {
        sum += s[i];
        if (i == 1 && y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)) sum += 1;
    }
    return sum;
}

int main() {
    int y1,y2,m1,m2,d1,d2;
    while (cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2,
           y1 > -1 && y2 > -1 && m1 > -1 && m2 > -1 && d1 > -1 && d2 > -1) {
        y1--;
        int t1 = y1 * 365 + (y1 / 400) - (y1 / 100) + (y1 / 4);
        y1++;
        t1 += d1;
        t1 += pm(y1, m1);

        y2--;
        int t2 = y2 * 365 + (y2 / 400) - (y2 / 100) + (y2 / 4);
        y2++;
        t2 += d2;
        t2 += pm(y2, m2);

        cout << t2 - t1 << endl;
    }

    return 0;
}
