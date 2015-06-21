#include <iostream>
#include <string>
#include <sstream>
using namespace std;

const int INF = 99999999;
int rot[] = {4, 1, 4, 1, 2, 1, 2, 1};

int main ()
{
    string str;
    while (getline(cin, str)) {
        stringstream ss;
        ss << str;
        int n[8];
        for (int i = 0; i < 8; i++) {
            ss >> n[i];
        }
        int min_c = INF, min_n = INF;
        int res;
        for (int i = 0; i < 8; i++) {
            int c = 0, num = 0, t = 10000000;
            for (int j = 0; j < 8; j++) {
                int k = (i + j) % 8;
                num += t * rot[k];
                t /= 10;
                int tmp = n[k] - rot[k];
                if (tmp > 0) c += tmp;
            }
            if (min_c > c) {
                min_c = c;
                min_n = num;
                res = i;
            } else if (min_c == c && min_n > num) {
                min_n = num;
                res = i;
            }
            cout << c << " " << num << endl;
        }
        for (int i = res; i < res + 7; i++) {
            cout << rot[i % 8] << " ";
        }
        cout << rot[(res + 7) % 8] << endl;
    }
    

    return 0;
}
