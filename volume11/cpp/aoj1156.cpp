#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef unsigned int uint;
typedef vector<int> V;
typedef vector<vector<int> > VV;
typedef pair<int,pair<P,int> > PP;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

const int INF = 1 << 28;
const double EPS = 1e-9;
const int dx[] = {0, 1, 0,-1};
const int dy[] = {1, 0,-1, 0};

int main()
{
    int n, m;
    while (cin >> n >> m, m || n) {
        VV d(m, V(n));
        rep(i,m) rep(j,n) {
            cin >> d[i][j];
        }
        
        V c(4);
        rep (i, 4) {
            cin >> c[i];
        }

        vector<vector<vector<int> > > v(m, VV(n, V(4, INF)));
        VV dp (m, V(n, INF));
        dp[0][0] = v[0][0][0] = 0;
        priority_queue<PP, vector<PP>, greater<PP> >  que;
        que.push(PP(0, pair<P,int>(P(0,0), 0)));
        
        while (!que.empty()) {
            PP pp = que.top(); que.pop();
            int x = pp.second.first.first;
            int y = pp.second.first.second;
            int d_ = pp.second.second;

            if (v[x][y][d_] < pp.first) continue; 
            
            rep (i,4) {
                int dir = (i + d_) % 4;
                int cost = (i == d[x][y] ? 0 : c[i]) + v[x][y][d_];
                int nx = dx[dir] + x, ny = dy[dir] + y;
                if (0 <= nx && nx < m && 0 <= ny && ny < n && v[nx][ny][dir] > cost) {
                    v[nx][ny][dir] = cost;
                    dp[nx][ny] = min(dp[nx][ny], cost);
                    que.push(PP(cost, pair<P,int>(P(nx,ny), dir)));
                }
            }
        }

        cout << dp[m-1][n-1] << endl;
    }
    
                
    return 0;
}
