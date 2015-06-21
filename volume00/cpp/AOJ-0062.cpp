#include <iostream>
#include <vector>
using namespace std;

int c (vector<int> v) {
    int n[11][11];
    for (int i = 0; i < 10; i++) {
        n[0][i] = v[i];
    }
    for (int i = 1; i < 10; i++) {
        for (int j = i; j < 10; j++) {
            n[i][j] = (n[i-1][j-1] + n[i-1][j]) % 10;
        }
    }
    
    return n[9][9];
}

int main ()
{
    long long n;
    while (cin >> n) {
        vector<int> v;
        for (int i = 0; i < 10; i++) {
            v.push_back(n % 10);
            n /= 10;
        }
        cout << c(v) << endl;
    }

    return 0;
}
