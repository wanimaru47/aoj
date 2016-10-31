#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<P, int> Pc;

int main() {
    int N;
    while (cin >> N, N) {
        vector<Pc> pc;
        for (int i = 0; i < N; i++) {
            int a = 0, b = 0, c;
            char s;
            cin >> s;
            c = (N-i) * 1000 + s;
            for (int j = 0; j < N - 1; j++) {
                int t; cin >> t;
                if (t == 0) a++;
                if (t == 2) b++;
            }

            pc.push_back(Pc(P(a, b), c));
        }

        sort(pc.begin(), pc.end());

        for (int i = 0; i < N; i++)
            cout << (char)(pc[N-1-i].second  % 1000)<< endl;
    }

    return 0;
}
