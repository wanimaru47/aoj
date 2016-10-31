#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int M;
        cin >> M;
        string str;
        cin >> str;
        vector<string> vs;
        string v;
        for (int i = 0; i + 2 < M; i += 2) {
            if (str[i] == 'I' && str[i+1] == 'O' && str[i+2] == 'I') {
                v += "IO";
            } else {
                i-=1;
                if (v.size()) {
                    vs.push_back(v + "I");
                }

                v = "";
            }
        }

        if (v.size()) {
            vs.push_back(v + "I");
        }

        int ans = 0;
        for (int i = 0; i < vs.size(); i++) {
            ans += max((int)vs[i].size()/2-(N-1), 0);
        }

        cout << ans << endl;
    }

    return 0;
}
