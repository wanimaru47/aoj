#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define isUruu(y) ((y % 4 || (y % 100 == 0 && y % 400)) ? false : true)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef unsigned int uint;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<char> Vc;
typedef vector<Vc> VVc;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

const int INF = 1 << 28;
const double EPS = 1e-9;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int w, h;
int ans;

void dfs (VVc &field, vector<P> &pp, int sx, int sy, uint b, int sum)
{
    if (b == ((1 << pp.size()) - 1)) {
        if (ans > sum) ans = sum;
        return ;
    }
    if (sum > ans) return ;
    rep (j, pp.size()) {
        if (b & (1 << j)) continue;
        queue<P> q;
        q.push(P(sx,sy));
        VV d(h, V(w, INF));
        d[sx][sy] = 0;
        int count = 0;
        while (q.size()) {
            P p = q.front(); q.pop();
            int x = p.first, y = p.second;
            if (x == pp[j].first && y == pp[j].second) {
                count = d[x][y];
                break;
            }
            
            rep (i,4) {
                int nx = x + dx[i], ny = y + dy[i];
                if (0 <= nx && nx < h && 0 <= ny && ny < w && d[nx][ny] == INF && field[nx][ny] != 'x') {
                    d[nx][ny] = d[x][y] + 1;
                    q.push(P(nx,ny));
                }
            }
        }
        if (count == 0) return ;
        dfs(field, pp, pp[j].first, pp[j].second, b | (1 << j), sum + count);
    }
    
    return ;
}

int main()
{
    while (cin >> w >> h, h + w) {
        VVc field(h, Vc(w));
        vector<P> p;
        int sx,sy;
        rep (i,h) rep (j,w) {
            cin >> field[i][j];
            if (field[i][j] == 'o') sx = i, sy = j;
            else if (field[i][j] == '*') p.push_back(P(i,j)); 
        }

        ans = INF;
        dfs(field, p, sx, sy, 0, 0);
        
        cout << (ans == INF ? -1 : ans) << endl;
    }
                
    return 0;
}
