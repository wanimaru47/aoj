#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main () {
    int N, L;
    cin >> N >> L;
    vec V(L + 2);

    for (int i = 0; i < N; i++) { 
        char d; int p;
        cin >> d >> p;
        if (d == 'L') V[p] = -1;
        else V[p] = 1;
    }
    
    return 0;
}
