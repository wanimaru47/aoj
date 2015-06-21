#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main ()
{
    int n;
    while (cin >> n, n) {
        vector<vector<P> > course(n+1);
        vector<vector<P> > reverse(n+1);
        
        for (int i = 0; i <= n; i++) {
            int m; cin >> m;
            
            vector<int> x(m);
            vector<int> y(m);
            for (int j = 0; j < m; j++) {
                cin >> x[j] >> y[j]; 
            }
            
            const int R = 1;
            const int L = -1;
            
            // cout << i << "> " << m << endl;
            
            for (int j  = 0; j < m - 1; j++) {
                int tmp_dir = 0;
                int tmp_dis = 0;
                int l = j + 1;
                int k = j + 2;

                if (x[j] == x[l]) {
                    tmp_dis = abs(y[j] - y[l]);
                    if (k < m) {
                        if (y[j] < y[l]) {
                            if (x[j] > x[k]) tmp_dir = L;
                            else tmp_dir = R;
                        } else {
                            if (x[j] > x[k]) tmp_dir = R;
                            else tmp_dir = L;
                        }
                    }
                }
                
                if (y[j] == y[l]) {
                    tmp_dis = abs(x[j] - x[l]);
                    if (k < m) { 
                        if (x[j] < x[l]) {
                            if (y[j] < y[k]) tmp_dir = L;
                            else tmp_dir = R;
                        } else {
                            if (y[j] < y[k]) tmp_dir = R; 
                            else tmp_dir = L;
                        }
                    }
                }
                
                // cout << " > " << tmp_dis << ", " << tmp_dir << endl;
                
                course[i].push_back(P(tmp_dis, tmp_dir));
            }
            
            // puts ("reverse");
            // cout << "j = " << m - 1 << endl;

            for (int j = m - 2; j > 0; j--) {
                // cout << j << " " ;
                reverse[i].push_back(P(course[i][j].first, (course[i][j-1].second * -1)));
            }
            // puts("");
            // puts ("reverse pass !!");
            reverse[i].push_back(P(course[i][0].first, 0));
            // cout << "course size " << i << " : " << course[i].size() << endl;
            // cout << "reverse size " << i << " : " << reverse[i].size() << endl;
        }

        vector<int> res;
        for (int i = 1; i <= n; i++) {
            if (course[i].size() == course[0].size()) {
                bool flag = true;
                for (int j = 0; j + 1 < course[0].size(); j++) {
                    if (course[i][j].second != course[0][j].second) {
                        flag = false;
                        break;
                    }
                    if ((double)course[i][j].first / course[0][j].first != (double)course[i][j+1].first / course[0][j+1].first) {
                        flag = false;
                        break;
                    }
                }            
                if (flag) res.push_back(i);
            }

            if (reverse[i].size() == course[0].size()) {
                bool flag = true;            
                for (int j = 0; j + 1 < reverse[0].size(); j++) {
                    if (reverse[i][j].second != course[0][j].second) {
                        flag = false;
                        break;
                    }
                    if ((double)reverse[i][j].first / course[0][j].first != (double)reverse[i][j+1].first / course[0][j+1].first) {
                        flag = false;
                        break;
                    }
                }
            
                if (flag) res.push_back(i);
            }
        }
        
        
        for (auto i : res) {
            cout << i << endl;
        }

        cout << "+++++" << endl;
    }

    return 0;
}
