#include <iostream>
#include <queue>
#define MAX_N 8
#define MAX_M 8
#define MAX_C 6
#define INF 1000000

using namespace std;

int N, M, C;
int field[MAX_N][MAX_M];
int ans = 1;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int nd, flag = 0;
int d[MAX_N][MAX_M];

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
	void seeGrh();
	int outSum();
};

int Graphs::intialize(int x[MAX_N][MAX_M])
{
	node = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			g[i][j] = field[i][j];
		}
	}

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
	if (node == 5 && ans < sum) ans = sum;

	cout << "node " << node << endl;

	return node;
}

void Graphs::outgrh()
{
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < M; j++)  field[i][j] = g[i][j];
}

void Graphs::seeGrh()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << g[i][j] << " ";
		}
		puts("");
	}
}

void see()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << field[i][j] << " ";
		}
		puts("");
	}
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

void seeINF()
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (d[i][j] == INF) {
				printf(" INF");
			}else {
				printf("%4d ", d[i][j]);
			}
		}
		puts("");
	}
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

			//if (0 <= nx && nx < N && 0 <= ny && ny < M && (field[nx][ny] == 7 || field[nx][ny] == color) && d[nx][ny] != 0) {
			if (0 <= nx && nx < N && 0 <= ny && ny < M ) {
				if (field[nx][ny] == 7 || field[nx][ny] == color) {
					if (d[nx][ny] == INF) {
						if (field[nx][ny] == color) flag = 1;
						qg.push(P(nx, ny));
						d[nx][ny] = 0;
						field[nx][ny] = 7;
					}
				}
			}
		}
	}
}

int Graphs::outNode()
{
	return node;
}

int Graphs::outSum()
{
	return sum;
}

void solve()
{
	int color;
	color = field[0][0];
	field[0][0] = 7;
	bfs(color);									//init
	grh.intialize(field);
	nd = grh.outNode();
	que.push(grh);
	for (int i = 0; nd < 4; i++) {				//0~3
		/*
		flag = 1;
		while (flag) {
			grh = que.front();
			nd = grh.outNode();
			if (nd == i) {
				flag = 0;
			}else {
				que.pop();
			}
		}
		*/
		cout << "que size before " << que.size() << endl;
		for (int j = 0; j < MAX_C+1; j++) {
			grh = que.front();
			grh.outgrh();
			if (j == C) continue;
			flag = 0;
			bfs(j);
			if (flag == 1) {
				grh.ingrh(field);
				see();
				puts("");
				que.push(grh);
			}
		}
		que.pop();
		if (que.size()) {
			grh = que.front();
			nd = grh.outNode();
		}else break;
		

		cout << "que size after " << que.size() << endl;
	}
	/*
	flag = 1;
	while (flag) {
		grh = que.front();
		nd = grh.outNode();
		if (nd != 4) que.pop();
		else flag = 0;
	}
	*/
	while (que.size()) {
		grh = que.front();
		que.pop();
		grh.outgrh();
		bfs(C);
		see();
		puts("");
		grh.ingrh(field);
	}
}

int main(void)
{
	/*
	while (cin >> N >> M >> C) {
		*/
		//if (N == 0) break;
		//ans = 1;
		cin >> N >> M >> C;
		int sum;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) { 
				cin >> field[i][j];
			}
		}
		int color = field[0][0];
		field[0][0] = 7;
		bfs(color);
		see();
		grh.ingrh(field);
		grh.outSum();
		
/*
		solve();
		/*
		int color;
		color = field[0][0];
		field[0][0] = 7;
		bfs(color); //init
		bfs(6);		//0
		bfs(3);		//1
		bfs(4);		//2
		bfs(2);		//3
		bfs(C);		//4

		see();
		
		cout << "                                          " << ans << endl;
	}
	*/

	return 0;
}

/*
3 5 5
1 6 3 2 5
2 5 4 6 1
1 2 4 1 5

3 5 5
6 6 6 6 6
6 6 6 6 6
6 6 6 6 6

3 5 5
1 7 7 2 5
2 5 4 6 1
1 7 4 1 5

5 5 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
1 2 3 4 5
*/