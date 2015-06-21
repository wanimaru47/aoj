#include <bits/stdc++.h>
using namespace std;

int main ()
{
    vector<bool> num(100000, true);
    num[0] = num[1] = false;
    for (int i = 2; i < num.size() / 2; i++) {
        for (int j = 2; j * i <= num.size(); j++) {
            num[i * j] = false;
        }
    }
    vector<int> prim;
    for (int i = 0; i < num.size(); i++) {
        if (num[i]) prim.push_back(i);
    }
    
    
    int m, a, b;
    while (cin >> m >> a >> b, (m || a || b)) {
        int r = 0;
        int l = 0;
        for (int i = 0; i < prim.size() && prim[i] < m; i++) {
            for (int j = 0; j <= i; j++) {
                if (prim[i] * prim[j] > m) break; 
                if (l * r < prim[i] * prim[j] && (double)a / b <= (double)prim[j] / prim[i]) {
                    l = prim[j];
                    r = prim[i];
                }
            }
        }

        cout << l << " " << r << endl;
    }
    
    return 0;
}
