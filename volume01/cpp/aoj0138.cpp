#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    vector<vector<pair<double,int> > > v(3, vector<pair<double,int> >(8));
    vector<pair<double,int> > tmp;
    for (auto &t : v) for (auto &i : t) cin >> i.second >> i.first;
    for (int i = 0; i < 3; i++) 
        sort(v[i].begin(), v[i].end());

    for (int i = 0; i < 3; i++) {
        cout << v[i][0].second << " " << v[i][0].first << endl;
        cout << v[i][1].second << " " << v[i][1].first << endl;
        tmp.push_back(v[i][2]);
        tmp.push_back(v[i][3]);
    }

    sort(tmp.begin(), tmp.end());

    for (int i = 0; i < 2; i++) 
        cout << tmp[i].second << " " << tmp[i].first << endl;

    return 0;
}
