#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;

int main ()
{
    int m, n;
    while (cin >> n >> m, (n || m)) {
        map<string,P> v;
        for (int i = 0; i < n; i++) {
            string str;
            int s, e;
            cin >> str >> s >> e;
            v[str] = P(s,e);
        }

        for (int i = 0; i < m; i++) {
            int y;
            cin >> y;

            bool flag = true;
            for (auto i : v) {
                if (i.second.second - i.second.first < y && y <= i.second.second) {
                    cout << i.first << " " << y - i.second.second + i.second.first << endl;
                    flag = false;
                    break;
                }
            }
            if (flag) cout << "Unknown" << endl;
        }
    }

    return 0;
}
