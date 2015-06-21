#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int is_number(char c) {
    int res = c - '0';
    if (0 <= res && res < 10) return res;
    else return -1;
}

int main ()
{
    string str;
    int res = 0;
    while (cin >> str) {
        int i = 0;
        while (i < str.size()) {
            int tmp = 0;
            int sum = 0;
            while (i < str.size() && (tmp = is_number(str[i])) >= 0) {
                sum = sum * 10 + tmp;
                i++;
            }
            if (sum == 0) i++;
            res += sum;
        }
    }
    cout << res << endl;

    return 0;
}
