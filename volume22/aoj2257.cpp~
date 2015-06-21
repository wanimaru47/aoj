#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
#define isUruu(y) ((y % 4 || (y % 100 == 0 && y % 400)) ? false : true)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef unsigned int uint;
typedef vector<int> V;
typedef vector<vector<int> > VV;
typedef priority_queue<P, vector<P>, greater<P> > PQ;

const int INF = 1 << 28;
const int MOD = 1e9+7;
const double EPS = 1e-9;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

int main()
{
    int n, m, k;
    while (cin >> n >> m >> k, n + k + m) {
        vector<string> f, t, from(n), to(n);
        vector<set<string> > last(m + 1);
        vector<map<string, ll> > vms(m + 1);
        vector<map<string, set<string> > > vmss (m + 1);
        rep (i, n) {
            cin >> from[i] >> to[i];
            last[from[i].size()].insert(from[i]);
            last[to[i].size()].insert(to[i]);
            vms[from[i].size()][from[i]] = 1;
            vms[to[i].size()][to[i]] = 1;
            vmss[from[i].size()][from[i]].insert(from[i]);
            vmss[to[i].size()][to[i]].insert(to[i]);
        }

        vector<string> S(k);
        rep (i,k) {
            cin >> S[i];
        }

        REP (i,1,m) {
            rep (j,n) {
                if (last[i].find(from[i]) != last[i].end()) {
                    
                }
            }
        }
    }
                
    return 0;
}
