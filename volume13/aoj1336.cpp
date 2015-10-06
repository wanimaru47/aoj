#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main () {
    int N, L;
    cin >> N >> L;
    vec V[2](L);

    for (int i = 0; i < N; i++) { 
        char d; int p;
        cin >> d >> p;
        if (d == 'L') V[1][p] = i;
        else V[0][p] = i;
    }
    
    return 0;
}
