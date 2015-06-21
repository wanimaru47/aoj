#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, G, D;

bool c (vector<string> m) {
    int y = M - 1;
    for (int x = 0; x < D; x++) {
        if (y < N-1 && m[x][y] == '1') {
            y++;
        } else if (0 < y && m[x][y-1] == '1') {
            y--;
        }
    }
    if (y == G-1) return true;
    else return false;
}

bool t (string g) {
    for (int i = 0; i < g.size() - 1; i++) {
        if (g[i] == '1' && g[i+1] == '1') return false;
    }
    return true;
}

int main ()
{
    while  (cin >> N, N) {
        cin >> M >> G >> D;
        vector<string> v (D);
        for (int i = 0; i < D; i++) {
            cin >> v[i];
        }
        if (c(v)) {
            cout << 0 << endl;
            goto escape;
        }
        for (int i = 0; i < D; i++) {
            for (int j = 0; j < N-1; j++) {
                if (v[i][j] != '1') {
                    v[i][j] = '1';
                    if (t(v[i])) {
                        if(c(v)) {
                            cout << i+1 << " " << j+1 << endl;
                            goto escape;
                        };
                    }
                    v[i][j] = '0';
                }
            }
        }
        cout << 1 << endl;
    escape:;
    }
    
    return 0;
}
