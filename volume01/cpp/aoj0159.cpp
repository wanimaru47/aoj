#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int id = 1000000000;
        double bmi = 2000.0;
        for (int i = 0; i < N; i++) {
            int d;
            double h, w;
            cin >> d >> h >> w;
            h /= 100.0;

            if (bmi > abs(22.0 - (w / (h * h)))) {
                id = d;
                bmi = abs(22.0 - (w / (h * h)));
            } else if (bmi == abs(22.0 - (w / (h * h)))) {
                id = min(d, id);
            }
        }

        cout << id << endl;
    }

    return 0;
}
