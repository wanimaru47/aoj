#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

typedef map<int,long long> M;
typedef queue<int> P;

int N[4000];

int main()
{
    int count;
    while (cin >> count, count > 0) {
        M m;
        int t = 1;
        P p;
        for (int i = 0; i < count; i++) {
            int t1;
            long long t2, t3;
            cin >> t1 >> t2 >> t3;
            if (N[t1 - 1] == 0) {
                N[t1 - 1] = t;
                t++;
                p.push(t1);
                m[t1] = 0;
            }
            m[t1] += t2 * t3;
        }

        bool flag = true;
        while (p.size()) {
            t = p.front(); p.pop();
            if (m[t] >= 1000000) {
                cout << t << endl;
                flag = false;
            }
            N[t - 1] = 0;
        }
        if (flag)
            cout << "NA" << endl;
    }

    return 0;
}
