#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <sstream>
#include <queue>
using namespace std;

int main ()
{
    int n;
    while (cin >> n, n) {
        map<string,int> atm;
        for (int i = 0; i < n; i++) {
            int b; string a;
            cin >> a >> b;
            atm[a] = b;
        }
        int m;  cin >> m;
        map<string, queue<string> > rcp;
        for (int i = 0; i < m; i++) {
            string str; int t;
            cin >> str >> t;
            queue<string> q;
            int r_cost = 0;
            for (int j = 0; j < t; j++) {
                string s; cin >> s;
                r_cost += atm[s];
                q.push(s);
            }
            if (atm.find(str) != atm.end()) atm[str] = min(atm[str], r_cost);
            else atm[str] = r_cost;
            rcp[str] = q;
        }
        string pro; cin >> pro;
        if (rcp.find(pro) == rcp.end()) cout << atm[pro] << endl; 
        else {
            int res = 0;
            while (!rcp[pro].empty()) {
                string s = rcp[pro].front(); rcp[pro].pop();
                res += atm[s];
            }
            cout << (min(atm[pro], res)) << endl;
        }
    }

    return 0;
}
