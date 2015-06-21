#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 1000000;
const int MAX_N = 10000;

int main ()
{
    vector<bool> v(MAX + 1, true);
    vector<int> prim_sum;
    prim_sum.push_back(0);
    v[0] = v[1] = false;
    int i = 2;
    while (prim_sum.size() <= 10000) {
        if (v[i]) {
            prim_sum.push_back(i);
            for (int j = 2; i * j<= MAX; j++) {
                v[i * j] = false;
            }
            prim_sum[prim_sum.size()-1] += prim_sum[prim_sum.size()-2]; 
        }
        i++;
    }
    
    int n;
    while (cin >> n, n) {
        cout << prim_sum[n] << endl;
    }

    return 0;
}
