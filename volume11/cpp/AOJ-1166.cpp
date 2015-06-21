#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <list>
#include <stack>
#include <queue>
using namespace std;

typedef list<int> L;
typedef pair <int,int> P;
typedef vector<int> V;
typedef queue<P> Q;
typedef stack<int> S;
typedef map<string,int> M;

int W, H;
const int MAX = 31;
const int INF = 99999;
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
int ds[] = {1, 2, 4, 8};

int bfs(int s[MAX][MAX]) {
    Q q;
    q.push(P(0, 0));
    int d[MAX][MAX];
    for (int i = 0; i < MAX; i++)
        for (int j = 0; j < MAX; j++)
            d[i][j] = INF;
    d[0][0] = 1;

    while (q.size()) {
        int x = (q.front()).first, y = (q.front()).second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (0 <= nx && nx < H && 0 <= ny && ny < W && d[nx][ny] == INF && (s[x][y] & ds[i]) == 0) {
                //cout << "i = " << i << "s = " << s[x][y] << endl;
                q.push(P(nx, ny));
                d[nx][ny] = d[x][y] + 1;
                //cout << "OK" << endl;
            }
        }
    }
/*
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            printf("%6d", d[i][j]);
        }
        cout << endl;
    }
    cout << endl;
*/  
    return d[H - 1][W - 1] != INF ? d[H - 1][W - 1] : 0;
}

int main()
{
    while (cin >> W >> H, H) { 
        int s[MAX][MAX] = {};
        for (int i = 0; i < H; i++) {
            for (int j = 1; j < W; j++) {
                int wall; cin >> wall;
                if (wall == 1) {
                    s[i][j] |= 1;
                    s[i][j - 1] |= 4;
                }
                if (j == 1)
                    s[i][j - 1] |= 1;
                else if (j == W - 1)
                    s[i][j] |= 4;
            }
            for (int j = 0; j < W; j++) {
                int wall;
                if (i < H - 1) cin >> wall;
                else wall = 1;
                if (wall == 1) {
                    s[i][j] |= 2;
                    s[i + 1][j] |= 8;
                }
                if (i == 0)
                    s[i][j] |= 8;
            }
        }
        cout << bfs(s) << endl;;
        
    }
    
    return 0;
}
