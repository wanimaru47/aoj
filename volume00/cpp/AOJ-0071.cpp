#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> P;
typedef queue<P> Q;

const int dx[] = {0,1,0,-1}, dy[] = {1,0,-1,0};

int main ()
{
    int n;
    cin >> n;
    int count = 0;
    while (n > count) {
        vector<string> v(8,"00000000");
        for (auto& i : v) {
            string t;
            cin >> t;
            i = t;
        }
        int x, y;
        cin >> y >> x;
        
        Q q;
        q.push(P(x-1,y-1));
        while (!q.empty()) {
            P p = q.front(); q.pop();
            x = p.first;
            y = p.second;
            v[x][y] = '0';
            for (int i = 0; i < 4; i++) {
                for (int j = 1; j <= 3; j++) {
                    int nx = x + dx[i] * j, ny = y + dy[i] * j;
                    if (0 <= nx && nx < 8 && 0 <= ny && ny < 8 && v[nx][ny] == '1') {
                        q.push(P(nx,ny));
                    }
                }
            }
        }
        cout << "Data " << (++count) << ":" << endl;
        for (auto i : v) {
            cout << i << endl;
        }
    }
    
    return 0;
}
