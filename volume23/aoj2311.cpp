#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vec;
typedef vector<vec> mat;

int dx[] = {1, 1, 1, 0, -1, -1, -1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};

int rev(int n) {
    return n == 1 ? 2 : 1;
}

bool inFloor(int x, int y) {
    if (0 <= x && x < 8 && 0 <= y && y < 8) return true;
    return false;
}

int main() {
    mat d(8, vec(8));

    for (auto &i : d) {
        for (auto &j : i) {
            char c; cin >> c;
            if (c == 'o') j = 1;
            if (c == 'x') j = 2;
        }
    }

    int turn = 1;
    int noChangeCount = 0;
    while (1) {
        queue<P> que;
        for (int i = 0; i < 8; i++) {
            for (int j = 0 ; j < 8; j++) {
                if (d[i][j] == turn) {
                    bool flag = false;
                    for (int k = 0; k < 8; k++) {
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if (inFloor(nx, ny) && d[nx][ny] == rev(turn)) {
                            flag = true;
                        }
                    }
                    if (flag) que.push(P(i,j));
                }
            }
        }

        if (que.empty()) break;

        int tx(-1), ty(-1);
        int dir;
        int count = 0;

        while (que.size()) {
            P p = que.front();
            que.pop();

            int x = p.first;
            int y = p.second;

            for (int i = 0; i < 8; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];

                if (inFloor(nx, ny) && d[nx][ny] == rev(turn)) {
                    int count_ = 0;
                    while (inFloor(nx, ny) && d[nx][ny] == rev(turn)) {
                        count_++;
                        nx = nx + dx[i];
                        ny = ny + dy[i];
                    }

                    if (inFloor(nx, ny) && d[nx][ny] == 0) {
                        if (count < count_) {
                            tx = nx;
                            ty = ny;
                            count = count_;
                            dir = (i + 4) % 8;
                        } else if (count == count_) {
                            if (turn == 1) {
                                if (tx > nx) {
                                    tx = nx;
                                    ty = ny;
                                    dir = (i + 4) % 8;
                                } else if (tx == nx) {
                                    if (ty > ny) {
                                        ty = ny;
                                        dir = (i + 4) % 8;
                                    }
                                }
                            } else {
                                if (tx < nx) {
                                    tx = nx;
                                    ty = ny;
                                    dir = (i + 4) % 8;
                                } else if (tx == nx) {
                                    if (ty < ny) {
                                        ty = ny;
                                        dir = (i + 4) % 8;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        if (tx > -1) {
            bool flag = true;
            while (d[tx][ty] != turn) {
                d[tx][ty] = turn;
                tx += dx[dir];
                ty += dy[dir];
                cout << ty << " " << ty << endl;
                noChangeCount = 0;
                flag = false;
            }
            if (flag) noChangeCount++;
        } else noChangeCount++;
        cout << "in the loog" << endl;

        if (noChangeCount >= 2) break;

        turn = rev(turn);
    }

    for (auto i : d) {
        for (auto j : i) {
            if (j == 1) cout << 'o';
            else if (j == 2) cout << 'x';
            else cout << '.';
        }
        cout << endl;
    }

    return 0;
}
