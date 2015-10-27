#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;
typedef vector<string> word;

class Union_find
{
    public :
        vector<int> par;
        vector<int> rank;
        vector<int> cost;

        Union_find (int n) {
            par.resize(n);
            rank.resize(n);
            cost.resize(n);

            for (int i = 0; i < n; i++) {
                par[i] = i;
                rank[i] = 0;
                cost[i] = 0;
            }
        }

        int find (int);
        void unite (int, int);
        bool same (int, int);
};

int Union_find::find (int x) {
    if (par[x] == x) {
        return x;
    } else {
        return par[x] = find(par[x]);
    }
}

void Union_find::unite (int x, int y) {
    x = find(x);
    y = find(y);
    cost[y] = cost[x] = min(cost[x], cost[y]);

    if (rank[x] < rank[y]) {
        par[x] = y;
    } else {
        par[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

bool Union_find::same (int x, int y) {
    return find(x) == find(y);
}

int main() {
    int N, M;
    cin >> N;
    map<string,int> item_to_num;
    Union_find item(N);
    for(int i = 0; i < N; i++) {
        string str;
        int cost_;
        cin >> str >> cost_;
        item_to_num[str] = i;
        item.cost[i] = cost_;
    }
    cin >> M;
    for(int i = 0; i < M; i++) {
        string s, t;
        cin >> s >> t;
        item.unite(item_to_num[s], item_to_num[t]);
    }
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += item.cost[item.find(i)];
    }

    cout << sum << endl;

    return 0;
}
