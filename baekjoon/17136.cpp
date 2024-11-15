#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int n = 10;

int ret = INF;
int a[12][12];
map<int, int> paper;

bool check(int y, int x, int can) {
	if (y + can > n || x + can > n) return false;
	for (int i = y; i < y+can; i++) {
		for (int j = x; j < x +can; j++) {
			if (a[i][j] == 0) return false;
		}
	}
	return true;
}
void draw(int y, int x, int can, int value) {
	for (int i = y; i < y+can; i++) {
		for (int j = x; j < x+can; j++) {
			a[i][j] = value;
		}
	}

}

void dfs(int y, int x, int cnt) {
	if (cnt >= ret)
		return;

	if (x == n) {
		dfs(y + 1, 0, cnt); return;
	}
	if (y == n) {
		ret = min(ret, cnt);
		return;
	}

	if (a[y][x] == 0) {
		dfs(y, x + 1, cnt); return;
	}

	for (int size = 5; size >= 1; size--) {
		// ���� �ټ��� �ٽ�����
		if (paper[size] == 5) continue;
		if (!check(y, x, size)) continue;
		
		//���� ����ؼ� 0���� ����
		paper[size]++;
		draw(y, x, size, 0);

		dfs(y, x, cnt + 1);

		// ����
		draw(y, x, size, 1);
		paper[size]--;
	}


	
}
int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	dfs(0, 0, 0);


	cout << (ret == INF ? -1 : ret);

	return 0;
}