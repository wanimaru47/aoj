#include <iostream>
#include <queue>
#define MAX_N 8
#define MAX_M 8
#define MAX_C 6
#define INF 1000000
using namespace std;

int N, M, C, ans = 1, nd, flag = 0;
int field[MAX_N][MAX_M], d[MAX_N][MAX_M], dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

class Graphs
{
public:
	int g[MAX_N][MAX_M];
	int sum;
	int node;
	int intialize(int x[MAX_N][MAX_M]);
	int ingrh(int x[MAX_N][MAX_M]);
	void outgrh();
	int outNode();
};

int Graphs::intialize(int x[MAX_N][MAX_M])
{
	node = 0;
	sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			g[i][j] = field[i][j];
			if (g[i][j] == 7) sum++;
		}
	}
	if (ans < sum) ans = sum;

	return node;
}

int Graphs::ingrh(int x[MAX_N][MAX_M])
{
	sum = 0;
	node++;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			g[i][j] = x[i][j];
			if (g[i][j] == 7) {
				sum++;
			}
		}
	}
	if (ans < sum) ans = sum;

	return node;
}

void Graphs::outgrh()
{
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)  field[i][j] = g[i][j];
}

typedef Graphs G;
typedef pair<int, int> P;

G grh;
queue<G> que;

void initINF(){
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			d[i][j] = INF;
		}
	}
	d[0][0] = 0; 
}

void bfs(int color) {
	queue<P> qg;
	qg.push(P(0, 0));
	initINF();
	while(qg.size()) {
		P p = qg.front();
		qg.pop();
		for (int i = 0; i < 4; i++) {
			int nx = p.first + dx[i], ny = p.second + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M && (field[nx][ny] == 7 || field[nx][ny] == color) && d[nx][ny] == INF) {
				if (field[nx][ny] == color) flag = 1;
				qg.push(P(nx, ny));
				d[nx][ny] = 0;
				field[nx][ny] = 7;
			}
		}
	}
}

int Graphs::outNode() { return node; }

void solve()
{
	int color;
	color = field[0][0];
	field[0][0] = 7;
	bfs(color);	
	grh.intialize(field);
	nd = grh.outNode();
	que.push(grh);
	for (int i = 0; nd < 4; i++) {
		for (int j = 0; j < MAX_C+1; j++) {
			grh = que.front();
			grh.outgrh();
			flag = 0;
			bfs(j);
			if (flag == 1) {
				grh.ingrh(field);
				que.push(grh);
			}
		}
		que.pop();
		if (que.size()) {
			grh = que.front();
			nd = grh.outNode();
		}else break;
	}
	while (que.size()) {
		grh = que.front();
		que.pop();
		grh.outgrh();
		bfs(C);
		grh.ingrh(field);
	}
}

int main(void)
{
	while (cin >> N >> M >> C) {
		if (N == 0) break;
		ans = 1;
		for (int i = 0; i < N; i++) 
			for (int j = 0; j < M; j++) cin >> field[i][j];
		solve();
		cout << ans << endl;
	}

	return 0;
}
