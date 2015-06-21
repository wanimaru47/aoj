#include <iostream>
using namespace std;

int N[1001][1001];

int main()
{
    int n, m, a;
    cin >> n >> m >> a;
    for (int i = 0; i < 1001; i++)
        for (int j = 0; j < 1001; j++)
            N[i][j] = i;
    for (int i = 0; i <= m; i++) {
        int h, p, q;
        cin >> h >> p >> q;
        N[q][h] = p;
        N[p][h] = q;
    }
    int h = 1000;
    while (h) {
        a = N[a][h];
        h--;
    }
    cout << a << endl;

    return 0;
}
