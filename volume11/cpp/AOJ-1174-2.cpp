#include <iostream>
#include <queue>
#include <stack>
#define MAX 8
#define INF 1000000
using namespace std;

typedef pair<int,int> P;

int dx[4] = {1,0,-1,0}, dy[4] = {0,1,0,-1};
int h, w, color, res = 0;

struct F {
     int field[8][8];
     int times;
};

queue<F> tmp;

void bfs (F f, int colors) {
     int d[MAX][MAX];
     
     if (f.times == 5) colors = color;
     int count = 1;
     f.field[0][0] = 0;
     queue<P> que;
     que.push(P(0,0));

     for (int i = 0; i < MAX; i++)
	  for (int j = 0; j < MAX; j++)
	       d[i][j] = INF;
     d[0][0] = 0;
     bool flag = false;

     while (que.size()) {
	  P p = que.front(); que.pop();
	  for (int i = 0; i < 4; i++) {
	       int nx = p.first + dx[i], ny = p.second + dy[i];

	       if (0 <= nx && nx < w && 0 <= ny && ny < h && d[nx][ny] == INF) {	    
		    if (f.field[nx][ny] == 0 || f.field[nx][ny] == colors) {
			 if (f.field[nx][ny] != 0) flag = true;
			 f.field[nx][ny] = 0;
			 d[nx][ny] = 0;
			 count++;

			 que.push(P(nx,ny));
		    }
	       }
	  }
     }
     if (count > res) res = count;
     /*
     if (count > res) {
	  res = count;
	  for (int i = 0; i < h; i++) {
	       for (int j = 0; j < w; j++) {
		    cout << f.field[i][j] << " ";
	       }cout << endl;
	  }
	  cout << endl;
     }
     */
     if ((flag && f.times < 5) || f.times == 0) tmp.push(f);
}

void solve() {
     while (tmp.size()) {
	  F f = tmp.front(); tmp.pop();
	  f.times++;
	  for (int i = 1; i < 7; i++) {
	       bfs(f, i);
	       /*
	       for (int i = 0; i < h; i++) {
		    for (int j = 0; j < w; j++) {
			 cout << f.field[i][j] << " ";
		    }
		    cout << endl;
	       }
	       cout << endl;
	       */
	  }
     }
}

int main ()
{    
     while (cin >> h >> w >> color, h) {
	  F f;
	  res = 0;
	  for (int i = 0; i < h; i++)
	       for (int j = 0; j < w; j++)
		    cin >> f.field[i][j];

	  f.times = 0;
	  bfs(f, f.field[0][0]);
	  solve();
	  
	  cout << res << endl;
     }

     return 0;
}
