#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<vec> mat;

const int INF = 1 << 28;
long long int sum;
string num;

int main() {
    while (cin >> sum >> num, sum || num != "0") {
        map<long long int,vec> m;
        long long int target = -1;
        for (int i = 0; i < 1 << (num.size() - 1); i++) {
            long long int tmp = 0;
            int pre = 0;
            for (int j = 0; j < num.size() - 1; j++) {
                if (i & (1 << j)) {
                    string s = string(num.begin() + pre, num.begin() + j + 1);
                    stringstream ss; ss << s;
                    int n; ss >> n;
                    tmp += n;
                    pre = j + 1;
                }
            }

            string s = string(num.begin() + pre, num.end());
            stringstream ss; ss << s;
            int n; ss >> n;
            tmp += n;

            if (tmp <= sum) {
                m[tmp].push_back(i);
                target = max(target, tmp);
            }
        }

        if (m.size() == 0) {
            cout << "error" << endl;
        } else if (m[target].size() == 1) {
            cout << target << " ";
            int tmp = m[target][0];
            for (int i = 0; i < num.size(); i++) {
                cout << num[i];
                if (tmp & (1 << i)) cout << " ";
            }
            cout << endl;
        } else {
            cout << "reject" << endl;
        }
    }
}
