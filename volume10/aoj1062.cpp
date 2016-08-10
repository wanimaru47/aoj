#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        vector<int> order(N), serv(N);
        for (int i = 0; i < N; i++) {
            char c;
            int hh, mm;
            cin >> hh >> c >> mm >> serv[i];
            if (hh < 3) hh += 24;
            order[i] = 60 * hh + mm;
            if (mm > serv[i]) {
                int count = 0;
                while ((mm + count) % 60 != serv[i]) count++;
                serv[i] = count;
            } else {
                serv[i] = serv[i] - mm;
            }
        }

        int Ls = 11 * 60;
        int Le = 15 * 60;
        int Ds = 18 * 60;
        int De = 21 * 60;
        int Ms = 21 * 60;
        int Me = 26 * 60;
        int Lt, Lf, Dt, Df, Mt, Mf;
        Lt = Lf = Dt = Df = Mt = Mf = 0;

        for (int i = 0; i < N; i++) {
            if (Ls <= order[i] && order[i] < Le) {
                if (serv[i] <= 8) Lt++;
                else Lf++;
            }
            if (Ds <= order[i] && order[i] < De) {
                if (serv[i] <= 8) Dt++;
                else Df++;
            }
            if (Ms <= order[i] && order[i] < Me) {
                if (serv[i] <= 8) Mt++;
                else Mf++;
            }
        }

        cout << "lunch ";
        if (Lt + Lf)
            cout << (int)(100 * (double)(Lt) / (Lt + Lf)) << endl;
        else cout << "no guest" << endl;
        cout << "dinner ";
        if (Dt + Df)
            cout << (int)(100 * (double)(Dt) / (Dt + Df)) << endl;
        else cout << "no guest" << endl;
        cout << "midnight ";
        if (Mt + Mf)
            cout << (int)(100 * (double)(Mt) / (Mt + Mf)) << endl;
        else cout << "no guest" << endl;
    }

    return 0;
}
