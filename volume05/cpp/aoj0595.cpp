#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
using namespace std;

typedef list<int> L;
typedef pair <int,int> P;
typedef vector<int> V;
typedef queue<int> Q;
typedef stack<int> S;
typedef map<string,int> M;

const int MOD = 10007;
const int J = 4, O = 2, I = 1;
string str;
int n, attendA[8], attendB[8];

int changeNumber(char s) {
    if (s == 'J') return J;
    else if (s == 'O') return O;
    else return I;
}

int bfs() {
    Q q;
    q.push(J);
    int res = 0;
    int day = 0;
    attendB[J] = 1;
    while (day < n) {
        //cout << "day = " << day << endl;
        while (q.size()) {
            int befor = q.front(); q.pop();
            //cout << "befor = " << befor << endl;
            for (int i = 1; i < 8; i++) {
                //cout << "当番 = " << (changeNumber(str[day]) & i) << " : 前日の出席状態" << (befor & i) << endl;
                if ((befor & i) && (changeNumber(str[day]) & i))
                    attendA[i] += attendB[befor];
            }
        }
        for (int i = 1; i < 8; i++) {
            attendB[i] = attendA[i];
            if (attendB[i] > 0) q.push(i);
            attendA[i] = 0;
            attendB[i] %= MOD;
        }
        day++;
    }
    for (int i = 1; i < 8; i++)
        res += (attendB[i] % MOD);
    res %= MOD;

    return res;
}

int main()
{
    cin >> n >> str;
    cout << bfs() << endl;
    return 0;
}
