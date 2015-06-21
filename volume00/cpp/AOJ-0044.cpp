#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

int main ()
{
    vector<int> num(MAX + 1, 1);
    num[0] = num[1] = -1;
    for (int i = 2; i <= MAX / 2; i++) {
        for (int j = 2; i * j <= MAX; j++) {
            num[i*j] = -1;
        }
    }

    vector<int> prim;
    for (int i = 0; i < num.size(); i++) {
        if (num[i] == 1) {
            prim.push_back(i);
        }
        num[i] = prim.size() - 1;        
    }

    int n;
    while (cin >> n) {
        if (prim[num[n]] == n) 
            cout << prim[num[n]-1] << " " << prim[num[n]+1] << endl;
        else
            cout << prim[num[n]] << " " << prim[num[n]+1] << endl;
    }

    return 0;
}
