#include <bits/stdc++.h>
using namespace std;

int N;

void Swap(vector<int> &v, int a, int b) {
    swap(v[a], v[b]);
}

int main() {
    cin >> N;
    vector<int> Rol[4];
    for (int i = 0; i < 4; i++) {
        Rol[i].resize(30);
        for (int j = 0; j < 30; j++) {
            Rol[i][j] = j;
        }
    }

    Swap(Rol[0], 0, 23);
    Swap(Rol[0], 3, 26);
    Swap(Rol[0], 6, 29);
    Swap(Rol[0], 9, 20);
    Swap(Rol[0], 15, 17);

    Swap(Rol[1], 0, 27);
    Swap(Rol[1], 1, 28);
    Swap(Rol[1], 2, 29);
    Swap(Rol[1], 14, 15);
    Swap(Rol[1], 18, 20);

    Swap(Rol[2], 2, 21);
    Swap(Rol[2], 5, 24);
    Swap(Rol[2], 8, 27);
    Swap(Rol[2], 11, 18);
    Swap(Rol[2], 12, 14);

    Swap(Rol[3], 6, 21);
    Swap(Rol[3], 7, 22);
    Swap(Rol[3], 8, 23);
    Swap(Rol[3], 9, 11);
    Swap(Rol[3], 12, 17);

    while (N--) {
        string str;
        for (int i = 0; i < 30; i++) {char c; cin >> c; str += c;}
        string sub = "111111111222444666555333333333";

        queue<pair<int,string> > S;
        S.push(pair<int,string>(0, str));
        while (S.size()) {
            auto s = S.front(); S.pop();
            if (s.second == sub) {
                cout << s.first << endl;
                break;
            }
            else {
                for (int i = 0; i < 4; i++) {
                    string tmp;
                    for (auto j : Rol[i]) {
                        tmp += (s.second)[j];
                    }
                    S.push(pair<int,string>(s.first + 1, tmp));
                }
            }
        }
    }

    return 0;
}
