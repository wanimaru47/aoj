#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int n, a;
    cin >> n >> a;

    vector<vector<pair<int,int> > > v(10000);

    if (int i = 0; i < n; i++) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for (int j = y1; j < y2; j++) {
            if (v[j].size() == 0) v[j].push_back(pair<int,int>(x1,x2));
            for (auto k : v[j]) {
                
            }
        }
    }

    return 0;
}
