#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int n, p;
    vector<bool> num(1000001, true);
    vector<int> prim;
    num[0] = num[1] = false;
    for (int i = 2; i <= 1000000; i++) {
        for (int j = 2; num[i] && i * j <= 1000000; j++) {
            num[i * j] = false;
        }
        if (num[i]) prim.push_back(i);
    }

    while (cin >> n >> p, !(n < 0 || p < 0)) {
        vector<int> v;
        int s = upper_bound(prim.begin(), prim.end(), n) - prim.begin();
        if (prim[s] <= n) s++; 
        for (int i = 0; i <= p; i++) {
            for (int j = i; j <= p; j++) {
                v.push_back((prim[s + i] + prim[s + j]));
            }
        }

        sort(v.begin(), v.end());
        cout << v[p-1] << endl;
    }

    return 0;
}
