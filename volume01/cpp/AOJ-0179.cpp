#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

typedef pair<string,int> P;
typedef map<string,int> M;

int dfs(string str) {
    queue<P> s;
    s.push(P(str,0));
    int res = -1;
    M m;

    while (s.size()) {
        P p = s.front(); s.pop();
        str = p.first;
        if (m[str]) continue;
        int num = p.second;
        m[str] = num;
        bool f = true;
        int count = 0;
        for (int i = 0; i < str.size() - 1; i++) {
            string tmp = str;
            bool flag = false;
            if (tmp[i] != tmp[i + 1]) {
                flag = true;
                f = false;
                count++;
                if (tmp[i] != 'b' && tmp[i + 1] != 'b')
                    tmp[i + 1] = tmp[i] = 'b';
                else if (tmp[i] != 'r' && tmp[i + 1] != 'r')
                    tmp[i + 1] = tmp[i] = 'r';
                else if (tmp[i] != 'g' && tmp[i + 1] != 'g')
                    tmp[i + 1] = tmp[i] = 'g';
                if (tmp == str) flag = false;
            }
            if (flag) s.push(P(tmp, num + 1));
        }
        if (f) {
            res = num;
            break;
        }

    }

    return res;
}

int main()
{
    string str;
    while (cin >> str) {
        if (str == "0") break;
        int res = dfs(str);
        if (res < 0) cout << "NA" << endl;
        else cout << res << endl;
    }


    return 0;
}
