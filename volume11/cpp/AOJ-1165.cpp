#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int,int> P;

int main()
{
    int n;
    while (cin >> n, n) {
        vector<P> v;
        v.push_back(P(0, 0));
        int R = 0, L = 0, T = 0, B = 0;
        for (int i = 1; i < n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            int x = v[t1].first, y = v[t1].second;
            if (t2 == 0) y--;
            else if (t2 == 1) x--;
            else if (t2 == 2) y++;
            else if (t2 == 3) x++;
            v.push_back(P(x, y));
            if (x > T) T = x;
            else if (x < B) B = x;
            else if (y > R) R = y;
            else if (y < L) L = y;
        }
        cout << (R - L + 1) << " " << (T - B + 1) << endl;
    }

    return 0;
}
