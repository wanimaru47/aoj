#include <iostream>
using namespace std;

int main(void)
{
	int count, numbers[1000] = {0}, tmp;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < count; i++) {
		for (int j = i+1; j < count; j++) {
			if (numbers[i] > numbers[j]) {
				tmp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = tmp;
			}
		}
	}
	for (int i = 0; i < count-1; i++) {
		cout << numbers[i] << " ";
	}
	cout << numbers[count-1] << endl;

	return 0;
}