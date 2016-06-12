#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
typedef pair<P,int> PP;
int H, W;
long long int L;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const string DIR = "NESW";

void solve() {
    vector<string> v(H);
    for (int i = 0; i < H; i++) cin >> v[i];

    int sx, sy, dir;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (v[i][j] != '.' && v[i][j] != '#') sx = i, sy = j, dir = DIR.find(v[i][j]);

    v[sx][sy] = '.';

    map<PP,long long int> m;
    map<long long int, PP> rev;
    long long int loop_start = 0LL, loop_end = L;
    for (long long int i = 0LL; i < L; i++) {
        int nx = sx + dx[dir];
        int ny = sy + dy[dir];
      check:
        if (0 <= nx && nx < H && 0 <= ny && ny < W && v[nx][ny] == '.') {
            sx = nx;
            sy = ny;
        } else {
            dir = (dir + 1) % 4;
            nx = sx + dx[dir];
            ny = sy + dy[dir];
            goto check;
        }

        if (m.find(PP(P(sx,sy),dir)) != m.end()) {
            loop_start = m[PP(P(sx, sy), dir)];
            loop_end = i - 1;
            break;
        } else {
            m[PP(P(sx, sy), dir)] = i;
            rev[i] = PP(P(sx, sy), dir);
        }
    }

    long long int itr = (L - loop_start - 1) % (loop_end - loop_start + 1);
    itr += loop_start;
    cout << rev[itr].first.first+1 << " " << rev[itr].first.second+1 << " " << DIR[rev[itr].second] << endl;
}

int main() {
    while (cin >> H >> W >> L, H || W || L) solve();

    return 0;
}
