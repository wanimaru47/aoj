#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int main ()
{
    int n, w, d;
    while (cin >> n >> w >> d, n || w || d) {
        vector<P> v;
        v.push_back(P(w, d));
        int count = 1;
        while (n--) {
            int p, s;
            cin >> p >> s ;

            int x = v[p-1].first, y = v[p-1].second;
            // cout << "v size > " << v.size() << " : " << x << " " << y << endl;
            int len = x * 2 + y * 2;
            s %= len;

            int x1, x2, y1, y2;
            if (s < x) {
                x1 = s; x2 = x - s; y1 = y2 = y;
            } else if (s < len / 2) {
                x1 = x2 = x; y1 = s - x; y2 = y - y1;
            } else if (s < len -  y) {
                x1 = s - (len / 2); x2 = x - x1; y1 = y2 = y;
            } else if (s < len) {
                x1 = x2 = x; y1 = len - s; y2 = y - y1;
            }

            if (x1 * y1 < x2 * y2) {
                v.push_back(P(x1, y1));
                v.push_back(P(x2, y2));
            } else {
                v.push_back(P(x2, y2));
                v.push_back(P(x1, y1));
            }
            count++;
            v.erase(v.begin() + (p - 1));

            v.resize(count);
        }


        vector<int> res;
        for (auto i : v) {
            res.push_back(i.first * i.second);
        }

        sort(res.begin(), res.end());

        for (int i = 0; i < res.size() - 1; i++) {
            cout << res[i] << " " ;
        } cout << res[res.size()-1] << endl;
    }

    return 0;
}
