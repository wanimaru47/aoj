#include <iostream>
using namespace std;

int main(void)
{
  int n1, n2, n3, sum;

  while (1) {
    cin >> n1 >> n2 >> n3;
    if (n1 == -1 && n2 == -1 && n3 == -1) break;
    if (n1 == -1 || n2 == -1) cout << "F" << endl;
    else {
      sum = n1 + n2;
      if (sum >= 80) cout << "A" << endl;
      else if (sum >= 65) cout << "B" << endl;
      else if (sum >= 50) cout << "C" << endl;
      else if (sum >= 30 && n3 < 50) cout << "D" << endl;
      else if (n3 >= 50) cout << "C" << endl;
      else cout << "F" << endl;
    }
}

  return 0;
}
