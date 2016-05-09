#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    set<int> s;
    vector<int> v(n);
    vector<string> str(n);
    for (auto &i : v) {
        cin >> i;
        s.insert(i);
    }

    for (int i = 0; i < n; i++) {
        str[i] = '0' + v[i];
    }

    for (int i = 0; i < 1000; i++) {
        if (s.size() < pow(10., (double)(i + 1))) break;
        for (int j = 0; j < str.size(); j++) {
            if (n > j + i + 1) 
                str[j] += ('0' + v[j + i + 1]);
            stringstream ss;
            ss << str[j];
            int tmp;
            ss >> tmp;
            s.insert(tmp);
        }
    }

    for (int i = 0; i < 1000000; i++) {
        if (s.find(i) == s.end()) {
            cout << i << endl;
            break;
        }
    }

    return 0;
}
