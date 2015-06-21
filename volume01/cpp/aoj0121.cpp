#include <bits/stdc++.h>
using namespace std;

const int INF = 1 << 28;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

map<vector<int>,int> m;

bool check (vector<int> &p) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i] != i) return false;
    }
    return true;
}

int zero (vector<int> &p) {
    for (int i = 0; i < p.size(); i++) {
        if (p[i] == 0) return i;
    }

    return -1;
}

int calc (int z, int i) {
    int x = (z / 4) + dx[i];
    int y = (z % 4) + dy[i];
    int c = y + (x ? 4 : 0);
    if (0 <= x && x < 2 && 0 <= y && y < 4) {
        return c;
    }
    return -1;
}

int swap (vector<int> &p, int z, int c) {
    int n = p[z];
    p[z] = p[c];
    p[c] = n;
}

int bfs (vector<int> &p, int count) {
    if (check(p)) return count;
    if (m.find(p) != m.end()) return m[p];
    
    int res = INF ;
    int z = zero(p);
    m[p] = res;

    for (int i = 0; i < 4; i++) {
        int c = calc(z, i);
        if (c >= 0 && p[z] == 0) {
            swap(p, z, c);
            if (m.find(p) == m.end()) {
                res = min(bfs(p, count+1), res);
            } else if (m[p] > res - count) {
                res = min(bfs(p, count+1), res);
            }
            swap(p, z, c);
        }
    }
    m[p] = res - count;

    return res;
}

int main ()
{
    string str;
    while (getline(cin, str)) {
        stringstream ss;
        ss << str;
        vector<int> pazz(8);
        for (auto &i : pazz) {
            ss >> i;
        }
        int res = bfs(pazz, 0);
        cout << res << endl;
   }

    return 0;
}
