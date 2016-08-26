#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll MOD = 1e9+7;

struct Node {
    vector<int> accept;
    map<char,Node*> chd;
};

class PMA {
private :
    Node* root;
    const char failure = 0;

public :
    PMA () {
        root = new Node();
    }

    Node* getRoot() {
        return root;
    }

    void show (Node* now, string prefix) {
        for (auto i : now->chd) {
            cout << prefix << i.first << endl;
            show(i.second, prefix + '>');
        }
    }

    void build(vector<string> vstr) {
        int vlen = vstr.size();
        vector<vector<pair<int,int> > > substring(vlen);
        for (int i = 0; i < vlen; i++) {
            for (int j = 0; j < vlen; j++) {
                if (i == j) continue;
                auto pos = vstr[i].find(vstr[j]);
                if (pos != string::npos) {
                    substring[i].push_back(make_pair(j, pos + vstr[j].size()-1));
                }
            }
        }
        for (int i = 0; i < vlen; i++) {
            Node* now = root;
            for (int j = 0; j < vstr[i].size(); j++) {
                char s = vstr[i][j];
                if (now->chd.find(s) == now->chd.end())
                    now->chd[s] = new Node();
                now = now->chd[s];
                for (auto p : substring[i]) {
                    int v = p.first;
                    int ps = p.second;
                    if (ps == j) {
                        now->accept.push_back(v);
                    }
                }
            }
            now->accept.push_back(i);
        }


        queue<Node*> que;
        string symbol_array = "abcdefghijklmnopqrstuvwxyz";
        for (auto s : symbol_array) {
            if (root->chd.find(s) == root->chd.end()) {
                root->chd[s] = root;
            } else {
                root->chd[s]->chd[failure] = root;
                que.push(root->chd[s]);
            }
        }

        while (!que.empty()) {
            Node* now = que.front();
            que.pop();

            for (auto& v : now->chd) {
                if (v.first == failure) continue;
                que.push(v.second);
                Node* rev = now->chd[failure];
                cout << "> OK" << v.first << endl;
                // while (!rev->chd[v.first])
                while (rev->chd.find(v.first) == rev->chd.end())
                    rev = rev->chd[failure];
                cout << ">>" << endl;
                now->chd[v.first]->chd[failure] = rev->chd[v.first];
            }
        }
        cout << ">>>" << endl;
    }

    void match(string str, vector<int>& result) {
        Node* now = root;
        for (auto s : str) {
            while (now->chd.find(s) == now->chd.end())
                now = now->chd[failure];
            now = now->chd[s];
            for (auto i : now->accept) {
                result[i]++;
            }
        }
    }

    Node* next(string str, Node* now, int& count) {
        for (auto s : str) {
            while (now->chd.find(s) == now->chd.end())
                now = now->chd[failure];
            now = now->chd[s];
            count = count + 0;
            printf("now = %p in next \n", now);
            cout << now->accept.size() << endl;
            for (auto i : now->accept) {
                cout << "match: " << i << endl;
                count++;
            }
        }

        return now;
    }
};

int main() {
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
        cout << "OK" << endl;
        pma.build(season);

        vector<vector<vector<map<Node*,ll> > > > dp(M+1);
        for (auto& i : dp) {
            i.resize(ston.size()+1);
            for (auto& j : i) {
                j.resize(2);
            }
        }

        for (int i = 0; i < N; i++) {
            Node* now = pma.getRoot();
            int count = 0;
            now = pma.next(from[i], now, count);
            if (count > 1) continue;
            dp[from[i].size()][ston[from[i]]][count][now] = 1LL;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < (int)ston.size(); j++) {
                for (int k = 0; k < 2; k++) {
                    for (auto now : dp[i][j][k]) {
                        for (auto nx : next[j]) {
                            Node* node = now.first;
                            ll num = now.second;
                            printf("now = %p\n", node);
                            cout << i << " " << ntos[j] << " " << k << " " << ntos[nx] << endl;
                            int count = k;
                            node = pma.next(ntos[nx], node, count);
                            cout << i+ntos[nx].size() << " " << nx << " " << count << " " << num << endl;
                            printf("now = %p\n", node);
                            if (count <= 1 && i+ntos[nx].size() <= M) {
                                dp[i+ntos[nx].size()][nx][count][node] += num;
                                dp[i+ntos[nx].size()][nx][count][node] %= MOD;
                            }
                        }
                    }
                }
            }
        }

        ll ans = 0LL;
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
