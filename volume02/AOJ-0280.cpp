#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        string str;
        cin >> str;

        int sum = 0;
        vector<int> count(N);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'M') count[i % N]++;
            if (str[i] == 'L') count[i % N]+= sum+1, sum = 0;
            if (str[i] == 'S') sum += count[i%N]+1, count[i%N]=0;
        }

        sort(count.begin(), count.end());
        for (auto i : count) cout << i << " ";
        cout << sum << endl;
    }

    return 0;
}
