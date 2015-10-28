#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main() {
    int t; cin >> t;
    vec times(t), timee(t), count(t);
    for(int i = 0; i < t; i++) {
        int h1, m1, h2, m2;
        char c;
        cin >> h1 >> c >> m1 >> c >> h2 >> c >> m2;
        times[i] = h1 * 60 + m1;
        timee[i] = h2 * 60 + m2;
    }

    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int s; cin >> s;
        for(int k = 0; k < s; k++) {
            int h1, m1, h2, m2;
            char c;
            cin >> h1 >> c >> m1 >> c >> h2 >> c >> m2;
            int teachers = h1 * 60 + m1;
            int teachere = h2 * 60 + m2;
            for(int j = 0; j < t; j++) {
                if(teachers <= times[j] && timee[j] <= teachere) {
                    count[j]++;
                }
            }
        }
    }

    int m; cin >> m;
    int res = 0;
    for(int i = 0; i < m; i++) {
        int s; cin >> s;
        for(int k = 0; k < s; k++) {
            int h1, m1, h2, m2;
            char c;
            cin >> h1 >> c >> m1 >> c >> h2 >> c >> m2;
            int students = h1 * 60 + m1;
            int studente = h2 * 60 + m2;
            for(int j = 0; j < t; j++) {
                if(students <= times[j] && timee[j] <= studente) {
                    if(count[j]) res++, count[j]--;
                }
            }
        }
    }

    cout << res << endl;
    
    return 0;
}
