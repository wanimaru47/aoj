#include <bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<vector<int> > VV;

const int INF = 1 << 28;
const double EPS = 1e-9;

int n;
VV par;
VD x, y, r;
VI c;
map<int,int> m;

string toString (int era) {
    string str;
    for (int i = 0; i < n; i++) {
        str = (era % 2 ? "1" : "0") + str;
    }

    return str;
}

int dfs (int era) {
    // cout << toString(era) << endl;
    if (era == ((1 << n) - 1)) return 0;
    int cera = ((1 << n) - 1) ^ era;
    if (m.find(cera) != m.end()) {
        return m[cera];
    }
    
    VV count(5);
    rep (i,n) {
        bool flag = true;
        if (era & (1 << i)) continue; 
        rep(j,par[i].size()) {
            if (cera & (1 << par[i][j])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            count[c[i]].push_back(i);
        }
    }

    int ret = 0;
    REP(i,1,5) {
        if (count[i].size() >= 2) {
            rep(j,count[i].size()-1) REP(k,j+1,count[i].size()) {
                int tera = era;
                // cout << i << " " << j << " " << k << " " << count[i][j] << endl;
                // cout << i << " " << j << " " << k << " " << count[i][k] << endl;
                tera |= (1 << count[i][j]);
                tera |= (1 << count[i][k]);
                // cout << "tera > " << toString(tera) << endl;
                ret = max(ret, dfs(tera) + 2);
            }
        }
    }

    // cout << "ret = " << ret << endl;
    return m[cera] = ret;
}

int main()
{
    while (cin >> n, n) {
        x.resize(n), y.resize(n), r.resize(n), c.resize(n);
        m.clear();
        
        rep(i, n) {
            cin >> x[i] >> y[i] >> r[i] >> c[i];
        }
        
        par.clear();
        par.resize(n);
        rep(i,n) rep(j,i) {
            double dis = pow(x[i] - x[j], 2.) + pow(y[i] - y[j], 2.);
            if (sqrt(dis) < r[i] + r[j]) {
                par[i].push_back(j);
            }
        }

        /*
        rep(i,n) {
            rep(j,par[i].size()) {
            cout << par[i][j] << " ";
            }cout << endl;
        }
        */

        cout << dfs(0) << endl;
    }
                
    return 0;
}
