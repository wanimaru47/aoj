#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> len;
    len.push_back(60);
    for (int i = 0; i < 5; i++) {
        len.push_back(len[i] + 20);
    }

    vector<int> widht;
    widht.push_back(2);
    widht.push_back(5);
    for (int i = 2; i <= 5; i++) {
        widht.push_back(widht[1] * i);
    }

    vector<int> price;
    price.push_back(600);
    for (int i = 0; i < 5; i++) {
        price.push_back(price[i] + 200);
    }

    int N;
    while (cin >> N, N) {
        int sum  = 0;
        for (int i = 0; i < N; i++) {
            int x, y, z, d;
            cin >> x >> y >> z >> d;

            for (int j = 0; j < 6; j++) {
                if (len[j] >= x + y + z && widht[j] >= d) {
                    sum += price[j];
                    break;
                }
            }
        }

        cout << sum << endl;
    }

    return 0;
}
