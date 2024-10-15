#include <bits/stdc++.h>
using namespace std;

int n, m, t;

int ret = 0;

vector<vector<int>> circleBoard;
int visited[55][55];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

// ���� index ���
void dfs(int y, int x, int value, bool &flag) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		// ���δ� �����̹Ƿ� ��ⷯ ����
		int nx = x +dx[i];

		if (nx < 0) nx = m-1;
		else if(nx >= m) nx =0

		if (ny < 0 ||  ny >= n ) continue;
		if (circleBoard[ny][nx] == 0) continue;
		if (visited[ny][nx]) continue;

		if (value == circleBoard[ny][nx]) {
			visited[y][x] = 1;
			visited[ny][nx] = 1;
			flag = true;
			dfs(ny, nx, value, flag);
		}
	}

}

bool Remove() {
	bool find = false;
	memset(visited, 0, sizeof(visited));

	// ���� idx visitedó��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && circleBoard[i][j] !=0) {
				dfs(i, j, circleBoard[i][j], find);
			}
		}
	}
	
	// ���� ���� ����
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visited[i][j] == 1)
				circleBoard[i][j] = 0;
		}
	}

	return find;
}
// �ð� rbegin, �ݽð� begin
void solve(int x, int d, int k) {
	// step 1 
	// ��ȣ�� xi�� ����� ������ di�������� kiĭ ȸ����Ų��.
	// di�� 0�� ���� �ð� ����, 1�� ���� �ݽð� �����̴�.
	for (int i = 0; i < n; i++) {
		int idx = i + 1;
		if (idx % x == 0) {
			if (d == 0) {
				rotate(circleBoard[i].rbegin(), circleBoard[i].rbegin() + k, circleBoard[i].rend());
			}
			else if (d == 1) {
				rotate(circleBoard[i].begin(), circleBoard[i].begin() + k, circleBoard[i].end());
			}
		}
	}

	// step 2
	// �������� ����, ������ ��� ����
	if ( !Remove()) {
		int cnt = 0;
		int sum = 0;
		// ��� ���ϱ�
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (circleBoard[i][j] != 0) {
					cnt++;
					sum += circleBoard[i][j];
				}
			}
		}
		
		if (cnt == 0) return;

		double average = (double)sum / cnt; 

		// ��հ� ���Ͽ� �� ����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (circleBoard[i][j] != 0) {
					if (circleBoard[i][j] < average) {
						circleBoard[i][j]++;
					}
					else if (circleBoard[i][j] > average) {
						circleBoard[i][j]--;
					}
				}
			}
		}

	}
	
}

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < m; j++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		circleBoard.push_back(v);
	}


	for (int i = 0; i < t; i++) {
		int x, d, k;
		cin >> x >> d >> k;
		solve(x, d, k);
	}

	// counting
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (circleBoard[i][j] != 0)
				ret += circleBoard[i][j];
		}
	}

	cout << ret;

	return 0;
}