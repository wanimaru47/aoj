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
        int X[P + 1] = {0}, Y[P + 1] = {0}, Z[P + 1] = {0};
        for(int i = 0; i < P; i++) {
            string str = p[i];
            X[i] = count(str.begin(), str.end(), '(') - count(str.begin(), str.end(), ')');
            Y[i] = count(str.begin(), str.end(), '[') - count(str.begin(), str.end(), ']');
            Z[i] = count(str.begin(), str.end(), '{') - count(str.begin(), str.end(), '}');
        }
        int R, C, S;
        set<int> r, c, s;
        vector<int> ans(Q,-2);
        for(int i = 1; i <= 20; i++) {
            for(int j = 1; j <= 20; j++) {
                for(int k = 1; k <= 20; k++) {
                    int pre = 0;
                    bool flag = true;
                    for(int l = 0; l < P; l++) {
                        if(pre + X[l] * i + Y[l] * j + Z[l] * k == D[l + 2]) pre = D[l + 2];
                        else {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) continue;
                    for(int l = 0; l < Q; l++) {
                        
                    }
                }
            }
        }
        for(int i = 0; i < Q; i++) {
            if 
        }
    }

    return 0;
}
