#include <bits/stdc++.h>
using namespace std;

int main() {
    string str;

    vector<string> button{" ",
            "',.!?",
            "abcABC",
            "defDEF",
            "ghiGHI",
            "jklJKL",
            "mnoMNO",
            "pqrsPQRS",
            "tuvTUV",
            "wxyzWXYZ"};

    while (getline(cin,str)) {
        if (str == "") {
            cout << endl;
            continue;
        }
        string seq;
        vector<int> count;
        seq += str[0];
        count.push_back(1);
        for (int i = 1; i < str.size(); i++) {
            if (seq[seq.size()-1] == str[i]) {
                count[count.size()-1]++;
            } else {
                if (str[i] == '0') i++;
                seq += str[i];
                count.push_back(1);
            }
        }

        string ret;
        for (int i = 0; i < seq.size(); i++) {
            int b = seq[i] - '0';
            int c = (count[i]-1) % (int)(button[b].size()); 
            if (b == 0)
                for (int j = 0; j < count[i]; j++) ret += ' ';
            else
                ret += button[b][c];
        }
        cout << ret << endl;
    }

    return 0;
}
