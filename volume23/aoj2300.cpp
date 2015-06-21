#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int n, m;
    cin >> n >> m;
    vector<double> R(n), G(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> R[i] >> G[i] >> B[i];
    }

    vector<double> d;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double dis = (R[i] - R[j]) * (R[i] - R[j]) + (G[i] - G[j]) * (G[i] - G[j]) + (B[i] - B[j]) * (B[i] - B[j]);
            d.push_back(dis);
        }
    }

    sort(d.begin(), d.end());

    for (int i = d.size() - 1; i + ) {

    }

    return 0;
}
