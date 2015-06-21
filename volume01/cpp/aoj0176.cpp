#include <iostream>
#include <string>
#include <cmath>
using namespace std;

const int INF = 1 << 28;

int to_hex (char a) {
    if ('0' <= a && a <= '9') return a - '0';
    else return a - 'a' + 10;                              
}

int main ()
{
    int R[] = {0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xff};
    int G[] = {0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0xff, 0xff};
    int B[] = {0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff};
    string color[] = {"black", "blue", "lime", "aqua", "red", "fuchsia", "yellow", "white"};

    string str;
    while (cin >> str, str != "0") {
        int r = to_hex(str[1]) * 16 + to_hex(str[2]);
        int g = to_hex(str[3]) * 16 + to_hex(str[4]);
        int b = to_hex(str[5]) * 16 + to_hex(str[6]);

        int D = INF;
        string res;
        for (int i = 0; i < 8; i++) {
            int d = ((R[i] - r) * (R[i] - r) + (G[i] - g) * (G[i] - g) + (B[i] - b) * (B[i] - b));
            // cout << "> " << d << endl;
            if (d < D) {
                res = color[i];
                D = d;
            }
        }
        cout << res << endl;
    }

    return 0;
}
