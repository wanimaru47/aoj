#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    
    vector<vector<short> > vec(t.size() + 1, vector<short>(26));
    for (int i = 1; i <= t.size(); i++) {
        vec[i][t[i-1] - 'a']++;

        for (int j = 0; j < 26; j++) {
            vec[i][j] += vec[i-1][j];
        }
    }

    vector<vector<short> > v(s.size() + 1, vector<short>(26));
    for (int i = 1; i <= s.size(); i++) {
        v[i][s[i-1] - 'a']++;

        for (int j = 0; j < 26; j++) {
            v[i][j] += v[i-1][j];
        }
    }


    for (int i = s.size(); i > 0; i--) {
        set<vector<short>> sv;
        for (int j = 0; j + i < vec.size(); j++) {
            vector<short> sub(26);
            for (int k = 0; k < 26; k++) {
                sub[k] += vec[i + j][k] - vec[j][k];
            }

            sv.insert(sub);
        }
        
        for (int j = 0; j + i < v.size(); j++) {
            vector<short> sub(26);
            for (int k = 0; k < 26; k++) {
                sub[k] = v[i + j][k] - v[j][k];
            }

            if (sv.find(sub) != sv.end()) {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;

    return 0;
}
