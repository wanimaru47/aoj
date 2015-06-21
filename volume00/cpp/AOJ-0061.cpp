#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;

int main ()
{
    map<int,int> m;
    set<int> s;
    int a, b;
    while (scanf("%d,%d", &a, &b), (a | b)) {
        m[a] = b;
        s.insert(b);
    }
    vector<int> v;
    while (cin >> a) {
        v.push_back(a);
    }
    //sort(s.begin(), s.end());
    for (int i = 0; i < v.size(); i++) {
        int j = 0;
        for (auto it = s.begin(); it != s.end(); it++) {
            j++;
            if (*it == m[v[i]]) {
                cout << (s.size()-j+1) << endl;
                break;
            }
        }
    }

    return 0;
}
