#include <iostream>
using namespace std;

int main ()
{
    double w;
    while (cin >> w) {
        if (w <= 48.0) {
            cout << "light fly" << endl;
            continue;
        } else if (w <= 51.0) {
            cout << "fly" << endl;
            continue;
        } else if (w <= 54.0) {
            cout << "bantam" << endl;
            continue;
        } else if (w <= 57.0) {
            cout << "feather" << endl;
        } else if (w <= 60.0) {
            cout << "light" << endl;
            continue;
        } else if (w <= 64.0) {
            cout << "light welter" << endl;
            continue;
        } else if (w <= 69.0) {
            cout << "welter" << endl;
            continue;
        } else if (w <= 75.0) {
            cout << "light middle" << endl;
            continue;
        } else if (w <= 81.0) {
            cout << "middle" << endl;
            continue;
        } else if (w <= 91.0) {
            cout << "light heavy" << endl;
            continue;
        } else cout << "heavy" << endl;
    }

    return 0;
}
