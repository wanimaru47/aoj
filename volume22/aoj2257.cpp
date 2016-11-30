#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

struct Node {
    string suffix;
    vector<int> accept;
    vector<Node*> next;
};

class PMA {
private :

    Node* root;
    const char failure = 0;
public :
    PMA () {
        root = new Node();
        root->next.resize(256, nullptr);
        root->next[failure] = root;
    }

    Node* getRoot() {
        return root;
    }

    Node* addNode() {
        Node* node = new Node();
        node->next.resize(256, nullptr);
        node->next[failure] = root;

        return node;
    }

    void build(vector<string> vstr) {
        for (int i = 0, vlen = vstr.size(); i < vlen; i++) {
            Node* now = root;
            string tmp;
            for (auto c : vstr[i]) {
                if (!now->next[c]) now->next[c] = addNode();
                now = now->next[c];
                tmp += c;
                now->suffix = tmp;
            }
            now->accept.push_back(i);
        }

        queue<Node*> que;
        const string symbol_array = "abcdefghijklmnopqrstuvwxyz";
        for (auto c : symbol_array) {
            if (root->next[c] != nullptr) {
                root->next[c]->next[failure] = root;
                que.push(root->next[c]);
            } else {
                root->next[c] = root;
            }
        }

        while (!que.empty()) {
            Node* node = que.front(); que.pop();
            for (auto c : symbol_array) {
                auto now = node->next[c];
                if (now == nullptr) continue;
                que.push(now);

                Node* rev = node->next[failure];
                while (rev->next[c] == nullptr) rev = rev->next[failure];
                now->next[failure] = rev->next[c];

                vector<int> acc;
                set_union(now->accept.begin(),
                          now->accept.end(),
                          rev->next[c]->accept.begin(),
                          rev->next[c]->accept.end(),
                          back_inserter(acc));
                now->accept = acc;
            }
        }
    }

    Node* next(string str, Node* now, int& count) {
        for (auto c : str) {
            while (now->next[c] == nullptr) now = now->next[failure];
            now = now->next[c];

            for (auto i : now->accept) {
                count++;
            }
        }

        return now;
    }
};

int 
main() {
    int N, M, K;
    while (cin >> N >> M >> K, N || M || K) {
        PMA pma;
        vector<string> from(N), to(N), season(K);
        map<string,int> ston;
        vector<string> ntos;
        for (int i = 0; i < N; i++) {
            cin >> from[i] >> to[i];
            if (ston.find(from[i]) == ston.end())
                ston[from[i]] = ston.size()-1, ntos.push_back(from[i]);
            if (ston.find(to[i]) == ston.end())
                ston[to[i]] = ston.size()-1, ntos.push_back(to[i]);
        }

        vector<vector<int> > next(ston.size());
        for (int i = 0; i < N; i++) {
            next[ston[from[i]]].push_back(ston[to[i]]);
        }

        for (int i = 0; i < K; i++) cin >> season[i];
        pma.build(season);

        vector<vector<vector<map<Node*,int> > > > dp(M+1);
        for (auto& i : dp) {
            i.resize(ston.size()+1);
            for (auto& j : i) {
                j.resize(2);
            }
        }

        vector<vector<bool> > flag(M+1, vector<bool>(ston.size(), false));
        for (int i = 0; i < N; i++) {
            Node* now = pma.getRoot();
            int count = 0;
            now = pma.next(from[i], now, count);
            if (from[i].size() > M || count > 1) continue;
            dp[from[i].size()][ston[from[i]]][count][now] = 1;
            flag[from[i].size()][ston[from[i]]] = true;
        }
        for (int i = 0; i < N; i++) {
            Node* now = pma.getRoot();
            int count = 0;
            now = pma.next(to[i], now, count);
            if (to[i].size() > M || count > 1) continue;
            dp[to[i].size()][ston[to[i]]][count][now] = 1;
            flag[to[i].size()][ston[to[i]]] = true;
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < (int)ston.size(); j++) {
                if (!flag[i][j]) continue;
                for (int k = 0; k < 2; k++) {
                    for (auto now : dp[i][j][k]) {
                        for (auto nx : next[j]) {
                            Node* node = now.first;
                            int num = now.second;
                            int count = k;
                            node = pma.next(ntos[nx], node, count);
                            if (count <= 1 && i+ntos[nx].size() <= M) {
                                dp[i+ntos[nx].size()][nx][count][node] += num;
                                dp[i+ntos[nx].size()][nx][count][node] %= MOD;
                                flag[i+ntos[nx].size()][nx] = true;
                            }
                        }
                    }
                    dp[i][j][k].clear();
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < (int)ston.size(); i++) {
            for (auto now : dp[M][i][1]) {
                ans += now.second;
                ans %= MOD;
            }
        }

        cout << ans << endl;
    }

    return 0;
}
