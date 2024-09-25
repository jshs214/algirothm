#include <bits/stdc++.h>
using namespace std;

int ret = -INT_MAX;
int n, m;

int a[5][5];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}

	//����� ��
	for (int i = 0; i <= (1 << n*m); i++) {
		int sum = 0;

		// width check
		for (int y = 0; y < n; y++) {
			int cur = 0;
			for (int x = 0; x < m; x++) {
				int idx = y * m + x;
				
				if ( (i & (1 << idx) )== 0) {
					cur = cur * 10 + a[y][x];
				}
				else {
					cur = 0;
					//sum += cur;
				}
				//logic
			}
			sum += cur;
		}
		// height check
		for (int x = 0; x < m; x++) {
			int cur = 0;
			for (int y = 0; y < n; y++) {
				int idx = x * n + y;

				if ((i & (1 << idx)) == 1) {
					cur = cur * 10 + a[y][x];
				}
				else {
					cur = 0;
					//sum += cur;
				}
			}
			sum += cur;
		}

		ret = max(ret, sum);
	}

	cout << ret;

	return 0;
}