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
        int tx(-1), ty(-1);
        int dir;
        int count = 1;
        for (int i = 0; i < 8; i++) {
            for (int j = 0 ; j < 8; j++) {
                if (d[i][j] == 0) {
                    int count_ = 0;
                    for (int k = 0; k < 8; k++) {
                        int x = i + dx[k];
                        int y = j + dy[k];
                        int tmp = 0;
                        while (inFloor(x, y) && d[x][y] == rev(turn)) {
                            x += dx[k], y += dy[k];
                            tmp++;
                        }
                        if (inFloor(x,y) && d[x][y] == turn) count_ += tmp;
                    }

                    if (count < count_ || (count_ > 0 && tx < 0)) {
                        tx = i; ty = j; count = count_;
                    } else if (count == count_) {
                        if (turn == 1) {
                            if (tx > i) tx = i, ty = j;
                            else if (tx == i && ty > j) ty = j;
                        } else {
                            if (tx < i) tx = i, ty = j;
                            else if (tx == i && ty < j) ty = j;
                        }
                    }
                }
            }
        }

        if (tx > -1) {
            d[tx][ty] = turn;
            for (int i = 0; i < 8; i++) {
                int x = tx + dx[i];
                int y = ty + dy[i];
                while (inFloor(x, y) && d[x][y] == rev(turn)) {
                    x += dx[i], y += dy[i];
                }
                if (inFloor(x, y) && d[x][y] == turn)
                    while (inFloor(x, y) && d[(x+=dx[(i+4)%8])][(y+=dy[(i+4)%8])] == rev(turn))
                        d[x][y] = turn;
            }
        } else noChangeCount++;
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
