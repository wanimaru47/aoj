#include <iostream>
using namespace std;

int main() 
{
  int wigth;
  while (cin >> wigth) {
    int i = 1;
    bool flag = false;
    while (i <= 512) {
      if (wigth & i) {
	if (flag) cout << " ";
	cout << i;
	flag = true;
      }
      i *= 2;
    }
    cout << endl;
  }

  return 0;
}
