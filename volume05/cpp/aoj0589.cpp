#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<map<string,int> > dec(5);
    for (int i = 0; i < N; i++) {
        string str;
        int n;
        cin >> str >> n;
        dec[str.size()-1][str] += n;
    }

    for (auto i : dec) {
        for (auto j : i) {
            cout << j.first << " " << j.second << endl;
        }
    }

    return 0;
}
