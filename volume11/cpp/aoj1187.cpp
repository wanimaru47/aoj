#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
#include <algorithm>
#include <functional>
#include <list>
#include <stack>
#include <queue>
using namespace std;

typedef list<int> L;
typedef vector<int> V;
typedef queue<int> Q;
typedef stack<int> S;

struct Team {
    int t;
    int p;
    int time;
    int m[11];
};

bool cmp (const Team& p1, const Team& p2) {
    return p1.p > p2.p;
}

bool cmp2 (const Team& p1, const Team& p2) {
    return p1.time < p2.time;
}

int main()
{
    int M, T, P, R;
    while (cin >> M >> T >> P >> R, M) {
        vector<Team> team(T, Team {0});
        for (int i = 1; i <= T; i++)
            team[i - 1].t = i;
        for (int i = 0; i < R; i++) {
            int t1, t2, t3, t4;
            cin >> t1 >> t2 >> t3 >> t4;
            if (t4 == 0) {
                team[t2 - 1].p++;
                team[t2 - 1].time += t1 + team[t2 - 1].m[t3] + 20;
            } else {
                team[t2 - 1].m[t3] += 20;
            }
        }

        sort(team.begin(), team.end(), cmp);
        cout << "OK" << endl;
        for (int i = 0; i <= T; i++) {
            int start = i;
            vector<pair<int,int> > tmp;
            while (team[start].p == team[i].p) {
                tmp.push_back(pair<int,int>(team[i].time, team[i].t));
                i++;
            }
            sort(tmp.begin(), tmp.end());
            if (start != 0) cout << ",";
            for (int j = 0; j < tmp.size(); j++) {
                if (j != 0) cout << "=";
                cout << tmp[j].second;
            }
        }
    }
    

    return 0;
}
