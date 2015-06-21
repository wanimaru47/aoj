#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
const int TOP = 0;
const int UNDER = 5;
const int FRONT = 1;
const int BACK = 2;
const int LEFT = 3;
const int RIGHT = 4;

const int DIR[] = {FRONT, LEFT, BACK, RIGHT, TOP, UNDER};

const int Left[6][6] = {
    {0,3,5,2,4,0},
    {4,0,1,6,0,3},
    {2,6,0,0,1,5},
    {5,1,0,0,6,2},
    {3,0,6,1,0,4},
    {0,4,2,5,3,0},
};

struct Dice {
    int n[6];

    void SOUTH () {
        int tmp_ = n[TOP]; n[TOP] = n[BACK]; n[BACK] = n[UNDER]; n[UNDER] = n[FRONT]; n[FRONT] = tmp_;
    }

    void NORTH () {
        int tmp_ = n[TOP]; n[TOP] = n[FRONT]; n[FRONT] = n[UNDER]; n[UNDER] = n[BACK]; n[BACK] = tmp_;
    }

    void EAST () {
        int tmp_ = n[TOP]; n[TOP] = n[RIGHT]; n[RIGHT] = n[UNDER]; n[UNDER] = n[LEFT]; n[LEFT] = tmp_;
    }

    void WEST () {
        int tmp_ = n[TOP]; n[TOP] = n[LEFT]; n[LEFT] = n[UNDER]; n[UNDER] = n[RIGHT]; n[RIGHT] = tmp_;
    }
};

const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int main () {
    int n;
    while (cin >> n, n) {
        vector<vector<int> > higth(n * 2 + 1, vector<int>(n * 2 + 1, 0));
        vector<vector<int> > number(n * 2 + 1, vector<int>(n * 2 + 1, 0));

        for (int i = 0; i < n; i++) {
            int t, f;
            cin >> t >> f;
            Dice d;

            d.n[TOP] = t;
            d.n[UNDER] = 7 - t;
            d.n[FRONT] = f;
            d.n[BACK] = 7 - f;
            d.n[LEFT] = Left[t-1][f-1];
            d.n[RIGHT] = 7 - Left[t-1][f-1];

            queue<P> q;
            q.push(P(n,n));

            while (q.size()) {
                P p = q.front(); q.pop();
                int x = p.first, y = p.second;
                bool flag = true;

                for (int j = 6; flag && j >= 4; j--) {
                    for (int k = 0; flag && k < 4; k++) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if(d.n[DIR[k]] == j && higth[x][y] > higth[nx][ny]) {
                            q.push(P(nx,ny));
                            if (k == 0) d.SOUTH();
                            else if (k == 1) d.EAST();
                            else if (k == 2) d.NORTH();
                            else if (k == 3) d.WEST();
                            flag = false;
                        }
                    }
                }

                if (flag) {
                    number[x][y] = d.n[TOP];
                    higth[x][y]++;
                }
            }
        }

        vector<int> res(7);
        for (auto i : number) {
            for (auto j : i) {
                res[j]++;
            }
        }

        for (int i = 1; i < 6; i++) {
            cout << res[i] << " " ;
        } cout << res[6] << endl;
    }
    
    return 0;
}
