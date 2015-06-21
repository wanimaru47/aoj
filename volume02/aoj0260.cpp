#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int main ()
{
    int n;
    while (cin >> n, n) {
        long long res = 0;
        vector<int> j;

        int t;
        for (int i = 0; i < n; i++) { cin >> t; res += t;}
        for (int i = 0; i < n - 1; i++) { cin >> t; j.push_back(t);}

        sort(j.begin(), j.end(), greater<int>());

        long long tmp = 0;
        tmp = res;
        res *= n;
        for (int i = 1; i < n; i++) {
            tmp = tmp + j[i - 1];
            res = max(res, tmp * (n - i));
        }
        cout << res << endl;
    }

    return 0;
}

