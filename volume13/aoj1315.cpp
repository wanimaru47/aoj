#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vec;

int main() {
    int N;
    while(cin >> N, N) {
        vector<string> md(N), person(N);
        vec in(N, -1), out(N, -1);
        map<string,int> res;
        for(int i = 0; i < N; i++) {
            int h, m;
            char e, tmp;
            string q, MD;
            cin >> MD >> h >> tmp >> m >> e >> q;
            if(e == 'I')
                md[i] = MD, person[i] = q, in[i] = 60 * h + m;
            else 
                md[i] = MD, person[i] = q, out[i] = 60 * h + m;
            res[q] = 0;
        }

        for(int i = 0; i < N; i++) {
            if(person[i] == "000" && in[i] >= 0) {
                int out0 = i + 1;
                while(person[out0] != "000") out0++;
                for(int j = 0; j < N; j++) {
                    if(person[j] != "000" && md[i] == md[j] && in[j] >= 0) {
                        int outX = j + 1;
                        while(person[outX] != person[j]) outX++;
                        if(!(out[outX] < in[i] || out[out0] < in[j])) {
                            res[person[j]] += min(out[out0], out[outX]) - max(in[j], in[i]);
                        }
                    }
                }
            }
        }
        int MAX = 0;
        for(auto i : res) 
            MAX = max(MAX, i.second);

        cout << MAX << endl;
    }

    return 0;
}
