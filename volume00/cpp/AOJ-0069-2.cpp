#include <iostream>
#include <string>
#include <vector>
using namespace std;

int N, M, G, D;

int main ()
{
    while (cin >> N, N) {
        cin >> M >> G >> D;
        vector<string> m(D+1, "00000000000");
        for (int i = 0; i < D; i++) {
            cin >> m[i];
        }

        int d[D+1][N];
        int y = M - 1;

        for (int i = 0; i < D + 1; i++)
            for (int j = 0; j < N; j++) d[i][j] = 0;
        
        for (int x = 0; x < D+1; x++) {
            if (y < N-1 && m[x][y] == '1') {
                d[x][y] = 7;
                y++;
                d[x][y] = 7;
                //cout << "R" << endl;
            } else if (0 < y && m[x][y-1] == '1') {
                d[x][y] = 7;
                y--;
                d[x][y] = 7;
                //cout << "L" << endl;
            } else {
                d[x][y] = 6;
                //cout << "S" << endl;
            }
        }
        if (y == G - 1) {
            cout << 0 << endl;
            continue;
        }
        
        y = G - 1;
        int rx = -1, ry = -1;
        for (int x = D - 1; x >= 0; x--) {
            if (y < N-1 && m[x][y] == '1') {
                d[x][y++]++;
                d[x][y]++;
            } else if (0 < y && m[x][y-1] == '1') {
                d[x][y--]++;
                d[x][y]++;
            } else {
                d[x][y]++;
                if (0 < y && d[x][y-1] == 6) {
                    rx = x+1;
                    ry = y;
                } else if (y < N-1 && d[x][y] == 6) {
                    rx = x+1;
                    ry = y+1;
                }
            }
        }
/*
        for (int i = 0; i <= D; i++) {
            for (int j = 0; j < N; j++) {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
*/
        if (rx >= 0) {
            cout << rx << " " << ry << endl;
        } else cout << 1 << endl;
    }

    return 0;
}
