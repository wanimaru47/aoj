#include <bits/stdc++.h>
using namespace std;

int main() {
    int M, N;
    while (cin >> M >> N, N || M) {
        vector<bool> v(7368792);

        int i = M, count = 0;
        while (1) {
            if (!v[i]) {

                if (count == N) {
                    cout << i << endl;
                    break;
                }
                v[i] = true;
                for (int j = 2; j * i < v.size(); j++) {
                    v[i*j] = true;
                }
                count++;
            }
            i++;
        }
    }

    return 0;
}
