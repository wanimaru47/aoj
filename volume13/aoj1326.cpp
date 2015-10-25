#include <bits/stdc++.h>
using namespace std;

int main() {
    int P, Q;
    while(cin >> P >> Q, P || Q) {
        vector<string> p(P), q(Q);
        for(auto &i : p) cin >> i;
        for(auto &i : q) cin >> i;

        int psum = 0;
        int D[12] = {0}, F[12] = {0};
        for(int i = 0; i < P; i++) {
            string str = p[i];
            int dot = 0;
            while(str[dot] == '.') dot++;
            D[i + 1] = dot;
        }
        for(int i = 0; i < Q; i++) {
            string str = q[i];
            int dot = 0;
            while(str[dot] == '.') dot++;
            F[i + 1] = dot;
        }
        vector<int> X(P + 1), Y(P + 1), Z(P + 1);
        for(int i = 0; i < P; i++) {
            string str = p[i];
            X[i] = count(str.begin(), str.end(), '(') - count(str.begin(), str.end(), ')') + (i == 0 ? 0 : X[i-1]);
            Y[i] = count(str.begin(), str.end(), '[') - count(str.begin(), str.end(), ']') + (i == 0 ? 0 : Y[i-1]);
            Z[i] = count(str.begin(), str.end(), '{') - count(str.begin(), str.end(), '}') + (i == 0 ? 0 : Z[i-1]);
        }
        vector<int> R(P + 1), C(P + 1), S(P + 1);
        for(int i = 0; i < Q; i++) {
            string str = q[i];
            R[i] = count(str.begin(), str.end(), '(') - count(str.begin(), str.end(), ')') + (i == 0 ? 0 : R[i-1]);
            C[i] = count(str.begin(), str.end(), '[') - count(str.begin(), str.end(), ']') + (i == 0 ? 0 : C[i-1]);
            S[i] = count(str.begin(), str.end(), '{') - count(str.begin(), str.end(), '}') + (i == 0 ? 0 : S[i-1]);
        }

        set<int> r, c, s;
        vector<int> ans(Q + 1,-2);
        ans[0] = 0;
        for(int i = 1; i <= 20; i++) {
            for(int j = 1; j <= 20; j++) {
                for(int k = 1; k <= 20; k++) {
                    bool flag = true;
                    for(int l = 0; l < P; l++) {
                        if(X[l] * i + Y[l] * j + Z[l] * k == D[l + 2]) ;
                        else {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) continue;
                    for(int l = 0; l < Q; l++) {
                        int indention = i * R[l] + j * C[l] + k * S[l];
                        if(ans[l + 1] == -2) ans[l + 1] = indention;
                        else if (ans[l + 1] != indention) ans[l + 1] = -1;
                    }
                }
            }
        }
        for(int i = 0; i < Q - 1; i++) {
            cout << ans[i] << " ";
        }
        cout << ans[Q-1] << endl;
    }

    return 0;
}
