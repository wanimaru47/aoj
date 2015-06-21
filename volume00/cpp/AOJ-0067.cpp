#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

const int MAX = 12;
int m[MAX][MAX];
string t[12];
const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int main ()
{
    while (cin >> t[0]) {
        for (int i = 1; i < 12; i++) {
            cin >> t[i];
        }

        int res = 0;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (t[i][j] == '1') {
                    res++;
                    pair<int,int> p;
                    queue<pair<int,int> > v;
                    p = pair<int,int>(i,j);
                    v.push(p);
                    t[i][j] = '0';
                    while (!v.empty()) {
                        auto q = v.front(); v.pop();
                        int x = q.first, y = q.second;
                        for (int k = 0; k < 4; k++) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (0 <= nx && nx < 12 && 0 <= ny && ny < 12 && t[nx][ny] == '1') {
                                t[nx][ny] = '0';
                                v.push(pair<int,int>(nx,ny));
                            }
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }
    
    return 0;
}
