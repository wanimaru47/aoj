#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define INF 999999999
using namespace std;

int n, q;

int main ()
{
    cin >> n;
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    int sp = sqrt(n), cl = 0;
    while (cl + sp < n) {
        sort(a.begin() + cl, a.begin() + cl + sp);
        cl += sp;
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, d;
        cin >> l >> r >> d;

        int res = INF;
        //線形探索
        cl = l + (l % sp);
        if (cl != l) {
            if (sp % 2 != 0) cl = l + ((l + 1) % sp);
            for (int i = l; 0 < i % sp && i <= r; i++)
                res = res > abs(d - b[i]) ? abs(d - b[i]) : res;
        }
        //二分探索
//        cout << cl << endl;
        while (cl + sp < r) {
            int lb = cl, ub = cl + sp - 1;
            while (ub - lb > 1) {
                int mid = (ub + lb) / 2;
                if (a[mid] <= d) {
                    lb = mid;
                } else {
                    ub = mid;
                }
            }
//            cout << l << endl;
            res = min(res, min(abs(d - a[ub]), abs(d - a[lb])));
            cl += sp;
        }
        //線形探索
        for (int i = cl; i <= r; i++) 
            res = res > abs(d - b[i]) ? abs(d - b[i]) : res;
        cout << res << endl;
    }

    return 0;
}
