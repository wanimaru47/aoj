#include <iostream>
#include <vector>
using namespace std;

int n, m;

int main ()
{
    cin >> n >> m;
    vector<int> v[100];
    int prob[100][100][2];
    for (int i = 0; i < m; i++) {
        int a, b, c, p;
        cin >> a >> b >> c >> p;
        v[a].push_back(b);
        prob[a][b][0] = c;
        prob[a][b][1] = p;
    }

    int q;
    for (int i = 0; i < q; i++) {
        int dest, cost;
        cin >> dest >> cost;
        int que = 0;
        while (que != ) {

        }
    }

    return 0;
}
