#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int start = -1;
    int res = -1;
    int i = 0;
    while(start) {
        start = (a * i + b * i);
        int end = (a * (i + 1) + b * i);
        int c_ = c + (start / 60) * 60;

        if(start <= c_ && c_ <= end) {
            res = c_;
            break;
        }

        i++;
        start = (a * i + b * i) % 60;
    }
    
    cout << (res < 0 ? -1 : res) << endl;

    return 0;
}
