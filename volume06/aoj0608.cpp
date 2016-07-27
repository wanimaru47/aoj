#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B, C, D, P;
    cin >> A >> B >> C >> D >> P;
    if (P * A <= (B + max(P - C, 0) * D)) cout << P * A << endl;
    else cout << (B + max(P - C, 0) * D) << endl;

    return 0;
}
