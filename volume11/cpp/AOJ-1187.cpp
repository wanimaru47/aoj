#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#define MAX_T 50
#define MAX_P 10
using namespace std;

typedef pair<int,int> S;
typedef vector<S> V;
typedef map<int,set<S>> MM;

bool pairCompare(const S& firstElof, const S& secondElof)
{
    return firstElof.second > secondElof.second;
}

int main(void)
{
    int M, T, P, R;
    while (cin >> M >> T >> P >> R) {
        if (M == 0 && T == 0 && P == 0 && R == 0) break;
        int m, t, p, j, data[T + 1][P + 1][2];
        memset(data, 0, sizeof(data));
        for (int i = 0; i < R; i++) {
            cin >> m >> t >> p >> j;
            if (j == 0) {
                data[t][0][0] += (m + data[t][p][1]);
                data[t][0][1]++;
            } else
                data[t][p][1] += 20;
        }
        V v;
        MM mm;
        queue<int> ans;
        for (int i = 1; i <= T; i++) {
            //cout << i << " : " << data[i][0][1] << " : " << data[i][0][0] << endl;
            if (data[i][0][1] == 0) data[i][0][0] = -2;
            mm[data[i][0][1]].insert(S(data[i][0][0],i));
        }
        for (int i = P; i >= 0; i--) {
            stack<int> tmp;
            auto f = mm[i].begin();
            for (auto it = mm[i].begin(); it != mm[i].end(); it++) {
                //cout << "i = " << i << " *f.f = " << (*f).first << " *it.f = " << (*it).first << endl;
                if ((*f).first == (*it).first) tmp.push((*it).second); 
                else {
                    if (ans.size()) ans.push(-1);
                    while (tmp.size()) {
                        advance( f, 1);
                        auto ss = tmp.top(); tmp.pop();
                        //cout << "ss " << ss << endl;
                        ans.push(ss);
                        if (tmp.size()) ans.push(-3);
                    }
                    tmp.push((*it).second);
                    //advance( f, 2);
                    //cout << (*f).first << endl;
                }
            }
            if (tmp.size()) {
                if (ans.size())ans.push(-1);
                while (tmp.size()) {
                    auto ss = tmp.top(); tmp.pop();
                    ans.push(ss);
                    if (tmp.size()) ans.push(-3);
                }
            }
        }
        while (ans.size()) {
            int tmp = ans.front(); ans.pop();
            if (tmp == -1) cout << ",";
            else if (tmp == -3) cout << "=";
            else cout << tmp;
        }
        cout << endl;
        
    }
    
    return 0;
}
