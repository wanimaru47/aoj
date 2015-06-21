#include <iostream>
#include <queue>
#define MAX 10
#define LIM 12
using namespace std;

struct F {
     int field[MAX][MAX];
     int lim;
};

int LX[12] = {-2, -1, 1, 2, 0, 0, 0, 0, -1, -1, 1, 1};
int LY[12] = {0, 0, 0, 0, -2, -1, 1, 2, -1, 1, -1, 1};
int MX[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
int MY[8] = {0, 0, -1, 1, -1, 1, -1, 1};
int SX[4] = {-1, 1, 0 ,0};
int SY[4] = {0, 0, -1, 1};
     
typedef queue<F> Q;
typedef pair<int,int> P;
typedef map<P, int> M;

F f;
int N;
int tmp1[MAX][MAX], tmp2[MAX][MAX];

bool sreach(int tmp[MAX][MAX]) {
     for (int i = 0; i < MAX; i++)
	  for (int j = 0; j < MAX; j++)
	       if (tmp[i][j] > 0) return true;

     return false;
}

bool sl(int tmp[MAX][MAX], P p) {
     int x = p.first, y = p.second;
     for (int i = 0; i < sizeof(LX); i++) {
	  int nx = x + LX[i], ny = y + LY[i];
	  if (tmp[nx][ny] < 1) return false;
     }

     return true;
}

bool sm(int tmp[MAX][MAX], P p) {
     int x = p.first, y = p.second;
     for (int i = 0; i < sizeof(MX); i++) {
	  int nx = x + MX[i], ny = y + MY[i];
	  if (tmp[nx][ny] < 1) return false;
     }

     return true;
}

bool ss(int tmp[MAX][MAX], P p) {
     int x = p.first, y = p.second;
     for (int i = 0; i < sizeof(SX); i++) {
	  int nx = x + SX[i], ny = y + SY[i];
	  if (tmp[nx][ny] < 1) return false;
     }

     return true;
}

void dfs() {
     Q q;
     q.push(f);

}

int main()
{
     cin >> N;
     for (int i = 0; i < MAX; i++)
	  for (int j = 0; j < MAX; j++)
	       cin >> f.field[i][j];
     
     f.lim = 0;    

     return 0;
}
