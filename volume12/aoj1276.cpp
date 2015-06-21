#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    vector<bool> num(2222222, true);
    num[0] = num[1] = false;
    vector<int> prim;
    for (int i = 2; i <= 2222222; i++) {
        for (int j = 2; num[i] && j * i <= 2222222; j++) {
            num[i * j] = false;
        }
        if (num[i]) prim.push_back(i);
    }
    int n;
    while (cin >> n, n) {
        auto i = lower_bound(prim.begin(), prim.end(), n) - prim.begin();

        int res = 0;
        if (n < prim[i]) res = prim[i] - prim[i-1];
        if (n > prim[i]) res = prim[i+1] - prim[i];

        //cout << prim[i-1] << " < " << prim[i] << " < " << prim[i+1] << endl;

        cout << res << endl;
    }

    return 0;
}
