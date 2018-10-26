#include <bits/stdc++.h>
using namespace std;

int main() {
    string g;
    while (cin >> g, g != "#") {
	int y, m, d;
	cin >> y >> m >> d;

	if (g == "HEISEI" && y > 31) {
	    cout << "? " << y - 30 << " " << m << " " << d << endl; 
	} else if (g == "HEISEI" && y == 31 && m >= 5) {
	    cout << "? 1 " << m << " " << d << endl;
	} else {
	    cout << g << " " << y << " " << m << " " << d << endl;
	}
    }

    return 0;
}
