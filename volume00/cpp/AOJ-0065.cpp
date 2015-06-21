#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main ()
{
    string str;
    map<int,int> m;
    while (getline(cin, str)) {
        if (str == "") break;
        stringstream ss;
        for (int i = 0;i < str.size(); i++)
            if (str[i] == ',') str[i] = ' ';
        ss << str;
        int n, d;
        ss >> n >> d;
        m[n]++;
    }

    set<int> v;
    while (getline(cin, str)) {
        if (str == "") break;
        stringstream ss;
        for (int i = 0;i < str.size(); i++)
            if (str[i] == ',') str[i] = ' ';
        ss << str;
        int n, d;
        ss >> n >> d;
        if (m.find(n) != m.end()) {
            v.insert(n);
            m[n]++;
        }
    }

    vector<pair<int,int> > p;
    for (auto& i : v) {
        p.push_back(pair<int,int>(i, m[i]));
    }
    sort(p.begin(), p.end());
    for (int i = 0; i < p.size(); i++) {
        cout << p[i].first << " " << p[i].second << endl;
    }
    
    return 0;
}
