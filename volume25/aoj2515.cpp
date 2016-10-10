#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, T;
    cin >> N >> T;

    vector<string> vs;
    vector<int> vi;

    int sh, sm, eh, em;
    char c;
    string st, sr;

    cin >> sh >> c >> sm >> st >> eh >> c >> em >> sr;

    for (int i = 1; i < N; i++) {
        int times = eh * 60 + em;
        cin >> sh >> c >> sm >> st >> eh >> c >> em >> sr;
        int timee = sh * 60 + sm;

        if (timee - times >= T) {
            vs.push_back(st);
            vi.push_back(timee - times);
        }
    }

    cout << vs.size() << endl;
    for (int i = 0; i < (int)vs.size(); i++) {
        cout << vs[i] << " " << vi[i] << endl;
    }

    return 0;
}
