#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;
    cin >> str;

    string vs;
    vector<int> vi;

    vs += str[0];
    vi.push_back(1);
    for (int i = 1; i < str.size(); i++) {
        if (vs[vs.size()-1] == str[i]) {
            vi[vi.size()-1]++;
        } else {
            vs += str[i];
            vi.push_back(1);
        }
    }

    int ans = 0;
    for (int i = 0; i + 2 < vs.size(); i++) {
        if (vs[i] == 'J' && vs[i+1] == 'O' && vs[i+2] == 'I'
            && vi[i] >= vi[i+1] && vi[i+1] <= vi[i+2]) {
            ans = max(ans, vi[i+1]);
        }
    }

    cout << ans << endl;

    return 0;
}
