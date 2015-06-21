#include <iostream>
#include <cstdio>
#define MAX_N 10
#define MAX_M 10
using namespace std;

int field[MAX_N][MAX_M] = {0};
int x, y, size, nx, ny;

void Big()
{
	int mx[13] = {-1, -1, -1, 0, 0, 0, 1, 1, 1, -2, 0, 0, 2}, my[13] = {-1, 0, 1, -1, 0, 1, -1, 0, 1, 0, -2, 2, 0};
	for (int i = 0; i < 13; i++) {
		nx = x + mx[i]; ny = y + my[i];
		if (0 <= nx && nx < MAX_N && 0 <= ny && ny < MAX_M) field[nx][ny]++; 
	}
}

void Midole()
{
	int mx[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1}, my[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
	for (int i = 0; i < 9; i++) {
		nx = x + mx[i]; ny = y + my[i];
		if (0 <= nx && nx < MAX_N && 0 <= ny && ny < MAX_M) field[nx][ny]++; 
	}
}

void Mini()
{
	int mx[5] = {-1, 0, 0, 0, 1}, my[5] = {0, -1, 0, 1, 0};
	for (int i = 0; i < 5; i++) {
		nx = x + mx[i]; ny = y + my[i];
		if (0 <= nx && nx < MAX_N && 0 <= ny && ny < MAX_M) field[nx][ny]++; 
	}
}

int main(void)
{
	int ans = 0, color = 0;
	while (scanf("%d,%d,%d", &x, &y, &size) != EOF) {
		if (x == 0 && y == 0 && size == 0) break;
		switch (size) {
			case 1: Mini(); break;
			case 2: Midole(); break;
			case 3: Big(); break;
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (field[i][j] == 0) ans++;
			else if (color < field[i][j]) color = field[i][j];
		}
	}
	cout << ans << endl << color << endl;

	return 0;
}