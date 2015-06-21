#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string str;
    char m[3][3];
    while (cin >> str) {
        for (int i = 0; i < 9; i++) {
            m[i / 3][i % 3] = str[i];
        }
        
        for (int i = 0; i < 3; i++) {
            if (m[i][0] != 's' && m[i][0] == m[i][1] && m[i][0] == m[i][2]) {
                cout << m[i][0] << endl;
                goto escape;
            }
            if (m[0][i] != 's' && m[0][i] == m[1][i] && m[2][i] == m[0][i]) {
                cout << m[0][i] << endl;
                goto escape;
            }
        }
        if (m[0][0] != 's' && m[0][0] == m[1][1] && m[2][2] == m[0][0]) {
            cout << m[0][0] << endl;
            goto escape;
        }
        if (m[2][0] != 's' && m[2][0] == m[1][1] && m[0][2] == m[2][0]) {
            cout << m[2][0] << endl;
            goto escape;
        }
        cout << "d" << endl;
    escape:;
    }
    

    return 0;
}
