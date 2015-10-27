#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    while(cin >> N >> M, N || M) {
        vector<string> v(N);
        for(auto &i : v) cin >> i;

        string res = "";
        const int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
        const int dy[] = {-1, 0, 1, -1, 0, 1, -1, 1};
        set<string> s;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                for(int k = 0; k < 8; k++) {
                    int x = i; 
                    int y = j;
                    int nx = (x + dx[k] + N) % N;
                    int ny = (y + dy[k] + M) % M;
                    string tmp = "";
                    tmp += v[i][j];
                    while(x != nx || y != ny) {
                        tmp += v[nx][ny]; 
                        nx = (nx + dx[k] + N) % N;
                        ny = (ny + dy[k] + M) % M;
                        if(res.size() <= tmp.size() && s.find(tmp) != s.end()) {
                            if(res.size() < tmp.size()) {
                                res = tmp;
                            } else if (res.size() == tmp.size()) {
                                res = min(res, tmp);
                            } 
                        } else if (res.size() <= tmp.size()){
                            s.insert(tmp);
                        }
                    }
                }
            }
        }

        cout << (res == "" ? "0" : res) << endl;
    }

    return 0;
}
