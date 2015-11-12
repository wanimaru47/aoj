#include <bits/stdc++.h>
using namespace std;

struct edge {int to, cap, rev; };
const int MAX_V = 10000;
const int INF = 1 << 28;

vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge){to, cap, G[to].size()});
    G[to].push_back((edge){from, cap, G[from].size() - 1});
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(que.size()) {
        int v = que.front(); que.pop();
        for(int i = 0; i < G[v].size(); i++) {
            edge &e = G[v][i];
            if(e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if(v == t)  return f;
    
    for(int &i = iter[v]; i < G[v].size(); i++) {
        edge &e = G[v][i];
        if(e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t, int flow_=INF) {
    int flow = 0;
    while (bfs(s), level[t] >= 0 && flow_ > 0) {
        memset(iter, 0, sizeof(iter));
        int f;
        while((f = dfs(s, t, flow_)) > 0) {
            flow += f;
            if (flow_ != INF) flow_ -= f;
        }
    }

    return flow;
}

int main() {
    int n, e, q; 
    cin >> n >> e >> q;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            add_edge(i, j, 0);
        }
    }
    for (int i = 0; i < e; i++) {
        int f, t;
        cin >> f >> t;
        int j = 0;
        while (G[f][j].to != t) j++;
        G[f][j].cap = 1;
        G[t][G[f][j].rev].cap = 1;
    }

    int f = max_flow(1, n);
    for (int i = 0; i < q; i++) {
        int m, a, b;
        cin >> m >> a >> b;
        int j = 0;
        while (G[a][j].to != b) j++;
        if (m == 1) {
            G[a][j].cap = 1;
            G[b][G[a][j].rev].cap = 1;
            f += max_flow(1, n);
        } else {
            int from = -1, to = -1;
            if (G[a][j].cap == 2) from = b, to = a;
            if (G[b][G[a][j].rev].cap == 2) from = a, to = b;
            G[a][j].cap = 0;
            G[b][G[a][j].rev].cap = 0;
            if (from > 0 && to > 0 && max_flow(from, to, 1) == 0) {
                f--;
                max_flow(from, 1, 1);
                max_flow(n, to, 1);
            }
        }
        cout << f << endl;
    }

    return 0;
}
