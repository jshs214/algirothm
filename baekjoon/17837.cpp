#include <bits/stdc++.h>
using namespace std;

struct Point {
	int y;
	int x;
	int dir;
};

// ü����
// 0 : ���
// 1 : ������
// 2 : �Ķ���
int a[14][14];

vector<int> v[14][14];	// ü���� ���� �� ����
vector<Point> status;	// ���� ����
int n, k;

int dy[] = { 0, 0, -1, 1 };
int dx[] = { 1, -1, 0, 0 };

void dirChange(int& dir) {
	if (dir == 0) dir = 1;
	else if (dir == 1) dir = 0;
	else if (dir == 2) dir = 3;
	else if (dir == 3) dir = 2;
}

bool check(int y, int x) {
	if (y < 0 || y >= n || x < 0 || x >= n) return false;
	return true;
}
bool gameclear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (v[i][j].size() >= 4)
				return true;
		}
	}
	return false;
}

void move(int y, int x, int dir, int idx) {
	int ny = y + dy[dir];
	int nx = x + dx[dir];

	//��踦 �Ѿ�ų� �Ķ����̸�
	if (!check(ny, nx) || a[ny][nx] == 2) {
		dirChange(status[idx].dir);
		ny = y + dy[status[idx].dir];
		nx = x + dx[status[idx].dir];

		// ��ȯ �Ŀ��� �Ķ����̸� return
		if (!check(ny, nx) || a[ny][nx] == 2) return;
	}


	vector<int>& hereV = v[y][x];
	vector<int>& nextV = v[ny][nx];

	// ���� �� find
	auto pos = find(hereV.begin(), hereV.end(), idx);

	// �������̸� vector reverse 
	if (a[ny][nx] == 1)
		reverse(pos, hereV.end());
	

	// ���� ĭ���� �̵�
	for (auto it = pos; it != hereV.end(); it++) {
		nextV.push_back(*it);
		status[*it].y = ny;
		status[*it].x = nx;

	}
	hereV.erase(pos, hereV.end());

	return;
}

bool simul() {
	// �� ������ŭ
	for (int i = 0; i < status.size(); i++) {
		int y = status[i].y;
		int x = status[i].x;
		int dir = status[i].dir;

		move(y, x, dir, i);
		if (gameclear())
			return true;
	}
	return false;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int y, x, dir;
		cin >> y >> x >> dir;
		y--; x--; dir--;

		// �� ������� ����
		v[y][x].push_back(i);
		status.push_back({ y,x,dir });
	}

	bool flag = false;
	int cnt = 0;
	while (cnt <= 1000) {
		cnt++;
		if (simul()) {
			flag = true;
			break;
		}
	}

	cout << (flag ? cnt : -1);

	return 0;
}