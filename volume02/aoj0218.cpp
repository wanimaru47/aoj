#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        for (int i = 0; i < N; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            if (max(max(x, y), z) == 100) {
                cout << "A" << endl;
            }
            else if ((x + y) / 2 >= 90) {
                cout << "A" << endl;
            }
            else if ((x + y + z) / 3 >= 80) {
                cout << "A" << endl;
            }
            else if ((x + y + z) / 3 >= 70) {
                cout << "B" << endl;
            }
            else if ((x + y + z) / 3 >= 50 && max(x, y)>=80) {
                cout << "B" << endl;
            }
            else {
                cout << "C" << endl;
            }
        }
    }

    return 0;
}
