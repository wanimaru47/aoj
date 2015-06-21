#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    int p[5][5][4];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++ )
            for (int k = 0; k < 4; k++) p[i][j][k] = 0;
    string s;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        for (int j = 0; j < 4; j++) {
            if (s[j] == '1') {
                p[i][j][1] = p[i][j+1][3] = 1;
            }
        }
        cin >> s;
        for (int j = 0; j < 5; j++) {
            if (s[j] == '1') {
                p[i][j][2] = p[i+1][j][0] = 1;
            }
        }
    }
    cin >> s;
    for (int j = 0; j < 4; j++) {
        if (s[j] == '1') {
            p[4][j][1] = p[4][j+1][3] = 1;
        }
    }
/*/////////////////////////////
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++ ) {
            for (int k = 0; k < 4; k++) cout << " " << p[i][j][k];
            cout << endl;
            
        }cout << endl;
    }
    //////////////////////////////*/
    
    
    string DIR = "URDL";
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
    int px = 0, py = 1, dir = 1;
    cout << "R";
    int q = 0;
    while ((px != 0 || py != 0) && q++ < 40) {
        for (int i = 0; i < 4; i++) {
            if (p[px][py][(((dir + 3) % 4) + i) % 4] == 1) {
                //cout << "px: " << px << " py: " << py << " dir: " << ((((dir + 3) % 4) + i) % 4) << endl;
                dir = (((dir + 3) % 4) + i) % 4;
                px += dx[dir];
                py += dy[dir];
                cout << DIR[dir];
                break;
            }
        }
    }
    cout << endl;
    
    return 0;
}
