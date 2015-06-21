#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cstring>
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

const int MAX = 21;
const int INF = 999999;

int n, m, f[MAX][MAX];
V d[MAX];

int bfs (int start, int goal) {
    int s[MAX];
    memset(s, INF, sizeof(s));
    Q q;
    q.push(start);
    s[start] = 0;

    while (q.size()) {
        int t1 = q.front(); q.pop();

        for (int i = 0; i < d[t1].size(); i++) {
            int t2 = d[t1][i];
            if (s[t2] > s[t1] + f[t1][t2]) {
                s[t2] = s[t1] + f[t1][t2];
                q.push(t2);
            }
        }
    }

    return s[goal];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c, dd;
        scanf("%d,%d,%d,%d", &a, &b, &c, &dd);
        f[a][b] = c;
        f[b][a] = dd;

        d[a].push_back(b);
        d[b].push_back(a);
    }
    int x1, x2, y1, y2;
    scanf("%d,%d,%d,%d", &x1, &x2, &y1, &y2);

    int res = y1 - y2;
    res -= bfs(x1, x2);
    res -= bfs(x2, x1);

    cout << res << endl;
    
    return 0;
}
